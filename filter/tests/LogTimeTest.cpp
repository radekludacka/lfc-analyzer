/* 
 * File:   LogTimeTest.cpp
 * Author: radek
 *
 * Created on 31-Oct-2013, 15:13:43
 */

#include <stdlib.h>
#include <iostream>

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "LogTimeTest test 1" << std::endl;
}

void test2() {
    std::cout << "LogTimeTest test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (LogTimeTest) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% LogTimeTest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (LogTimeTest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (LogTimeTest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (LogTimeTest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (LogTimeTest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

