PROJECT (HELLO)
ADD_SUBDIRECTORY(src)

SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
SET(CMAKE_BINARY_OUTPUT_DIRCTORY ${PROJECT_BINARY_DIR}/bin)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
LINK_DIRECTORIES(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
