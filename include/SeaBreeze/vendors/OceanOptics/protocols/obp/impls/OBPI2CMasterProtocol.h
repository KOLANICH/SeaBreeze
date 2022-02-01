/***************************************************/ /**
 * @file    OBPI2CMasterProtocol.h
 * @date    May 2017
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

#pragma once

#include <SeaBreeze/common/buses/Bus.h>
#include <SeaBreeze/common/exceptions/ProtocolException.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/interfaces/I2CMasterProtocolInterface.h>

namespace seabreeze {
namespace oceanBinaryProtocol {
class OBPI2CMasterProtocol: public I2CMasterProtocolInterface {
  public:
	OBPI2CMasterProtocol();

	virtual ~OBPI2CMasterProtocol();

	/* Inherited from OBPI2CMasterProtocolInterface */

	virtual unsigned char i2cMasterGetNumberOfBuses(const Bus &bus) throw(ProtocolException);

	virtual std::vector<unsigned char> i2cMasterReadBus(const Bus &bus, unsigned char busIndex, unsigned char slaveAddress, unsigned short numberOfBytes) throw(ProtocolException);

	virtual unsigned short i2cMasterWriteBus(const Bus &bus, unsigned char busIndex, unsigned char slaveAddress, const std::vector<unsigned char> writeData) throw(ProtocolException);
};
}// namespace oceanBinaryProtocol
}// namespace seabreeze

/* OBPI2CMASTERPROTOCOL_H */
