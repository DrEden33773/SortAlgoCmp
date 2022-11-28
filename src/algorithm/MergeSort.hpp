/**
 * @file MergeSort.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-18
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
void Merge(std::vector<T>& vec, size_t begin, size_t mid, size_t end) {
    using type = std::remove_cvref_t<T>;

    // Merge Sorted `vec[begin : ..mid]` and `vec[mid : ..end]`
    // method => two finger
    size_t len = end - begin;

    std::vector<type> tmp;
    tmp.reserve(len);

    size_t left      = begin;
    size_t right     = mid;
    size_t left_lim  = mid;
    size_t right_lim = end;
    while (left < left_lim && right < right_lim) {
        if (vec[left] < vec[right]) {
            tmp.emplace_back(vec[left]);
            ++left;
        } else {
            tmp.emplace_back(vec[right]);
            ++right;
        }
    }
    while (left < left_lim) {
        tmp.emplace_back(vec[left]);
        ++left;
    }
    while (right < right_lim) {
        tmp.emplace_back(vec[right]);
        ++right;
    }

    size_t idx = begin;
    for (type& curr : tmp) {
        vec[idx] = std::move(curr);
        ++idx;
    }
}

// sort vec[begin : ..end]
// (index in [begin, end))
template <class T>
requires std::equality_comparable<T>
void MS(std::vector<T>& vec, size_t begin, size_t end) {
    if (end - begin > 1) { // [begin,end), at least contain one elem
        size_t mid = (begin + end) / 2;
        MS(vec, begin, mid);
        MS(vec, mid, end);
        Merge(vec, begin, mid, end);
    }
}

template <class T>
requires std::equality_comparable<T>
void MergeSort(std::vector<T>& vec) {
    if (!vec.size()) {
        return;
    }
    MS(vec, 0, vec.size());
}

template <class Iter>
requires std::sortable<Iter>
    and (std::random_access_iterator<Iter>
         or std::bidirectional_iterator<Iter>)
void Merge(Iter begin, Iter mid, Iter end) {
    using std::advance;
    using std::distance;
    using type = std::remove_cvref_t<decltype(*begin)>;

    size_t len = distance(begin, end);

    std::vector<type> tmp;
    tmp.reserve(len);

    Iter left      = begin;
    Iter right     = mid;
    Iter left_lim  = mid;
    Iter right_lim = end;

    auto l_dist = distance(left, left_lim);
    auto r_dist = distance(right, right_lim);
    while (l_dist && r_dist) {
        if (*left < *right) {
            tmp.emplace_back(*left);
            ++left;
            --l_dist;
        } else {
            tmp.emplace_back(*right);
            ++right;
            --r_dist;
        }
    }
    while (l_dist) {
        tmp.emplace_back(*left);
        ++left;
        --l_dist;
    }
    while (r_dist) {
        tmp.emplace_back(*right);
        ++right;
        --r_dist;
    }

    for (type& curr : tmp) {
        *begin = std::move(curr);
        ++begin;
    }
}

// sort [begin : ..end] <=> [begin, end)
template <class Iter>
requires std::sortable<Iter>
    and (std::random_access_iterator<Iter>
         or std::bidirectional_iterator<Iter>)
void MergeSort(Iter begin, Iter end) {
    using std::advance;
    using std::distance;
    if (distance(begin, end) > 1) { // [begin,end), at least contain one elem
        Iter mid = begin;
        advance(mid, distance(begin, end) / 2);
        MergeSort(begin, mid);
        MergeSort(mid, end);
        Merge(begin, mid, end);
    }
}