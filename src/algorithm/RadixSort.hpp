/**
 * @file RadixSort.hpp
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
#include <concepts>
#include <iostream>
#include <list>
#include <type_traits>
#include <vector>

template <class T>
concept if_nonnegative_integer
    = std::is_same_v<T, unsigned short>
    or std::is_same_v<T, unsigned int>
    or std::is_same_v<T, unsigned long>
    or std::is_same_v<T, unsigned long long>;

template <class T>
requires if_nonnegative_integer<T>
class RadixSortHelper {
    static constexpr T RADIX = 65536;

    using vector    = std::vector<T>;
    using list      = std::list<T>;
    using bucket_t  = std::vector<T>;
    using buckets_t = std::vector<bucket_t>;

    std::vector<T> vec;
    buckets_t      buckets = buckets_t(RADIX, bucket_t());

    explicit RadixSortHelper(std::vector<T>& toSort)
        : vec(toSort) {
    }
    int get_max_len() {
        int ret = 0;
        for (auto num : vec) {
            int curr_len = 0;
            while (num > 0) {
                num /= RADIX;
                ++curr_len;
            }
            ret = std::max(ret, curr_len);
        }
        return ret;
    }
    void build_buckets(int pos) {
        for (auto&& value : vec) {
            T   value_clone = value;
            T   identifier  = 0;
            int curr_pos    = pos;
            while (curr_pos > 0) {
                identifier = value_clone % RADIX;
                value_clone /= RADIX;
                --curr_pos;
            }
            buckets[identifier].push_back(value);
        }
    }
    void extract_buckets() {
        int idx = 0;
        for (int bucket_idx = 0; bucket_idx < RADIX; ++bucket_idx) {
            auto& bucket = buckets[bucket_idx];
            for (auto&& value : bucket) {
                vec[idx] = std::move(value);
                ++idx;
            }
        }
    }
    void clean_buckets() {
        for (auto&& bucket : buckets) {
            bucket.clear();
        }
    }
    void executer() {
        int max_len = get_max_len();
        for (int pos = 1; pos <= max_len; ++pos) {
            build_buckets(pos);
            extract_buckets();
            clean_buckets();
        }
    }

public:
    static void RadixSort(std::vector<T>& toSort) {
        if (toSort.empty()) {
            return;
        }

        RadixSortHelper helper(toSort);
        helper.executer();
        toSort = helper.vec;
    }
};