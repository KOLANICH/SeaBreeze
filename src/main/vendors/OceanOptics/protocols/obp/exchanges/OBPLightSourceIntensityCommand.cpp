/***************************************************/ /**
 * @file    OBPLightSourceIntensityCommand.cpp
 * @date    April 2013
 * @author  Ocean Optics, Inc.
 *
 * LICENSE:
 *
 * SeaBreeze Copyright (C) 2014, Ocean Optics Inc
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *******************************************************/

#include <SeaBreeze/common/globals.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/obp/constants/OBPMessageTypes.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/obp/exchanges/OBPLightSourceIntensityCommand.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/obp/hints/OBPControlHint.h>

using namespace seabreeze;
using namespace seabreeze::oceanBinaryProtocol;

OBPLightSourceIntensityCommand::OBPLightSourceIntensityCommand() {
	this->hints->push_back(new OBPControlHint());

	this->messageType = OBPMessageTypes::OBP_SET_LIGHT_SOURCE_INTENSITY;

	this->payload.resize(2 + sizeof(float));
}

OBPLightSourceIntensityCommand::~OBPLightSourceIntensityCommand() {
}

void OBPLightSourceIntensityCommand::setLightSourceIntensity(int moduleIndex,
	int source, float intensity) {

	unsigned int i;
	uint8_t *cptr = (uint8_t *) &intensity;

	this->payload[0] = (uint8_t) moduleIndex;
	this->payload[1] = (uint8_t) source;
	for(i = 0; i < sizeof(float); i++) {
		payload[i + 2] = cptr[i];
	}
}
