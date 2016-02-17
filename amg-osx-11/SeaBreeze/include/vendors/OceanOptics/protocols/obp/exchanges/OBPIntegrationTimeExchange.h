/***************************************************/ /**
 * @file    OBPIntegrationTimeExchange.h
 * @date    January 2011
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

#ifndef OBPINTEGRATIONTIMEEXCHANGE_H
#define OBPINTEGRATIONTIMEEXCHANGE_H

#include "vendors/OceanOptics/protocols/obp/exchanges/OBPCommand.h"
#include "vendors/OceanOptics/protocols/obp/exchanges/OBPMessage.h"

namespace seabreeze {
namespace oceanBinaryProtocol {
class OBPIntegrationTimeExchange: public OBPCommand {
  public:
	OBPIntegrationTimeExchange(unsigned long integrationTimeBase_usec);
	virtual ~OBPIntegrationTimeExchange();
	void setIntegrationTimeMicros(unsigned long integrationTime_usec);

  private:
	unsigned long integrationTimeBase_usec;
	unsigned long integrationTime_usec;
};
}// namespace oceanBinaryProtocol
}// namespace seabreeze

#endif /* OBPINTEGRATIONTIMEEXCHANGE_H */