/**
 * @file OrderAssertion.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-12-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <concepts>
#include <stdexcept>
#include <vector>

namespace Utility {

template <typename T>
requires std::totally_ordered<T>
bool if_ascending_order(const std::vector<T>& vec) {
    if (vec.empty() || vec.size() == 1) {
        return true;
    }
    const size_t& size = vec.size();
    for (size_t idx = 0; idx < size - 1; ++idx) {
        if (vec.at(idx) > vec.at(idx + 1)) {
            return false;
        }
    }
    return true;
}

template <typename T>
requires std::totally_ordered<T>
void assert_if_ascending_order(const std::vector<T>& vec) {
    if (!if_ascending_order(vec)) {
        throw std::runtime_error("Input Vec is not ascending-ordered!");
    }
}

} // namespace Utility