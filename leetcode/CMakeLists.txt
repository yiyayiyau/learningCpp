cmake_minimum_required(VERSION 3.7.2)

project(leetcode)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(arrays_linkedlist)

target_include_directories(${PROJECT_NAME} 
    PUBLIC arrays_linkedlist
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE arrays_linkedlist/
)

target_link_libraries(${PROJECT_NAME} 
    arrays_linkedlist
)

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)  #${CMAKE_INSTALL_PREFIX}/bin
install(FILES "${PROJECT_NAME}" DESTINATION src)    #${CMAKE_INSTALL_PREFIX}/src