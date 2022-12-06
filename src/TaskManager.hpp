/**
 * @file TaskManager.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "module/Executor.hpp"
#include "module/Generator.hpp"
#include "utility/FileManager.hpp"

namespace Task {

void RunAllTask() {

    Utility::FileManager::path_init();
    Module::Generator::generate();
    Module::Executor::exec();
}

} // namespace Task