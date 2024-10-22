cmake_minimum_required(VERSION 3.25)

project(GUI VERSION 0.1 LANGUAGES CXX)
set(GST_DEBUG "3")
set(CMAKE_VERBOSE_MAKEFILE ON)
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)#без этого mcvs не сгенерирует DLL
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#рекомендация от KDAB
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#рекомендация от KDAB



find_package(PkgConfig)

pkg_check_modules(GST REQUIRED
    gstreamer-1.0>=1.14
    gstreamer-video-1.0>=1.14
    gstreamer-gl-1.0>=1.14
)

# find_package(PkgConfig REQUIRED)
# pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET
#     #libavdevice
#     libavfilter
#     libavformat
#     libavcodec
#     libswresample
#     #libswscale
#     libavutil
# )


find_package(Qt6 ${QT_VERSION} REQUIRED COMPONENTS Qml Core Quick Gui Multimedia Widgets)
#find_package(Qt6 6.4 COMPONENTS Gui Multimedia Core Quick Widgets REQUIRED)

qt_standard_project_setup()

macro (propagate_to_parent)
    set (HEADERS ${HEADERS} PARENT_SCOPE)
    set (SOURCES ${SOURCES} PARENT_SCOPE)
    set (QML ${QML} PARENT_SCOPE)
    set (SVG ${SVG} PARENT_SCOPE)
    set (IMAGE ${IMAGE} PARENT_SCOPE)
endmacro()

macro (add_headers)
    file (RELATIVE_PATH _relPath "${PROJECT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src ${ARGN})
        if (_relPath)
            list (APPEND HEADERS "${_relPath}/${_src}")
        else()
            list (APPEND HEADERS "${_src}")
        endif()
    endforeach()
endmacro()

macro (add_sources)
    file (RELATIVE_PATH _relPath "${PROJECT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src ${ARGN})
        if (_relPath)
            list (APPEND SOURCES "${_relPath}/${_src}")
        else()
            list (APPEND SOURCES "${_src}")
        endif()
    endforeach()
endmacro()

macro (add_qml)
    file (RELATIVE_PATH _relPath "${PROJECT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src ${ARGN})
        if (_relPath)
            list (APPEND QML "${_relPath}/${_src}")
        else()
            list (APPEND QML "${_src}")
        endif()
    endforeach()
endmacro()

macro (add_svg)
    file (RELATIVE_PATH _relPath "${PROJECT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src ${ARGN})
        if (_relPath)
            list (APPEND SVG "${_relPath}/${_src}")
        else()
            list (APPEND SVG "${_src}")
        endif()
    endforeach()
endmacro()


macro (add_image) #?????? ?????????? ????? ? ????????? ??????????? ?? ????????? ?????
    foreach (_src ${ARGN})
        file(GLOB_RECURSE image_files LIST_DIRECTORIES false RELATIVE "${PROJECT_SOURCE_DIR}" ${CMAKE_CURRENT_SOURCE_DIR}/${_src}/*.svg ${CMAKE_CURRENT_SOURCE_DIR}/${_src}/*.png)
        list (APPEND IMAGE "${image_files}")
    endforeach()
endmacro()

add_subdirectory(front)

qt_add_library(${PROJECT_NAME} STATIC
    g_interfaces.h
    gs.cpp
    gs.h
    guimod.cpp
    guimod.h
    ${HEADERS}
    ${SOURCES}
)
target_include_directories(${PROJECT_NAME} PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}
${GST_INCLUDE_DIRS}
)
qt_add_resources(${PROJECT_NAME} ui
    PREFIX "/"
    FILES main.qml ${QML} ${SVG} ${IMAGE}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt6::Gui
    Qt6::Widgets
    Qt6::Multimedia
    Qt6::Core
    Qt6::Quick
    Qt6::Qml
    ${GST_LINK_LIBRARIES}
)
