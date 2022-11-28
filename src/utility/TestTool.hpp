/**
 * @file TestTool.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include <iostream>

void title_info(const char* name) {
    std::cout << "========== Test of `"
              << name
              << "` is started ========== " << std::endl;
    std::cout << std::endl;
}

void end_info(const char* name) {
    std::cout << "========== Test of `"
              << name
              << "` is ended ========== " << std::endl;
    std::cout << std::endl;
}