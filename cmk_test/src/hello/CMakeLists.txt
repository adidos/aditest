SET(SRC_LIST main.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)
ADD_EXECUTABLE(hello ${SRC_LIST})

TARGET_LINK_LIBRARIES(hello util)
