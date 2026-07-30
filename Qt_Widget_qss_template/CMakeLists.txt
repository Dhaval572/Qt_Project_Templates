cmake_minimum_required(VERSION 3.19)
project(Qt_widgets LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

qt_add_executable(Qt_widgets
    main.cpp
    mainwindow.h mainwindow.cpp
    pch.h
    stylemanager.h stylemanager.cpp
    resources.qrc
)

target_precompile_headers(Qt_widgets PRIVATE pch.h)
target_link_libraries(Qt_widgets PRIVATE
        Qt::Core
        Qt::Widgets  
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(Qt_widgets PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -fsanitize=address
        -fno-omit-frame-pointer
    )

    target_link_options(Qt_widgets PRIVATE
        -fsanitize=address
    )
endif()

install(TARGETS Qt_widgets
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Qt_widgets
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
