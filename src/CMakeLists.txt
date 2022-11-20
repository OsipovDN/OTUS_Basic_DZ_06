cmake_minimum_required (VERSION 3.8)

project (MyContainers)

add_executable (MyContainers 
	myContainers.cpp
	)

set_target_properties(MyContainers PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
target_include_directories(MyContainers PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(MyContainers PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../MyVector)
target_link_libraries (MyContainers MyVector)

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
    target_compile_options(MyContainers PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(MyContainers PUBLIC cxx_std_17)