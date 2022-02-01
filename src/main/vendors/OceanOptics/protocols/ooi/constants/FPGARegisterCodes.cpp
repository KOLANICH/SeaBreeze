/***************************************************/ /**
 * @file    FPGARegisterCodes.cpp
 * @date    October 2012
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
#include <SeaBreeze/vendors/OceanOptics/protocols/ooi/constants/FPGARegisterCodes.h>

using namespace seabreeze::ooiProtocol::FPGARegisterCodes;

const uint8_t Base::FIRMWARE_VERSION = 0x04;
const uint8_t Base::SINGLE_STROBE_HIGH_CLOCK_TRANSITION_DELAY_COUNT = 0x38;
const uint8_t Base::SINGLE_STROBE_LOW_CLOCK_TRANSITION_DELAY_COUNT = 0x3c;
const uint8_t Base::LAMP_ENABLE = 0x40;
const uint8_t Base::GPIO_MUX_REGISTER = 0x48;
const uint8_t Base::GPIO_OUTPUT_ENABLE = 0x50;
const uint8_t Base::GPIO_DATA_REGISTER = 0x54;
const uint8_t Base::OFFSET_VALUE = 0x5c;
const uint8_t Base::OFFSET_CONTROL = 0x60;
const uint8_t Base::MAXIMUM_SATURATION_LEVEL = 0x68;

const uint8_t V1::CONTINUOUS_STROBE_TIMER_INTERVAL_DIVISOR = 0x08;
const uint8_t V1::CONTINUOUS_STROBE_BASE_CLOCK_DIVISOR = 0x0c;

const uint8_t V3::CONTINUOUS_STROBE_TIMER_MSB = 0x08;
const uint8_t V3::CONTINUOUS_STROBE_TIMER_LSB = 0x0c;
