# Install script for directory: E:/Users/mobut/Documents/testcmake/src/module/gui/front/moduls

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/testc")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("E:/Users/mobut/Documents/testcmake/build/Desktop_Qt_6_7_2_MSVC2019_64bit-RelWithDebInfo/src/module/gui/front/moduls/Attitude/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("E:/Users/mobut/Documents/testcmake/build/Desktop_Qt_6_7_2_MSVC2019_64bit-RelWithDebInfo/src/module/gui/front/moduls/Compass/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("E:/Users/mobut/Documents/testcmake/build/Desktop_Qt_6_7_2_MSVC2019_64bit-RelWithDebInfo/src/module/gui/front/moduls/Depth/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("E:/Users/mobut/Documents/testcmake/build/Desktop_Qt_6_7_2_MSVC2019_64bit-RelWithDebInfo/src/module/gui/front/moduls/Direction/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("E:/Users/mobut/Documents/testcmake/build/Desktop_Qt_6_7_2_MSVC2019_64bit-RelWithDebInfo/src/module/gui/front/moduls/Force/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("E:/Users/mobut/Documents/testcmake/build/Desktop_Qt_6_7_2_MSVC2019_64bit-RelWithDebInfo/src/module/gui/front/moduls/Rpd/cmake_install.cmake")
endif()

