cmake_minimum_required(VERSION 3.25)
project(LoadSetting VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)#без этого mcvs не сгенерирует DLL

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_library(${PROJECT_NAME} STATIC
    loader.cpp
    loader.h
    settingsmod.h
    settingsmod.cpp
    p_interfaces.h
    ds.h
)

set(DEST_FILE "${CMAKE_BINARY_DIR}/settings.txt")

configure_file(settings.txt ${DEST_FILE} COPYONLY)

# qt_add_resources(
#     ${PROJECT_NAME} "settings"
#     PREFIX "/"
#     FILES
#     settings.txt
# )


target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC Qt::Core)
