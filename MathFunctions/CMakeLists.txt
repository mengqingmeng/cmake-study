project(MathFunctions VERSION 1.0 LANGUAGES CXX) # 可以不写

set(CMAKE_CXX_STANDARD 11) # -std=c++17
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(MathFunctions add.cpp div.cpp mult.cpp sub.cpp)
target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)
message(STATUS "MathFunction --- ${CMAKE_CURRENT_SOURCE_DIR}")

set(installable_libs MathFunctions tutorial_compiler_flags)
install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES head.h DESTINATION include)