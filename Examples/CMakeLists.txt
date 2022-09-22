cmake_minimum_required(VERSION 3.10)

project(qtProject)

if(WIN32)
    set(QT_DIR "C:\\DevTools\\Qt\\5.15.2\\mingw81_64\\lib\\cmake\\Qt5")
    set(QT_QPA_PLATFORM_PLUGIN_PATH "C:\\DevTools\\Qt\\5.15.2\\mingw81_64\\plugins\\platforms")
    set(QT_PLUGIN_PATH "C:\\DevTools\\Qt\\5.15.2\\mingw81_64\\plugins")
else()
    set(QT_DIR "/opt/Qt/5.15.2/gcc_64/lib/cmake/Qt5")
    set(QT_QPA_PLATFORM_PLUGIN_PATH "/opt/Qt/5.15.2/gcc_64/plugins/platforms")
    set(QT_PLUGIN_PATH "/opt/Qt/5.15.2/gcc_64/plugins")
endif()

set(QT_DEBUG_PLUGINS 1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "src/*.h")
file(GLOB_RECURSE RESOURCE_FILES "resource/*.qrc")
file(GLOB_RECURSE QML_FILES "qml/*.qml")

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${QT_DIR})
find_package(Qt5 COMPONENTS
        Core
        Quick
        QuickWidgets
        Widgets
        Gui
        Svg
        Xml
        LinguistTools
        QuickControls2
        WebChannel
        3DCore 3DExtras 3DRender 3DInput
        REQUIRED)

add_executable(${PROJECT_NAME}
        ${SOURCE_FILES}
        ${HEADER_FILES}
        ${RESOURCE_FILES}
        ${QML_FILES}
        )

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Qml
        Qt5::Quick
        Qt5::QuickWidgets
        Qt5::Xml
        Qt5::Svg
        Qt5::3DCore
        Qt5::3DExtras
        Qt5::3DRender
        Qt5::3DInput
        )
