cmake_minimum_required (VERSION 3.8)

project (MyVector)

add_library (MyVector STATIC 
    myVector.cpp
    #include/myVector.h
    )

#target_include_directories(MyVector PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(MyVector PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(MyVector PRIVATE 
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

#target_compile_features(MyVector PUBLIC cxx_std_17)