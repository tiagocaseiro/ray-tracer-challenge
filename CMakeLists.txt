cmake_minimum_required(VERSION 3.31)

project(ray-tracer)

add_executable(ray-tracer src/main.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_link_libraries(ray-tracer core)

target_include_directories(ray-tracer PUBLIC core)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  ray-tracer-tests
  tests/tuple_test.cpp
)
target_link_libraries(
  ray-tracer-tests
  GTest::gtest_main
  core
)

target_include_directories(ray-tracer-tests PUBLIC core)
target_include_directories(ray-tracer PUBLIC core)

include(GoogleTest)
gtest_discover_tests(ray-tracer-tests)

add_subdirectory(core)
