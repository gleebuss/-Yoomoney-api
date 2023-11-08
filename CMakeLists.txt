if(WIN32)
    if (EXISTS $ENV{APPDATA}/../Local/vcpkg/vcpkg.path.txt)
        set(FILE $ENV{APPDATA}/../Local/vcpkg/vcpkg.path.txt)
        file(READ ${FILE} FILE_CONTENTS)
        set(CMAKE_TOOLCHAIN_FILE ${FILE_CONTENTS}/scripts/buildsystems/vcpkg.cmake)
    else()
        set(FILE $ENV{LOCALAPPDATA}/vcpkg/vcpkg.path.txt)
        file(READ ${FILE} FILE_CONTENTS)
        set(CMAKE_TOOLCHAIN_FILE ${FILE_CONTENTS}/scripts/buildsystems/vcpkg.cmake)
    endif()
else()
    if (EXISTS $ENV{HOME}/.vcpkg/vcpkg.path.txt)
        set(FILE $ENV{HOME}/.vcpkg/vcpkg.path.txt)
        file(READ ${FILE} FILE_CONTENTS)
        set(CMAKE_TOOLCHAIN_FILE ${FILE_CONTENTS}/scripts/buildsystems/vcpkg.cmake)
    else()
        set(FILE /var/.vcpkg/vcpkg.path.txt)
        file(READ ${FILE} FILE_CONTENTS)
        set(CMAKE_TOOLCHAIN_FILE ${FILE_CONTENTS}/scripts/buildsystems/vcpkg.cmake)
    endif()
endif()

cmake_minimum_required(VERSION 3.21)
project(Yoomoney)

#message(FATAL_ERROR ${CMAKE_TOOLCHAIN_FILE})
#C:/Users/-_-/vcpkg/scripts/buildsystems/vcpkg.cmake
set(CMAKE_CXX_STANDARD 17)
# set(BUILD_SHARED_LIBS ON)
set(SOURCE_DIR "API/src")
set(INCLUDE_DIR "API/include")
set(DEP_DIR "API/include/dependencies")
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${SOURCE_DIR}/*.cpp")
include(GNUInstallDirs)

find_package(Doxygen REQUIRED)
find_package(cpr REQUIRED)

add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/API/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

target_link_libraries(${PROJECT_NAME} PUBLIC cpr::cpr)

# add_subdirectory(examples)

if(DOXYGEN_FOUND)
    set(DOXYGEN_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    add_custom_target(
            documentation
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_INPUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM
    )
endif()

install(TARGETS ${PROJECT_NAME} EXPORT YoomoneyConfig
        ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME  DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY API/include DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
install(EXPORT YoomoneyConfig DESTINATION share/Yoomoney/cmake)
export(TARGETS ${PROJECT_NAME} FILE YoomoneyConfig.cmake)