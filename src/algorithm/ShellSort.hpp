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
void OriginalInsertSort(std::vector<T>& vec) {
    long long size = vec.size();
    for (long long curr = 1; curr < size; ++curr) {
        long long cmp = curr;
        while (cmp > 0 && vec[cmp] < vec[cmp - 1]) {
            std::swap(vec[cmp], vec[cmp - 1]);
            --cmp;
        }
    }
}

/**
 * @brief PartialInsertSort
 * @warning
        `size_t` index is not allowed, for code below:
            cmp -= interval; // if use `size_t`, `overflow` must happen
 *
 * @tparam T
 * @param vec
 * @param interval
 * @return requires
 */
template <class T>
requires std::equality_comparable<T>
void PartialInsertSort(std::vector<T>& vec, long long interval) {
    if (vec.empty() || vec.size() <= interval) {
        return;
    }
    if (interval <= 1) {
        OriginalInsertSort(vec);
        return;
    }
    long long begin = 0;
    long long end   = vec.size();
    // separate into different slices
    for (long long slice_beg = begin;
         slice_beg < end;
         slice_beg += interval) {
        bool if_effective_slice = false;
        // try to opt on any effective slice
        for (long long curr = slice_beg + interval;
             curr < end;
             curr += interval) {
            // find an effective slice
            if_effective_slice = true;
            long long cmp      = curr;
            while (cmp > slice_beg && vec[cmp] < vec[cmp - interval]) {
                std::swap(vec[cmp], vec[cmp - interval]);
                cmp -= interval;
            }
        }
        if (!if_effective_slice) {
            break;
        }
        slice_beg += interval;
    }
}

template <class T>
requires std::equality_comparable<T>
void ShellSort(std::vector<T>& vec) {
    if (vec.empty()) {
        return;
    }
    // PartialInsertSort(vec, 19);
    // PartialInsertSort(vec, 17);
    // PartialInsertSort(vec, 13);
    // PartialInsertSort(vec, 11);
    // PartialInsertSort(vec, 7);
    PartialInsertSort(vec, 5);
    PartialInsertSort(vec, 3);
    PartialInsertSort(vec, 1);
}