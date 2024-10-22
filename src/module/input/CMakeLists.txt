cmake_minimum_required(VERSION 3.16)
project(JControl VERSION 1.0 LANGUAGES C CXX)

#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)#без этого mcvs не сгенерирует DLL

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

add_subdirectory(qjoysticks)

qt_add_library(${PROJECT_NAME} STATIC
    j_interfaces.h
    jcontrol.cpp
    jcontrol.h
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    QJoysticks
)
