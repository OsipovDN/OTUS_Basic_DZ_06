cmake_minimum_required (VERSION 3.8)

project (My_Vector)

add_library (MyVector STATIC 
    src/myVector.cpp
    )

target_include_directories(MyVector PRIVATE include)

set_target_properties(MyVector PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(calc PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(MyVector PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(MyVector PUBLIC cxx_std_17)