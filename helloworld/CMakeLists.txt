cmake_minimum_required(VERSION 3.7.2)

project(HelloWorld)

add_executable(${PROJECT_NAME} Main.cpp adder.cpp) #if there are many files, just put it behind main.cpp

add_subdirectory(Adder) # if you have libraries

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} PUBLIC Adder) # with this line, in main.cpp you donnot need #include with path
# and you will get a lib-file in build
 
target_link_directories(${PROJECT_NAME} PRIVATE Adder/)

target_link_libraries(${PROJECT_NAME} Adder) # Project_name lib_name1 lib_name2

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)  #${CMAKE_INSTALL_PREFIX}/bin
install(FILES "${PROJECT_NAME}" DESTINATION src)    #${CMAKE_INSTALL_PREFIX}/src
