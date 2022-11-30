/**
 * @file RadixSortTest.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../algorithm/RadixSort.hpp"
#include "../utility/Print.hpp"
#include "../utility/TestTool.hpp"

#include <iostream>
#include <vector>

namespace test {

void RadixSortTest() {
    title_info("RadixSort");
    // std::vector
    {
        std::vector<size_t> vec { 900, 22, 71, 565, 3134, 41, 19, 0 };

        std::cout << "vec raw => ";
        Println(vec.begin(), vec.end());

        RadixSortHelper<size_t>::RadixSort(vec);

        std::cout << "vec ascending => ";
        Println(vec.begin(), vec.end());

        std::cout << std::endl;
    }
    end_info("RadixSort");
}

} // namespace test