#
# Set expected CMAKE version
#
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

#
# Disbale in-source builds
#
if (${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory)
    and run CMake from there. You may need to remove CMakeCache.txt and CMakeFiles folder.")
endif ()

#
# Define BUILD version
#
set(VERSION_MAJOR "2019")
set(VERSION_MINOR "0611")
set(VERSION_PATCH "01")
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

#
# Set naming variables
#
set(ROOT_PROJ kcf_multiscale_multifeature)

#
# Setup compiler projects
#
project(${ROOT_PROJ} LANGUAGES CXX)

#
# Set DIR information
#
set(USR_NAME root)
set(DIR_HOME /opt/repos)
set(DEVELOPMENT ON)

if (DEVELOPMENT)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEVELOPMENT")
endif()

#
#  Set CXX Standard
#
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required..

#
# Set required compiler locations
#
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/archive)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#
# Set CMAKE build settings
#
set(CMAKE_VERBOSE_MAKEFILE true)

#
# Including threading
#
find_package(Threads REQUIRED)

#
# Set extra compiler flags
#
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wl,--no-as-needed -ldl -lz")

#
#  3rd Party Header directories
#
include_directories(/usr/local/include)
include_directories(/usr/include)
include_directories(/usr/local/include/opencv4)

#
#  3rd Party Shared Libraries
#
link_directories(/usr/local/lib)
link_directories(/usr/lib)

set(MAIN_SOURCES
        src/main.cpp src/tracker.h src/fftutils.h src/gradient.cpp src/gradient.h src/sse.h src/gradientutils.h)

#
# Add all CPP Object files
#
add_executable(${ROOT_PROJ}
        ${MAIN_SOURCES})

# Link 3rd Party Libraries
target_link_libraries(${ROOT_PROJ} PUBLIC glog)
target_link_libraries(${ROOT_PROJ} PUBLIC libopencv_core.so libopencv_highgui.so libopencv_videoio.so
        libopencv_video.so libopencv_imgcodecs.so libopencv_imgproc.so)