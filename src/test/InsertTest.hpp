/**
 * @file Insert.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "../algorithm/InsertSort.hpp"
#include "../utility/Print.hpp"
#include "../utility/TestTool.hpp"

#include <iostream>
#include <list>
#include <vector>

namespace test {

void InsertSortTest() {
    title_info("InsertSort");

    std::list<int> test { 9, 2, 7, 5, 3, 4, 1, 0 };
    std::cout << "raw => ";
    Println(test.begin(), test.end());

    InsertSort(test.begin(), test.end());

    std::cout << "ascending => ";
    Println(test.begin(), test.end());

    std::cout << std::endl;

    end_info("InsertSort");
}

} // namespace test
