/**
 * @file QuickSortTest.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../algorithm/QuickSort.hpp"
#include "../utility/Print.hpp"
#include "../utility/TestTool.hpp"

#include <iostream>
#include <list>
#include <vector>

namespace test {

void QuickSortTest() {
    title_info("QuickSort");
    // std::vector
    {
        std::vector<int> vec { 9, 2, 7, 5, 3, 4, 1, 0 };

        std::cout << "vec raw => ";
        Println(vec.begin(), vec.end());

        QuickSort(vec);

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

        QuickSort(list.begin(), list.end());

        std::cout << "list ascending => ";
        Println(list.begin(), list.end());

        std::cout << std::endl;
    }
    end_info("QuickSort");
}

} // namespace test