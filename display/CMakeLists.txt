cmake_minimum_required(VERSION 3.14)

project(display LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Quick QuickWidgets)

qt_add_resources(DISPLAY_QML_SOURCES qml-files.qrc)

set(QML_SOURCES ${DISPLAY_QML_SOURCES} CACHE INTERNAL "")
add_library(display STATIC


  board-display.h  board-display.cpp
  note-board-display.cpp  note-board-display.h
  note-board-display.qml
  qml-files.qrc
)



target_link_libraries(display PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::QuickWidgets)

target_compile_definitions(display PRIVATE DISPLAY_LIBRARY)
