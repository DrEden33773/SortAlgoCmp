/**
 * @file QuickSort.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-28
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

// video below could be a great reference:
// https://youtu.be/duln2xAZhBA

/**
 * @brief Vector_Only QuickSort
 *
 * @note sort range => [begin, end)
 *
 */

template <class T>
requires std::equality_comparable<T>
int Partition(std::vector<T>& vec, int begin, int end) {
    // set pivot
    int pivot = (begin + end) / 2;
    // convert [begin, end) to [front, back]
    const int& front = begin;
    const int& back  = end - 1;
    // move pivot to the back
    std::swap(vec[pivot], vec[back]);
    // set `eof_l` & `eof_g`
    // vec[front, eof_l) < vec[back]
    // vec[eof_l, eof_g) >= vec[back]
    // vec[eof_g, back) => unvisited
    int eof_l = front;
    int eof_g = front;
    // eof_g always go ahead, because you've visited the elem
    while (eof_g < back) {
        if (vec[eof_g] < vec[back]) {
            // add a member to `less part`
            std::swap(vec[eof_l], vec[eof_g]);
            // update range of `less part`
            ++eof_l;
        }
        // update range of `unvisited part` & `greater_eq part`
        ++eof_g;
    }
    // move vec[back] to vec[eof_l] <correct place>
    std::swap(vec[eof_l], vec[back]);
    // now, pivot(index) := eof_l(index)
    pivot = eof_l;
    // could return
    return pivot;
}

template <class T>
requires std::equality_comparable<T>
int AnotherPartition(std::vector<T>& vec, int begin, int end) {
    int pivot       = begin;
    int front       = begin;
    int back        = end - 1;
    T   pivot_value = vec[pivot];
    while (front < back) {
        // compare right part first
        while (front < back && vec[back] >= pivot_value) {
            --back;
        }
        std::swap(vec[front], vec[back]);

        // compare left part then
        while (front < back && vec[front] <= pivot_value) {
            ++front;
        }
        std::swap(vec[front], vec[back]);
    }
    vec[front] = std::move(pivot_value);
    pivot      = front;
    return pivot;
}

template <class T>
requires std::equality_comparable<T>
void QS(std::vector<T>& vec, int begin, int end) {
    if (end - begin > 1) {
        // [begin, end) contain at least `2 elements`
        int pivot = AnotherPartition(vec, begin, end);
        QS(vec, begin, pivot);
        QS(vec, pivot + 1, end);
    }
}

template <class T>
requires std::equality_comparable<T>
void QuickSort(std::vector<T>& vec) {
    if (vec.empty()) {
        return;
    }
    QS(vec, 0, vec.size());
}

/**
 * @brief Random/Bidirectional_Iterator_Container QuickSort
 *
 * @note sort range => [begin, end)
 *
 */

template <class Iter>
requires std::sortable<Iter>
    and (std::random_access_iterator<Iter>
         or std::bidirectional_iterator<Iter>)
Iter Partition(Iter begin, Iter end) {
    using std::advance;
    using std::distance;
    using std::next;
    using std::prev;
    using std::swap;

    Iter pivot = begin;
    advance(pivot, distance(begin, end) / 2);

    const Iter& front = begin;
    const Iter& back  = prev(end);
    swap(*pivot, *back);

    Iter   eof_l       = front;
    Iter   eof_g       = front;
    size_t g_back_dist = distance(eof_g, back);
    while (g_back_dist > 0) {
        if (*eof_g < *back) {
            swap(*eof_l, *eof_g);
            eof_l = next(eof_l);
        }
        eof_g = next(eof_g);
        --g_back_dist;
    }

    swap(*eof_l, *back);
    pivot = std::move(eof_l);

    return pivot;
}

template <class Iter>
requires std::sortable<Iter>
    and (std::random_access_iterator<Iter>
         or std::bidirectional_iterator<Iter>)
Iter AnotherPartition(Iter begin, Iter end) {
    using std::advance;
    using std::distance;
    using std::next;
    using std::prev;
    using std::swap;

    Iter pivot       = begin;
    auto pivot_value = *pivot;
    Iter front       = begin;
    Iter back        = prev(end);

    size_t front_back_dist = distance(front, back);
    while (front_back_dist > 0) {
        while (front_back_dist > 0 && *back >= pivot_value) {
            back = prev(back);
            --front_back_dist;
        }
        std::swap(*front, *back);
        while (front_back_dist > 0 && *front <= pivot_value) {
            front = next(front);
            --front_back_dist;
        }
        std::swap(*front, *back);
    }
    *front = std::move(pivot_value);
    pivot  = front;
    return pivot;
}

template <class Iter>
requires std::sortable<Iter>
    and (std::random_access_iterator<Iter>
         or std::bidirectional_iterator<Iter>)
void QuickSort(Iter begin, Iter end) {
    if (std::distance(begin, end) > 1) {
        Iter pivot = AnotherPartition(begin, end);
        QuickSort(begin, pivot);
        QuickSort(std::next(pivot), end);
    }
}