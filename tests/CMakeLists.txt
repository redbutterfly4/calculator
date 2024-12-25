add_executable(runUnitTests CalculatorTests.cpp)

target_link_libraries(runUnitTests gtest gtest_main lib)

add_test(runTests runUnitTests)