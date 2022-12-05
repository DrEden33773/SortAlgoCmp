/**
 * @file Bubble.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "../algorithm/BubbleSort.hpp"
#include "../utility/Print.hpp"
#include "../utility/TestTool.hpp"

#include <iostream>
#include <list>
#include <vector>

namespace test {

void BubbleSortTest() {
    title_info("BubbleSort");

    // std::vector
    {
        std::vector<int> vec { 9, 2, 7, 5, 3, 4, 1, 0 };

        std::cout << "vec raw => ";
        Println(vec.begin(), vec.end());

        BubbleSort(vec);

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

        BubbleSort(list.begin(), list.end());

        std::cout << "list ascending => ";
        Println(list.begin(), list.end());

        std::cout << std::endl;
    }

    end_info("BubbleSort");
}

} // namespace test