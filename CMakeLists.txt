cmake_minimum_required(VERSION 3.5)

project(Qt_CustomControl LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories("${PROJECT_SOURCE_DIR}/src/Cat_Animation")
add_subdirectory(${PROJECT_SOURCE_DIR}/src/Cat_Animation Cat_Animation.out)
set(CATANIMATION ${CATANIMATION} Cat_Animation)

include_directories("${PROJECT_SOURCE_DIR}/src/Cat_Button")
add_subdirectory(${PROJECT_SOURCE_DIR}/src/Cat_Button Cat_Button.out)
set(CATBUTTON ${CATBUTTON} Cat_Button)

include_directories("${PROJECT_SOURCE_DIR}/src/Cat_ControlWidget")
add_subdirectory(${PROJECT_SOURCE_DIR}/src/Cat_ControlWidget Cat_ControlWidget.out)
set(CATCONTROLWIDGET ${CATCONTROLWIDGET} Cat_ControlWidget)

include_directories("${PROJECT_SOURCE_DIR}/src/Cat_InputGroup")
add_subdirectory(${PROJECT_SOURCE_DIR}/src/Cat_InputGroup Cat_InputGroup.out)
set(CATINPUTGROUP ${CATINPUTGROUP} Cat_InputGroup)

if(ANDROID)
  add_library(Qt_CustomControl SHARED
    main.cpp
    widget.cpp
    widget.h
    widget.ui
  )
else()
  add_executable(Qt_CustomControl
    main.cpp
    widget.cpp
    widget.h
    widget.ui
   )
endif()

target_link_libraries(Qt_CustomControl PRIVATE Qt5::Widgets)
target_link_libraries(Qt_CustomControl PRIVATE ${CATBUTTON})
target_link_libraries(Qt_CustomControl PRIVATE ${CATANIMATION})
target_link_libraries(Qt_CustomControl PRIVATE ${CATCONTROLWIDGET})
target_link_libraries(Qt_CustomControl PRIVATE ${CATINPUTGROUP})
