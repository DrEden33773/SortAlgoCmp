/**
 * @file InsertSort.hpp
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
#include <vector>

/* InsertSort is `Stable` */

template <class Iter>
requires std::sortable<Iter>
    and (std::random_access_iterator<Iter>
         or std::bidirectional_iterator<Iter>)
void InsertSort(Iter begin, Iter end) {
    using std::distance;
    using std::next;
    using std::prev;

    Iter curr          = next(begin);
    auto curr_end_dist = distance(curr, end);
    while (curr_end_dist) {
        Iter cmp            = curr;
        auto begin_cmp_dist = distance(begin, cmp);
        while (begin_cmp_dist && *cmp < *prev(cmp)) {
            std::swap(*cmp, *prev(cmp));
            --cmp;
            --begin_cmp_dist;
        }
        ++curr;
        --curr_end_dist;
    }
}

template <class T>
requires std::equality_comparable<T>
void InsertSort(std::vector<T>& vec) {
    size_t size = vec.size();
    for (size_t from = 1; from < size; ++from) {
        size_t cmp = from;
        while (cmp >= 1 && vec[cmp] < vec[cmp - 1]) {
            std::swap(vec[cmp], vec[cmp - 1]);
            --cmp; // important
        }
    }
}
