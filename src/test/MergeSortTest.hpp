/**
 * @file MergeSortTest.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "../algorithm/MergeSort.hpp"
#include "../utility/Print.hpp"
#include "../utility/TestTool.hpp"

#include <iostream>
#include <list>
#include <vector>

namespace test {

void MergeSortTest() {
    title_info("MergeSort");
    // std::vector
    {
        std::vector<int> vec { 9, 2, 7, 5, 3, 4, 1, 0 };

        std::cout << "vec raw => ";
        Println(vec.begin(), vec.end());

        MergeSort(vec);

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

        MergeSort(list.begin(), list.end());

        std::cout << "list ascending => ";
        Println(list.begin(), list.end());

        std::cout << std::endl;
    }
    end_info("MergeSort");
}

} // namespace test