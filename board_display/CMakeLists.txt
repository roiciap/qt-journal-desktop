cmake_minimum_required(VERSION 3.14)

project(board_display LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)



add_library(board_display STATIC
  board-display.h  board-display.cpp
  note-board-display.cpp  note-board-display.h
  note-board-display.qml


)


target_link_libraries(board_display PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_compile_definitions(board_display PRIVATE BOARD_DISPLAY_LIBRARY)
