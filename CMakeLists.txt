cmake_minimum_required(VERSION 3.24)
project(Tutorial VERSION 1.4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11) # -std=c++17
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_14)

option(USE_MYMATH "Use My Math?" ON)

message(STATUS "OUT --- ${CMAKE_CURRENT_SOURCE_DIR}")

configure_file(TutorialConfig.h.in TutorialConfig.h)

if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    # list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

add_executable(Tutorial tutorial.cpp)
# 指定include的头文件目录
target_include_directories(Tutorial PUBLIC ${PROJECT_BINARY_DIR} ${EXTRA_INCLUDES})
# 链接库
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS} tutorial_compiler_flags) 

install(TARGETS Tutorial DESTINATION bin)
message(STATUS "${CMAKE_INSTALL_PREFIX}")
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)