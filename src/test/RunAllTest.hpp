/**
 * @file RunAllTest.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "BubbleTest.hpp"
#include "InsertTest.hpp"
#include "MergeSortTest.hpp"
#include "SelectionTest.hpp"

#include <functional>

namespace test {

static const std::vector<std::function<void()>> AllTest {
    BubbleSortTest,
    InsertSortTest,
    SelectionSortTest,
    MergeSortTest,
};

void run_all_test() {
    for (auto&& func : AllTest) {
        func();
    }
}

} // namespace test