/**
 * @file BubbleSort.hpp
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

template <class Iter>
requires std::sortable<Iter>
    and (std::random_access_iterator<Iter>
         or std::bidirectional_iterator<Iter>)
void BubbleSort(Iter begin, Iter end) {
    using std::advance;
    using std::distance;
    using std::next;
    long size = distance(begin, end);
    if (size <= 1) {
        return;
    }
    for (long subbed = 0; subbed < size; ++subbed) {
        Iter destination = end;
        advance(destination, -1 - subbed);

        Iter cmp      = begin;
        auto cmp_dist = distance(cmp, destination);
        while (cmp_dist) {
            if (*cmp > *next(cmp)) {
                std::swap(*cmp, *next(cmp));
            }
            ++cmp;
            --cmp_dist;
        }
    }
}

template <class T>
requires std::totally_ordered<T>
void BubbleSort(std::vector<T>& vec) {
    long size = vec.size();
    for (long subbed = 0; subbed < size; ++subbed) {
        bool if_sorted = true;
        for (long cmp = 0; cmp < size - 1 - subbed; ++cmp) {
            if (vec[cmp] > vec[cmp + 1]) {
                if_sorted = false;
                std::swap(vec[cmp], vec[cmp + 1]);
            }
        }
        if (if_sorted) {
            break;
        }
    }
}