cmake_minimum_required(VERSION 3.29)
project(seminar09)
set(CMAKE_CXX_STANDARD 20)
include_directories(lib/spdlog)

enable_testing()

add_subdirectory(src)

add_executable(main main.cpp)
target_link_libraries(main lib)


add_subdirectory(lib)
include_directories(src)

add_subdirectory(tests)
