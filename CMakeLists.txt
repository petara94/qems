cmake_minimum_required(VERSION 3.5)

project(qems VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE)
    set(CMAKE_PREFIX_PATH "/Users/user/Qt/6.3.1/macos")
elseif (UNIX)
    set(CMAKE_PREFIX_PATH "/opt/Qt/6.3.2/gcc_64")
endif ()    


set(PROJECT_SOURCES
        main.cpp
        qems.cpp
        qems.h
        qems.ui
        icons.qrc
        elemitem/elemitem.h elemitem/elemitem.cpp
        render/glrender.h render/glrender.cpp
        g_items/emsitem.h g_items/emsitem.cpp
        g_items/editorview.h g_items/editorview.cpp
        )

add_executable(qems ${PROJECT_SOURCES})

find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGL OpenGLWidgets)
qt_standard_project_setup()

if (WIN32)
    find_package(OpenGL REQUIRED)
    include_directories(${OPENGL_INCLUDE_DIRS})
    target_link_libraries(qems PRIVATE Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets ${OPENGL_LIBRARIES})
else ()
    target_link_libraries(qems PRIVATE Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets)
endif ()


set_target_properties(qems PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

install(TARGETS qems
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(qems)
endif ()
