cmake_minimum_required (VERSION 3.8)

project (MyContainers)

add_subdirectory(MyVector)

add_executable (MyContainers 
	src/myContainers.cpp
	)

set_target_properties(MyContainers PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
target_include_directories(
	MyContainers
	PRIVATE
	${CMAKE_SOURCE_DIR}/MyVector
)
target_link_libraries(
	MyContainers
	PRIVATE
	MyVector
)






