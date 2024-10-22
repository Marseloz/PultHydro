cmake_minimum_required(VERSION 3.16)
project(QJoysticks VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)#без этого mcvs не сгенерирует DLL

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Widgets)

qt_standard_project_setup()

qt_add_library(QJoysticks STATIC
    src/QJoysticks.cpp src/QJoysticks.h
    src/QJoysticks/JoysticksCommon.h
    src/QJoysticks/SDL_Joysticks.cpp src/QJoysticks/SDL_Joysticks.h
    src/QJoysticks/VirtualJoystick.cpp src/QJoysticks/VirtualJoystick.h
)
target_include_directories(QJoysticks PUBLIC
    lib/SDL/include
    src
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(QJoysticks PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
)
# Resources:
qt_add_resources(QJoysticks "qjoysticks-res"
    PREFIX
        "/QJoysticks"
    BASE
        "etc/resources"
    FILES
        "etc/resources/qjoysticks-res.qrc"
)


target_compile_definitions(QJoysticks PRIVATE SDL_SUPPORTED)
target_link_libraries(QJoysticks PUBLIC SDL2)
if(WIN32)
    target_compile_definitions(QJoysticks PUBLIC SDL_MAIN_HANDLED SDL_WIN)
    if(MINGW)
        target_link_directories(QJoysticks PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL/bin/windows/mingw/)
    endif()
    if(MSVC)
        if(CMAKE_SIZEOF_VOID_P EQUAL 8)
            target_link_directories(QJoysticks PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL/bin/windows/msvc/x64/)
        else()
            target_link_directories(QJoysticks PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL/bin/windows/msvc/x86/)
        endif()
    endif()
endif()


install(TARGETS QJoysticks
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    FRAMEWORK DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
