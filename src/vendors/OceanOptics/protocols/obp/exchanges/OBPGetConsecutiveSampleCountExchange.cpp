/***************************************************/ /**
 * @file    OBPGetConsecutiveSampleCountExchange.cpp
 * @date    February 2017
 * @author  Ocean Optics, Inc.
 *
 * LICENSE:
 *
 * SeaBreeze Copyright (C) 2017, Ocean Optics Inc
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

#include "common/globals.h"
#include "vendors/OceanOptics/protocols/obp/constants/OBPMessageTypes.h"
#include "vendors/OceanOptics/protocols/obp/exchanges/OBPGetConsecutiveSampleCountExchange.h"
#include "vendors/OceanOptics/protocols/obp/hints/OBPControlHint.h"
#include <vector>

using namespace seabreeze;
using namespace seabreeze::oceanBinaryProtocol;
using namespace std;

OBPGetConsecutiveSampleCountExchange::OBPGetConsecutiveSampleCountExchange() {
	this->hints->push_back(new OBPControlHint());
	this->messageType = OBPMessageTypes::OBP_GET_BACK_TO_BACK_SAMPLE_COUNT;
	this->payload.resize(sizeof(unsigned int));
}

OBPGetConsecutiveSampleCountExchange::~OBPGetConsecutiveSampleCountExchange() {
}

unsigned int OBPGetConsecutiveSampleCountExchange::queryConsecutiveSampleCount(
	TransferHelper *helper) throw(ProtocolException) {

	unsigned int consecutiveSampleCount;
	vector<byte> *result;

	result = this->queryDevice(helper);
	if(NULL == result || result->size() < sizeof(unsigned int)) {
		throw ProtocolException("Got a short read when querying consecutive sample count.");
	}

	// cast of a byte pointer(data) to an unsigned integer pointer which is dereferenced
	consecutiveSampleCount = *(unsigned int *) ((*result).data());

	delete result;

	return consecutiveSampleCount;
}
