/**
 * @file Generator.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief To generate different samples
 * @version 0.1
 * @date 2022-12-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "../utility/FileManager.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

namespace Module {

class Generator {
    static constexpr int SAMPLE_NUM   = 10;  // 10 samples
    static constexpr int LEN          = 5e4; // 50000 elements/sample
    static constexpr int NUM_PER_LINE = 20;  // 20 elements/line
    static constexpr int MAX_NUM      = std::numeric_limits<int>::max() - 1;
    enum class Order : unsigned short {
        ascending  = 0,
        descending = 1,
        random     = 2,
    };

    void title_info() {
        std::cout << "Start to generate 10 samples..." << std::endl;
        std::cout << std::endl;
    }
    void end_info() {
        std::cout << "Done!" << std::endl;
        std::cout << std::endl;
    }
    void generate_for(std::fstream& file, Order order = Order::random) {
        /* initialize random seed: */
        srand(time(nullptr));
        /* vector */
        std::vector<int> container {};
        container.reserve(LEN);
        /* for-loop */
        for (int i = 0; i < LEN; ++i) {
            int curr = 0;
            curr     = rand() % MAX_NUM + 1;
            container.emplace_back(curr);
        }
        /* adjust if necessary */
        if (order == Order::ascending) {
            std::sort(
                container.begin(),
                container.end(),
                [](const int& a, const int& b) {
                    return a < b;
                }
            );
        } else if (order == Order::descending) {
            std::sort(
                container.begin(),
                container.end(),
                [](const int& a, const int& b) {
                    return a > b;
                }
            );
        }
        /* write into file */
        int cnt = 0;
        for (auto&& curr : container) {
            file << curr << " ";
            if (cnt != 0 && cnt % NUM_PER_LINE == 0) {
                file << std::endl;
            }
            ++cnt;
        }
    }

public:
    /**
     * @brief @b opt_collections
     *
     */
    void generate_samples() {
        using std::fstream;
        using Utility::FileManager::all_sample;
        for (const auto& curr_path : all_sample) {
            // 1. create file
            fstream file(curr_path, fstream::binary | fstream::out);
            if (!file.is_open()) {
                throw std::runtime_error("Cannot open/create sample file!");
            }
            // 2. generate
            if (curr_path == all_sample.at(0)) {
                generate_for(file, Order::ascending);
            } else if (curr_path == all_sample.at(1)) {
                generate_for(file, Order::descending);
            } else {
                generate_for(file, Order::random);
            }
            // 3. don't forget to close file!
            file.close();
        }
    }
    /**
     * @brief @b outer_interface
     *
     */
    static void generate() {
        Generator generate_process;
        generate_process.generate_samples();
    }
};

} // namespace Module