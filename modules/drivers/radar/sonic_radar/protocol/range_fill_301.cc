/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/drivers/radar/sonic_radar/protocol/range_fill_301.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace drivers {
namespace sonic_radar {

using apollo::drivers::Ultrasonic;

const uint32_t RangeFill301::ID = 0x301;

RangeFill301::RangeFill301() {}
RangeFill301::~RangeFill301() {}

uint32_t RangeFill301::GetPeriod() const {
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

/**
  * @brief parse the data
  * @param data a pointer to the data to be updated
  * @param length the length of the data
  * @param ultrasonic message to be filled
  */
void RangeFill301::Parse(const std::uint8_t* bytes, int32_t length, Ultrasonic* ultrasonic) const {
  ultrasonic->set_ranges(0, bytes[1]);
  ultrasonic->set_ranges(1, bytes[2]);
  ultrasonic->set_ranges(2, bytes[3]);
  ultrasonic->set_ranges(3, bytes[4]);
}

}  // namespace sonic_radar
}  // namespace drivers
}  // namespace apollo
