/*
 * SPDX-FileCopyrightText: 2024 M5Stack Technology CO LTD
 *
 * SPDX-License-Identifier: MIT
 */
/*!
  @file M5Utility.hpp
  @brief Main header of M5Utility

  @mainpage M5Utility
  This library is a collection of common functionality for other M5Libraries and products.
*/
#ifndef M5_UTILITY_HPP
#define M5_UTILITY_HPP

#include "m5_utility/stl/expected.hpp"
#include "m5_utility/stl/extension.hpp"
#include "m5_utility/stl/optional.hpp"
#include "m5_utility/stl/endianness.hpp"

#include "m5_utility/log/library_log.hpp"

#include "m5_utility/container/circular_buffer.hpp"

#include "m5_utility/bit_segment.hpp"
#include "m5_utility/compatibility_feature.hpp"
#include "m5_utility/murmurhash3.hpp"
#include "m5_utility/types.hpp"
#include "m5_utility/crc.hpp"
#include "m5_utility/string.hpp"
#include "m5_utility/conversion.hpp"
#include "m5_utility/math.hpp"
#include "m5_utility/misc.hpp"

/*!
  @namespace m5
  @brief Top level namespace of M5
*/
namespace m5 {
/*!
  @namespace utility
  @brief For utilities
*/
namespace utility {
}

/*!
  @namespace stl
  @brief STL compatibility functions and classes
 */
namespace stl {
}

/*!
  @namespace container
  @brief Container classes
 */
namespace container {
}

}  // namespace m5

#endif
