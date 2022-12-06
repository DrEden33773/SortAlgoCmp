/**
 * @file main.cpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "TaskManager.hpp"
#include "test/RunAllTest.hpp"

int main(int argc, char** argv) {
    // test::run_all_test();
    Task::RunAllTask();
    return 0;
}
