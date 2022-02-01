/***************************************************/ /**
 * @file    Maya2000ProUSB.cpp
 * @date    February 2009
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
#include <SeaBreeze/vendors/OceanOptics/buses/usb/Maya2000ProUSB.h>
#include <SeaBreeze/vendors/OceanOptics/buses/usb/OOIUSBControlTransferHelper.h>
#include <SeaBreeze/vendors/OceanOptics/buses/usb/OOIUSBEndpointMaps.h>
#include <SeaBreeze/vendors/OceanOptics/buses/usb/OOIUSBProductID.h>
#include <SeaBreeze/vendors/OceanOptics/buses/usb/OOIUSBSpectrumTransferHelper.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/ooi/hints/ControlHint.h>
#include <SeaBreeze/vendors/OceanOptics/protocols/ooi/hints/SpectrumHint.h>

using namespace seabreeze;
using namespace ooiProtocol;

Maya2000ProUSB::Maya2000ProUSB() {
	this->productID = MAYA2000PRO_USB_PID;
}

Maya2000ProUSB::~Maya2000ProUSB() {
}

bool Maya2000ProUSB::open() {
	bool retval = false;

	retval = OOIUSBInterface::open();

	if(true == retval) {
		ControlHint *controlHint = new ControlHint();
		SpectrumHint *spectrumHint = new SpectrumHint();
		OOIUSBFPGAEndpointMap endpointMap;

		clearHelpers();

		addHelper(spectrumHint, new OOIUSBSpectrumTransferHelper((this->usb), endpointMap));

		addHelper(controlHint, new OOIUSBControlTransferHelper((this->usb), endpointMap));

		this->usb->clearStall(endpointMap.getLowSpeedInEP());
		this->usb->clearStall(endpointMap.getHighSpeedInEP());
		this->usb->clearStall(endpointMap.getLowSpeedOutEP());
	}

	return retval;
}
