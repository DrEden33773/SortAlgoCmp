/**
 * @file FileManager.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <algorithm>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace Utility::FileManager {

namespace fs = std::filesystem;

namespace Path {
    /* root */
    static const fs::path Root = "Samples";
} // namespace Path

namespace Filename {
    /* Use this to build the rebuild the `Route` */
    static const fs::path s1  = Path::Root / "s1.bin";
    static const fs::path s2  = Path::Root / "s2.bin";
    static const fs::path s3  = Path::Root / "s3.bin";
    static const fs::path s4  = Path::Root / "s4.bin";
    static const fs::path s5  = Path::Root / "s5.bin";
    static const fs::path s6  = Path::Root / "s6.bin";
    static const fs::path s7  = Path::Root / "s7.bin";
    static const fs::path s8  = Path::Root / "s8.bin";
    static const fs::path s9  = Path::Root / "s9.bin";
    static const fs::path s10 = Path::Root / "s10.bin";
} // namespace Filename

/* all_path in a vec */
static const std::vector<fs::path> all_path {
    Path::Root,
};

/* all_sample in a vec */
static const std::vector<fs::path> all_sample {
    Filename::s1,
    Filename::s2,
    Filename::s3,
    Filename::s4,
    Filename::s5,
    Filename::s6,
    Filename::s7,
    Filename::s8,
    Filename::s9,
    Filename::s10,
};

static void build_all_path() {
    std::for_each(
        all_path.begin(),
        all_path.end(),
        [](const fs::path& curr) {
            if (!fs::exists(curr)) {
                try {
                    fs::create_directories(curr);
                } catch (fs::filesystem_error& e) {
                    std::cout << "Could not create directory, because: " << e.what() << std::endl;
                }
            }
        }
    );
}
static void check_all_path_existence() {
    std::for_each(
        all_path.begin(),
        all_path.end(),
        [](const fs::path& curr) {
            if (!fs::exists(curr)) {
                throw std::runtime_error("A FilePath is NOT exist!");
            }
        }
    );
}
static void path_init() {
    build_all_path();
    check_all_path_existence();
    std::cout << "Path_Init Succeeded!" << std::endl;
    std::cout << std::endl;
}

} // namespace Utility::FileManager