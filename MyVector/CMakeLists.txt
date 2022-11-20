cmake_minimum_required (VERSION 3.8)

project (My_Vector)

add_library (MyVector STATIC 
    src/myVector.cpp
    )

set_target_properties(MyContainers PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

target_include_directories(MyVector PRIVATE include)


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