/**
 * @file Selection.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "../algorithm/SelectionSort.hpp"
#include "../utility/Print.hpp"
#include "../utility/TestTool.hpp"

#include <iostream>
#include <list>
#include <vector>

namespace test {

void SelectionSortTest() {
    title_info("SelectionSort");

    // std::vector
    {
        std::vector<int> vec { 9, 2, 7, 5, 3, 4, 1, 0 };

        std::cout << "vec raw => ";
        Println(vec.begin(), vec.end());

        SelectionSort(vec);

        std::cout << "vec ascending => ";
        Println(vec.begin(), vec.end());

        std::cout << std::endl;
    }
    // std::list
    {
        std::list<int> list { 9, 2, 7, 5, 3, 4, 1, 0 };

        std::cout << "list raw => ";
        Println(list.begin(), list.end());

        SelectionSort(list.begin(), list.end());

        std::cout << "list ascending => ";
        Println(list.begin(), list.end());

        std::cout << std::endl;
    }

    end_info("SelectionSort");
}

} // namespace test