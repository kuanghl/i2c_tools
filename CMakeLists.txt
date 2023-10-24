# limit cmakeminimum version 
cmake_minimum_required(VERSION 3.1)

# project
project(i2c)
SET(CMAKE_C_FLAGS_RELEASE "-D_REETRANT -DNDEBUG -fcommon -fPIC -Wall -Wextra -pedantic -O3 -std=gnu99 -v")
SET(CMAKE_C_FLAGS_DEBUG "-D_REETRANT -g -fcommon -fPIC -Wall -Wextra -pedantic -O0 -v")
SET(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2")
SET(CMAKE_CXX_FLAGS_DEBUG "-g")

# add and build sub
add_subdirectory(linux)