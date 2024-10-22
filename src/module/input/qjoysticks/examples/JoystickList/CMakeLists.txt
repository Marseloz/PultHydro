cmake_minimum_required(VERSION 3.16)
project(JoystickList VERSION 1.0 LANGUAGES C CXX)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Qml Quick Widgets)

qt_standard_project_setup()

qt_add_executable(JoystickList WIN32 MACOSX_BUNDLE
    ../../src/QJoysticks.cpp ../../src/QJoysticks.h
    ../../src/QJoysticks/Android_Joystick.cpp ../../src/QJoysticks/Android_Joystick.h
    ../../src/QJoysticks/JoysticksCommon.h
    ../../src/QJoysticks/SDL_Joysticks.cpp ../../src/QJoysticks/SDL_Joysticks.h
    ../../src/QJoysticks/VirtualJoystick.cpp ../../src/QJoysticks/VirtualJoystick.h
    main.cpp
)
qt_add_qml_module(JoystickList
    URI JoystickList
    VERSION ${PROJECT_VERSION}
    QML_FILES
        main.qml
    NO_RESOURCE_TARGET_PATH
)

target_include_directories(JoystickList PRIVATE
    ../../lib/SDL/include
    ../../src
)

target_link_libraries(JoystickList PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
    Qt::Widgets
)


# Resources:
set(qjoysticks-res_resource_files
    "../../etc/resources/SDL/Database.txt"
    "../../etc/resources/SDL/GenericMappings/Linux.txt"
    "../../etc/resources/SDL/GenericMappings/OSX.txt"
    "../../etc/resources/SDL/GenericMappings/Windows.txt"
)

qt_add_resources(JoystickList "qjoysticks-res"
    PREFIX
        "/QJoysticks"
    BASE
        "../../etc/resources"
    FILES
        ${qjoysticks-res_resource_files}
)

if(win32_x_)
    target_compile_definitions(JoystickList PRIVATE
        SDL_MAIN_HANDLED
        SDL_WIN
    )
endif()

if((win32-msvc_x_) AND (QMAKE_TARGET.arch___contains___x86_64))
    target_link_libraries(JoystickList PRIVATE
        # Remove: L${CMAKE_CURRENT_SOURCE_DIR}/../../lib/SDL/bin/windows/msvc/x64/
        SDL2
    )
endif()

if((win32-msvc_x_) AND (NOT (QMAKE_TARGET.arch___contains___x86_64)))
    target_link_libraries(JoystickList PRIVATE
        # Remove: L${CMAKE_CURRENT_SOURCE_DIR}/../../lib/SDL/bin/windows/msvc/x86/
        SDL2
    )
endif()

if(macx_x_)
    target_link_libraries(JoystickList PRIVATE
        "-framework AudioToolbox"
        "-framework AudioUnit"
        "-framework Carbon"
        "-framework Cocoa"
        "-framework CoreAudio"
        "-framework CoreFoundation"
        "-framework CoreVideo"
        "-framework ForceFeedback"
        "-framework IOKit"
        "-framework OpenGL"
        # Remove: L${CMAKE_CURRENT_SOURCE_DIR}/../../lib/SDL/bin/mac-osx/
        SDL2
    )
endif()

if(LINUX)
    target_link_libraries(JoystickList PRIVATE
        SDL2
    )
endif()
