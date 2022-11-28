/**
 * @file Print.hpp
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

template <class Iter>
requires std::sortable<Iter>
void Print(Iter begin, Iter end) {
    for (Iter curr = begin; std::distance(curr, end); ++curr) {
        std::cout << *curr << " ";
    }
}

template <class Iter>
requires std::sortable<Iter>
void Println(Iter begin, Iter end) {
    for (Iter curr = begin; std::distance(curr, end); ++curr) {
        std::cout << *curr << " ";
    }
    std::cout << std::endl;
}