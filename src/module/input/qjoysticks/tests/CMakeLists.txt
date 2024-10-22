cmake_minimum_required(VERSION 3.16)
project(QJoysticks_Test VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Test Widgets)

qt_standard_project_setup()

qt_add_executable(QJoysticks_Test WIN32 MACOSX_BUNDLE
    .././src/QJoysticks.cpp .././src/QJoysticks.h
    .././src/QJoysticks/Android_Joystick.cpp .././src/QJoysticks/Android_Joystick.h
    .././src/QJoysticks/JoysticksCommon.h
    .././src/QJoysticks/SDL_Joysticks.cpp .././src/QJoysticks/SDL_Joysticks.h
    .././src/QJoysticks/VirtualJoystick.cpp .././src/QJoysticks/VirtualJoystick.h
    Test_QJoysticks.h
    main.cpp
)
target_include_directories(QJoysticks_Test PRIVATE
    .././src
    ../lib/SDL/include
)

target_link_libraries(QJoysticks_Test PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Test
    Qt::Widgets
)


# Resources:
set(qjoysticks-res_resource_files
    ".././etc/resources/SDL/Database.txt"
    ".././etc/resources/SDL/GenericMappings/Linux.txt"
    ".././etc/resources/SDL/GenericMappings/OSX.txt"
    ".././etc/resources/SDL/GenericMappings/Windows.txt"
)

qt_add_resources(QJoysticks_Test "qjoysticks-res"
    PREFIX
        "/QJoysticks"
    BASE
        ".././etc/resources"
    FILES
        ${qjoysticks-res_resource_files}
)

if(NOT ANDROID)
    target_compile_definitions(QJoysticks_Test PRIVATE
        SDL_SUPPORTED
    )
endif()

if(win32_x_)
    target_compile_definitions(QJoysticks_Test PRIVATE
        SDL_MAIN_HANDLED
        SDL_WIN
    )
endif()

if(_x_ + win32-g)
    target_link_libraries(QJoysticks_Test PRIVATE
        # Remove: L${CMAKE_CURRENT_SOURCE_DIR}/../lib/SDL/bin/windows/mingw/
        SDL2
    )
endif()

if((win32-msvc_x_) AND (QMAKE_TARGET.arch___contains___x86_64))
    target_link_libraries(QJoysticks_Test PRIVATE
        # Remove: L${CMAKE_CURRENT_SOURCE_DIR}/../lib/SDL/bin/windows/msvc/x64/
        SDL2
    )
endif()

if((win32-msvc_x_) AND (NOT (QMAKE_TARGET.arch___contains___x86_64)))
    target_link_libraries(QJoysticks_Test PRIVATE
        # Remove: L${CMAKE_CURRENT_SOURCE_DIR}/../lib/SDL/bin/windows/msvc/x86/
        SDL2
    )
endif()

if(macx_x_)
    target_link_libraries(QJoysticks_Test PRIVATE
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
        # Remove: L${CMAKE_CURRENT_SOURCE_DIR}/../lib/SDL/bin/mac-osx/
        SDL2
    )
endif()

if(LINUX)
    target_link_libraries(QJoysticks_Test PRIVATE
        SDL2
    )
endif()

install(TARGETS QJoysticks_Test
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET QJoysticks_Test
    FILENAME_VARIABLE deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
