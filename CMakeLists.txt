cmake_minimum_required(VERSION 3.28)
project(fisica LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 3.0.0
  GIT_SHALLOW ON
  EXCLUDE_FROM_ALL
  SYSTEM)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG 11.1.4)
FetchContent_MakeAvailable(fmt)  

add_executable(fisica
  src/main.cpp
  src/body.cpp)

target_compile_features(fisica PRIVATE cxx_std_20)
target_compile_options(fisica PRIVATE -Wall -Wextra -Wpedantic)

target_link_libraries(fisica PRIVATE SFML::Graphics)
target_link_libraries(fisica PRIVATE SFML::System)
target_link_libraries(fisica PRIVATE fmt::fmt)
