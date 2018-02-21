cmake_minimum_required(VERSION 3.9)
project(MazeSolver)

set(CMAKE_CXX_STANDARD 11)


add_executable(MazeSolver
    LICENSE
    main.cpp
    main.o
    mainwindow.cpp
    mainwindow.h
    mainwindow.o
    mainwindow.ui
    maze.cpp
    maze.h
    maze.o
    MazeSolver
    mazesolver.cpp
    mazesolver.h
    mazesolver.o
    MazeSolver.pro
    MazeSolver.pro.user
    moc_mainwindow.cpp
    moc_mainwindow.o
    README.md
    ui_mainwindow.h)

#find_library (LogicToolbox REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
target_link_libraries(MazeSolver Qt5::Widgets)
target_link_libraries(MazeSolver Qt5::Core)
#target_link_libraries(MazeSolver LogicToolbox)