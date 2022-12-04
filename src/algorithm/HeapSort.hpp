/**
 * @file HeapSort.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-30
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

// reference of
// https://www.cnblogs.com/chengxiao/p/6129630.html

/**
 * @brief Vector_Only HeapSort
 *
 * @note sort range => [begin, end)
 *
 */
template <class T>
requires std::equality_comparable<T>
void BuildMaxHeap(std::vector<T>& vec, int root, int end) {
    int dad = root;
    int son = 2 * dad + 1;
    while (son < end) {
        // 1. cmp two sons
        if (son + 1 < end && vec[son] < vec[son + 1]) {
            ++son;
        }
        // 2. cmp dad and max son
        if (vec[dad] > vec[son]) {
            return; // OK
        } else {
            std::swap(vec[dad], vec[son]);
            dad = son;
            son = 2 * dad + 1;
        }
    }
}
template <class T>
requires std::equality_comparable<T>
void HeapSort(std::vector<T>& vec) {
    if (vec.empty()) {
        return;
    }
    int begin = 0;
    int end   = vec.size();
    int len   = end;
    // 1. init
    int root = len / 2 - 1; // the last parent node
    for (; root >= 0; --root) {
        BuildMaxHeap(vec, root, end);
    }
    // 2. adjust
    int te = end;
    for (; te > 0; --te) {
        std::swap(vec[0], vec[te - 1]);
        BuildMaxHeap(vec, 0, te - 1);
    }
}