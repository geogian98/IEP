cmake_minimum_required(VERSION 3.19)
project(TemaIep1)

add_executable(${PROJECT_NAME}  main.cpp)

add_library(MyLib STATIC myLib.cpp)
target_link_libraries(${PROJECT_NAME} MyLib)

#instaleaza fisierele de executabil in folderul bin
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(TARGETS MyLib DESTINATION libs)
install(FILES myLib.h DESTINATION include)


