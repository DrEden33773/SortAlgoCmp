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

    // std::vector
    {
        std::vector<int> vec { 9, 2, 7, 5, 3, 4, 1, 0 };

        std::cout << "vec raw => ";
        Println(vec.begin(), vec.end());

        InsertSort(vec);

        std::cout << "vec ascending => ";
        Println(vec.begin(), vec.end());

        std::cout << std::endl;
    }
    // std::list
    {
        std::list<int> list { 9, 2, 7, 5, 3, 4, 1, 0 };
        // std::list<int> list {};

        std::cout << "list raw => ";
        Println(list.begin(), list.end());

        InsertSort(list.begin(), list.end());

        std::cout << "list ascending => ";
        Println(list.begin(), list.end());

        std::cout << std::endl;
    }

    end_info("InsertSort");
}

} // namespace test
