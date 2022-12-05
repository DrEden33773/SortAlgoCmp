/**
 * @file ShellSortTest.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "../algorithm/ShellSort.hpp"
#include "../utility/Print.hpp"
#include "../utility/TestTool.hpp"

#include <iostream>
#include <list>
#include <vector>

namespace test {

void ShellSortTest() {
    title_info("ShellSort");

    // std::vector
    {
        std::vector<int> vec { 9, 2, 7, 5, 3, 4, 1, 0 };

        std::cout << "vec raw => ";
        Println(vec.begin(), vec.end());

        ShellSort(vec);

        std::cout << "vec ascending => ";
        Println(vec.begin(), vec.end());

        std::cout << std::endl;
    }

    end_info("ShellSort");
}

} // namespace test
