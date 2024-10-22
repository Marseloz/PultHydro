cmake_minimum_required(VERSION 3.25)

project(testc LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

#рекомендация от KDAB
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#рекомендация от KDAB

find_package(Qt6 6.7 COMPONENTS Gui Multimedia Core Quick Widgets Test REQUIRED)

add_subdirectory(src/module/connect)
add_subdirectory(src/module/gui)
add_subdirectory(src/module/input)
add_subdirectory(src/module/setting)

#[[get_property(my_library_type TARGET QJoysticks PROPERTY TYPE)
get_property(my_library_sources TARGET QJoysticks PROPERTY SOURCES)
get_property(my_library_include_directories TARGET QJoysticks PROPERTY INCLUDE_DIRECTORIES)
message(AUTHOR_WARNING "--- TYPE --- ${my_library_type}")
message(AUTHOR_WARNING "--- SOURCES --- ${my_library_sources}")
message(AUTHOR_WARNING "--- INCLUDE_DIRECTORIES --- ${my_library_include_directories}")
message(AUTHOR_WARNING "--- QJoysticks --- ${Qt6::Quick}")]]

qt_add_executable(${PROJECT_NAME}
  src/main.cpp
  src/core.cpp
  src/core.h
)

# qt_add_qml_module(${PROJECT_NAME}
    # URI test
    # VERSION 1.0
    # RESOURCES main.qml
# )

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt6::Gui
    Qt6::Widgets
    Qt6::Multimedia
    Qt6::Core
    Qt6::Quick
    Qt6::Test
    Connect
    GUI
    LoadSetting
    JControl
)

function(SETUP_TESTS) #функция для упрощения составления cmake файла для тестов
       foreach(_testname ${ARGN})
           add_executable(${_testname} src/${_testname}.cpp )
           add_test(NAME ${_testname} COMMAND ${_testname})
           target_link_libraries(${_testname}
               Qt6::Gui
               Qt6::Widgets
               Qt6::Multimedia
               Qt6::Core
               Qt6::Quick
               Qt6::Test
               Connect
               GUI
               LoadSetting
               JControl
           )
       endforeach()
endfunction()

add_subdirectory(tests)
