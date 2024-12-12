add_executable(runUnitTests VehicleTests.cpp)

target_link_libraries(runUnitTests gtest gtest_main lib)

add_test(runTests runUnitTests)