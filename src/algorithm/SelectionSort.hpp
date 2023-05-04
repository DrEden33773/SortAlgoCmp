/**
 * @file SelectionSort.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-17
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

template <class Iter>
requires std::sortable<Iter>
    and (std::random_access_iterator<Iter>
         or std::bidirectional_iterator<Iter>
         or std::forward_iterator<Iter>)
void SelectionSort(Iter begin, Iter end) {
    using std::distance;
    using std::next;

    Iter expect          = begin;
    auto expect_end_dist = distance(expect, prev(end));
    while (expect_end_dist) {
        Iter minimum = expect;

        Iter cmp          = next(expect);
        auto cmp_end_dist = distance(cmp, end);
        while (cmp_end_dist) {
            if (*cmp < *minimum) {
                minimum = cmp;
            }
            ++cmp;
            --cmp_end_dist;
        } // located minimum

        std::swap(*minimum, *expect);
        ++expect;
        --expect_end_dist;
    }
}

template <class T>
requires std::totally_ordered<T>
void SelectionSort(std::vector<T>& vec) {
    size_t size = vec.size();
    for (size_t expect = 0; expect < size - 1; ++expect) {
        size_t minimum = expect;
        for (size_t cmp = expect + 1; cmp < size; ++cmp) {
            if (vec[cmp] < vec[minimum]) {
                minimum = cmp;
            }
        } // located minimum
        std::swap(vec[minimum], vec[expect]);
    }
}