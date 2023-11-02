# limit cmakeminimum version 
cmake_minimum_required(VERSION 3.1)

# project
project(i2c)

# add and build sub
if(UNIX)
    add_subdirectory(linux)
elseif(WIN32)
    add_subdirectory(windows)
endif()