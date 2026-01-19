cmake_minimum_required(VERSION 3.16)

project(wiget VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Chỉ tìm Qt5
find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    src/main.cpp
    src/ultils/gaugewidget.cpp
    src/ultils/gaugewidget.h
    src/view/view.ui
    src/view/view.h
    src/view/view.cpp
    src/controller/controller.cpp
    src/controller/controller.h
    src/model/model.cpp
    src/model/model.h
    src/model/cpu/cpu.cpp
    src/model/cpu/cpu.h
    src/model/disk/disk.cpp
    src/model/disk/disk.h
    src/model/mem/mem.cpp
    src/model/mem/mem.h
    src/model/system/system.cpp
    src/model/system/system.h
)

add_executable(wiget ${PROJECT_SOURCES})

target_include_directories(wiget PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/view
    ${CMAKE_CURRENT_SOURCE_DIR}/src/controller
    ${CMAKE_CURRENT_SOURCE_DIR}/src/model
    ${CMAKE_CURRENT_SOURCE_DIR}/src/model/cpu
    ${CMAKE_CURRENT_SOURCE_DIR}/src/model/disk
    ${CMAKE_CURRENT_SOURCE_DIR}/src/model/mem
    ${CMAKE_CURRENT_SOURCE_DIR}/src/model/system
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ultils
)

target_link_libraries(wiget PRIVATE Qt5::Widgets)

include(GNUInstallDirs)
install(TARGETS wiget
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)