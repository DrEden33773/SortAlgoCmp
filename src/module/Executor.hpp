/**
 * @file Executor.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-12-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "../algorithm/Sort.hpp"
#include "../utility/FileManager.hpp"

#include <fstream>
#include <stdexcept>

namespace Module {
class Executor {
    using fs_path = std::filesystem::path;

    static constexpr int LEN = 5e4;

    std::vector<int> received;

    void load_sample(const fs_path& sample_path) {
        using std::fstream;
        // 1. clear the container
        received.clear();
        // 2. reserve
        received.reserve(LEN);
        // 3. option
        fstream sample_file(sample_path, fstream::binary | fstream::in);
        if (!sample_file.is_open()) {
            throw std::runtime_error("Cannot open sample file!");
        }
        int temp = 0;
        while (sample_file >> temp) {
            received.emplace_back(temp);
        }
        // end of load_sample
    }

public:
    static void exec() {
        Executor exec_process;
    }
};

} // namespace Module