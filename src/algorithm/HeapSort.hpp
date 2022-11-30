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
void MakeHeapFrom(std::vector<T>& vec, int root, int end) {
    int left  = 2 * root + 1;
    int right = left + 1;
    if (left < end && vec[left] > vec[root]) {
        std::swap(vec[left], vec[root]);
    }
    if (right < end && vec[right] > vec[root]) {
        std::swap(vec[right], vec[root]);
    }
}

template <class T>
requires std::equality_comparable<T>
void MakeHeap(std::vector<T>& vec, int begin, int end) {
    int back = end - 1;
    while (back >= 0) {
        MakeHeapFrom(vec, back, end);
        --back;
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
    // [begin, end) at least contains 2 elems
    while (end - begin > 1) {
        // 1. MakeHeap
        MakeHeap(vec, begin, end);
        // 2. Move `Max` in heap to the tail
        std::swap(vec[begin], vec[end - 1]);
        // 3. update
        --end;
    }
}

/**
 * @brief Random/Bidirectional_Iterator_Container HeapSort
 *
 * @note sort range => [begin, end)
 *
 */

template <class Iter>
requires std::sortable<Iter>
    and (std::random_access_iterator<Iter>
         or std::bidirectional_iterator<Iter>)
void MakeHeapFrom(Iter root, Iter end) {
    using std::distance;
    using std::prev;
    using std::swap;
}

template <class Iter>
requires std::sortable<Iter>
    and (std::random_access_iterator<Iter>
         or std::bidirectional_iterator<Iter>)
void MakeHeap(Iter begin, Iter end) {
    using std::distance;
    using std::prev;
    using std::swap;
}

template <class Iter>
requires std::sortable<Iter>
    and (std::random_access_iterator<Iter>
         or std::bidirectional_iterator<Iter>)
void HeapSort(Iter begin, Iter end) {
    using std::distance;
    using std::prev;
    using std::swap;
    if (distance(begin, end) > 1) {
        Iter back = prev(end);
        // 1. MakeHeap
        MakeHeap(begin, end);
        // 2. Move `Max` in heap to the tail
        swap(*begin, *back);
        // 3. update
        end = prev(end);
    }
}