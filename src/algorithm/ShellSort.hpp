/**
 * @file ShellSort.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-12-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <algorithm>
#include <bits/iterator_concepts.h>
#include <concepts>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

template <class T>
requires std::equality_comparable<T>
void PartialInsertSort(std::vector<T>& vec, size_t interval) {
    if (vec.empty() || vec.size() <= interval) {
        return;
    }
}

template <class T>
requires std::equality_comparable<T>
void ShellSort(std::vector<T>& vec) {
    if (vec.empty()) {
        return;
    }
    PartialInsertSort(vec, 5);
    PartialInsertSort(vec, 3);
    PartialInsertSort(vec, 1);
}