cmake_minimum_required (VERSION 3.8)

project (MyList)

add_library (MyList STATIC 
    myList.cpp
    )


set_target_properties(MyList PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(MyList PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(MyList PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()
