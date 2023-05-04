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

/**
 * @brief InsertSort_with_gap
 *
 * @tparam T
 * @param vec
 * @param gap
 * @return requires
 */
template <class T>
requires std::totally_ordered<T>
void InsertSort_with_gap(std::vector<T>& vec, size_t gap) {
    if (gap <= 1) {
        gap = 1;
    }
    size_t end = vec.size();
    for (size_t from = gap;
         from < end;
         from += 1) {
        size_t cmp = from;
        while (cmp >= gap && vec[cmp] < vec[cmp - gap]) {
            std::swap(vec[cmp], vec[cmp - gap]);
            cmp -= gap;
        }
    }
}

template <class T>
requires std::totally_ordered<T>
void ShellSort(std::vector<T>& vec) {
    if (vec.empty()) {
        return;
    }
    size_t gap = vec.size() / 2;
    while (gap > 0) {
        InsertSort_with_gap(vec, gap);
        gap /= 2;
    }
}