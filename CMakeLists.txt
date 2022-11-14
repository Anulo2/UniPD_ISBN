cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
project(rational)

include_directories(include)

add_library(${PROJECT_NAME}
			src/rational.cpp)
			
add_library(book
			src/book.cpp)

add_library(date
			src/date.cpp)

add_library(isbn
			src/isbn.cpp)

add_executable(main src/main.cpp)

target_link_libraries(main ${PROJECT_NAME})
