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
#include "../utility/OrderAssertion.hpp"

#include <chrono>
#include <fstream>
#include <functional>
#include <stdexcept>
#include <utility>

namespace Module {
class Executor {
    using fs_path = std::filesystem::path;

    static constexpr int LEN = 5e4;

    const std::vector<std::pair<
        std::function<void(std::vector<int>&)>, std::string>>
        NormalSortTable {
            {InsertSort<int>,     "InsertSort"   },
            { SelectionSort<int>, "SelectionSort"},
            { BubbleSort<int>,    "BubbleSort"   },
            { ShellSort<int>,     "ShellSort"    },
            { HeapSort<int>,      "HeapSort"     },
            { QuickSort<int>,     "QuickSort"    },
            { MergeSort<int>,     "MergeSort"    },
    };

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
        sample_file.close();
    }
    void exec_all_sort() {
        using std::chrono::microseconds;

        // 1. NormalSort (except RadixSort)
        for (auto&& [sortFunc, sortName] : NormalSortTable) {
            // clone unsorted
            std::vector<int> cloned = received;
            // timing begin
            auto begin_time = std::chrono::system_clock::now();
            // exec algo
            sortFunc(cloned);
            // timing end
            auto end_time = std::chrono::system_clock::now();
            // assert if sorted
            Utility::assert_if_ascending_order(cloned);
            // get duration
            std::chrono::duration<double, std::milli> duration = end_time - begin_time;
            // output
            std::cout << sortName << " => " << duration.count() << " ms.";
            std::cout << std::endl;
        }
        // 2. RadixSort
        {
            std::vector<size_t> cloned;
            cloned.reserve(received.size());
            for (int curr : received) {
                cloned.emplace_back(
                    static_cast<size_t>(curr)
                );
            }
            // build helper
            RadixSortHelper<size_t> Helper(cloned);
            // timing begin
            auto begin_time = std::chrono::system_clock::now();
            // exec
            Helper.executer();
            // timing end
            auto end_time = std::chrono::system_clock::now();
            // return sorted
            cloned = Helper.return_sorted();
            // assert
            Utility::assert_if_ascending_order(cloned);
            // duration
            std::chrono::duration<double, std::milli> duration = end_time - begin_time;
            // output
            std::cout << "RadixSort => " << duration.count() << " ms.";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    void for_each_sample_exec() {
        using std::cout;
        using std::endl;
        using std::fstream;

        int idx = 0;
        for (const auto& curr_path : Utility::FileManager::all_sample) {
            cout << "Now, sort <sample " << idx << "> : ";
            cout << endl;
            cout << endl;
            load_sample(curr_path);
            exec_all_sort();
            ++idx;
        }
    }

public:
    static void exec() {
        Executor exec_process;
        exec_process.for_each_sample_exec();
    }
};

} // namespace Module