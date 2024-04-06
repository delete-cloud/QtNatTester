cmake_minimum_required(VERSION 3.5)

project(NatTypeTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#if (MSVC)
#    set(CMAKE_PREFIX_PATH "G:/Qt/6.6.2/msvc2019_64")
#    message(STATUS ${CMAKE_PREFIX_PATH})
##    find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Widgets PATHS "G:/Qt/6.6.2/msvc2019_64" NO_DEFAULT_PATH)
##    find_package(QT${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core PATHS "G:/Qt/6.6.2/msvc2019_64" NO_DEFAULT_PATH)
#endif()

#set(QT_VERSION_MAJOR 6)
#find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Widgets PATHS "G:/Qt/6.6.2/msvc2019_64" NO_DEFAULT_PATH)
#find_package(QT${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core PATHS "G:/Qt/6.6.2/msvc2019_64" NO_DEFAULT_PATH)
find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core)

set(PROJECT_SOURCES
        main.cc
        mainwindow.cc
        mainwindow.h
        mainwindow.ui
        nat_detect.h
        nat_detect.cc
        nat_detect_thread.cc
        nat_detect_thread.h
)

if(APPLE)
    set(MACOSX_BUNDLE_ICON_FILE icon.icns)
    set(APP_ICON_MACOSX ${CMAKE_CURRENT_SOURCE_DIR}/resources/icon.icns)
    set_source_files_properties(${APP_ICON_MACOSX} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

    find_package(PkgConfig REQUIRED)
    pkg_check_modules(PJSIP REQUIRED libpjproject)
    include_directories(${PJSIP_INCLUDE_DIRS})
elseif(MSVC)
        set(PJSIP_INCLUDE_DIRS "./dependencies/include")
        set(PJSIP_LIBRARY_DIRS "./dependencies/lib/windows/x64")
        set(PJSIP_LIBRARIES
                "libg7221codec-x86_64-x64-vc14-Release.lib"
                "libgsmcodec-x86_64-x64-vc14-Release.lib"
                "libilbccodec-x86_64-x64-vc14-Release.lib"
                "libpjproject-x86_64-x64-vc14-Release.lib"
                "libresample-x86_64-x64-vc14-Release.lib"
                "libspeex-x86_64-x64-vc14-Release.lib"
                "libsrtp-x86_64-x64-vc14-Release.lib"
                "libwebrtc-x86_64-x64-vc14-Release.lib"
                "libyuv-x86_64-x64-vc14-Release.lib"
                "pjlib-util-x86_64-x64-vc14-Release.lib"
                "pjlib-x86_64-x64-vc14-Release.lib"
                "pjmedia-audiodev-x86_64-x64-vc14-Release.lib"
                "pjmedia-codec-x86_64-x64-vc14-Release.lib"
                "pjmedia-videodev-x86_64-x64-vc14-Release.lib"
                "pjmedia-x86_64-x64-vc14-Release.lib"
                "pjnath-x86_64-x64-vc14-Release.lib"
                "pjsip-core-x86_64-x64-vc14-Release.lib"
                "pjsip-simple-x86_64-x64-vc14-Release.lib"
                "pjsip-ua-x86_64-x64-vc14-Release.lib"
                "pjsua-lib-x86_64-x64-vc14-Release.lib"
                "pjsua2-lib-x86_64-x64-vc14-Release.lib"
        )
        include_directories(${PJSIP_INCLUDE_DIRS})
        link_directories(${PJSIP_LIBRARY_DIRS})
    endif()


if(MSVC)
    add_compile_options(/Zc:__cplusplus)
    add_compile_options(/permissive-)
endif()

MESSAGE(STATUS "PJSIP_LIBRARIES: ${PJSIP_LIBRARIES}")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(NatTypeTest
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            ${APP_ICON_MACOSX}
    )
else()
    if(ANDROID)
        add_library(NatTypeTest SHARED
                ${PROJECT_SOURCES}
        )
    else()
        add_executable(NatTypeTest
                ${PROJECT_SOURCES}
                ${APP_ICON_MACOSX}
        )
    endif()
endif()

if (MSVC)
    target_link_libraries(NatTypeTest PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${PJSIP_LIBRARIES} Ws2_32)
else ()
    target_link_libraries(NatTypeTest PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${PJSIP_LIBRARIES})
endif ()

if(APPLE)
    set_target_properties(NatTypeTest PROPERTIES
            MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
            MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
            MACOSX_BUNDLE TRUE
            WIN32_EXECUTABLE TRUE
    )
    if(${QT_VERSION_MAJOR} VERSION_LESS 6 OR (${QT_VERSION_MAJOR} EQUAL 6 AND ${QT_VERSION_MINOR} LESS 1))
        set_target_properties(NatTypeTest PROPERTIES
                MACOSX_BUNDLE_GUI_IDENTIFIER com.example.NatTypeTest
                MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in
        )
    endif()
elseif(WIN32)
    set_target_properties(NatTypeTest PROPERTIES
            WIN32_EXECUTABLE TRUE
    )
endif()

include(GNUInstallDirs)
install(TARGETS NatTypeTest
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(NatTypeTest)
endif()
