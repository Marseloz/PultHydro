# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles\\testc_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\testc_autogen.dir\\ParseCache.txt"
  "src\\module\\connect\\CMakeFiles\\Connect_autogen.dir\\AutogenUsed.txt"
  "src\\module\\connect\\CMakeFiles\\Connect_autogen.dir\\ParseCache.txt"
  "src\\module\\connect\\Connect_autogen"
  "src\\module\\gui\\CMakeFiles\\GUI_autogen.dir\\AutogenUsed.txt"
  "src\\module\\gui\\CMakeFiles\\GUI_autogen.dir\\ParseCache.txt"
  "src\\module\\gui\\GUI_autogen"
  "src\\module\\input\\CMakeFiles\\JControl_autogen.dir\\AutogenUsed.txt"
  "src\\module\\input\\CMakeFiles\\JControl_autogen.dir\\ParseCache.txt"
  "src\\module\\input\\JControl_autogen"
  "src\\module\\input\\qjoysticks\\CMakeFiles\\QJoysticks_autogen.dir\\AutogenUsed.txt"
  "src\\module\\input\\qjoysticks\\CMakeFiles\\QJoysticks_autogen.dir\\ParseCache.txt"
  "src\\module\\input\\qjoysticks\\QJoysticks_autogen"
  "src\\module\\setting\\CMakeFiles\\LoadSetting_autogen.dir\\AutogenUsed.txt"
  "src\\module\\setting\\CMakeFiles\\LoadSetting_autogen.dir\\ParseCache.txt"
  "src\\module\\setting\\LoadSetting_autogen"
  "testc_autogen"
  "tests\\CMakeFiles\\testconnect_autogen.dir\\AutogenUsed.txt"
  "tests\\CMakeFiles\\testconnect_autogen.dir\\ParseCache.txt"
  "tests\\CMakeFiles\\testsettingmod_autogen.dir\\AutogenUsed.txt"
  "tests\\CMakeFiles\\testsettingmod_autogen.dir\\ParseCache.txt"
  "tests\\testconnect_autogen"
  "tests\\testsettingmod_autogen"
  )
endif()
