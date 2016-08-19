cmake_minimum_required (VERSION 2.8)
project (adc)

# important !!! export SYSTEMC and SYSTEMC_AMS

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-files)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -std=c++0x")

find_package(SystemC REQUIRED)
find_package(SystemCAMS REQUIRED)

include_directories(${SYSTEMC_INCLUDE_DIRS}
                    ${SYSTEMCAMS_INCLUDE_DIRS}
                    include
		    )

ADD_SUBDIRECTORY(src)
