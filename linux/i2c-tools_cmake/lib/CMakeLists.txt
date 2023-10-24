# limit cmakeminimum version 
cmake_minimum_required(VERSION 3.1)

# include
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include/i2c)

# set version
set(LIB_MAINVER  0)
set(LIB_MINORVER 1.1)
set(LIB_VER ${LIB_MAINVER}.${LIB_MINORVER})

# compile lib
add_library(i2c_sh SHARED ${CMAKE_CURRENT_SOURCE_DIR}/../include/i2c/smbus.h ${CMAKE_CURRENT_SOURCE_DIR}/smbus.c)
target_compile_options(i2c_sh PRIVATE -Wstrict-prototypes -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -Wnested-externs -Winline -W -Wundef -Wmissing-prototypes -Iinclude)
set_target_properties(i2c_sh PROPERTIES OUTPUT_NAME "i2c")
target_link_libraries(i2c_sh PRIVATE -Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/libi2c.map -Wl,-soname,"libi2c.so.${LIB_MAINVER}" -lc)

add_custom_command(TARGET i2c_sh POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink "libi2c.so" "libi2c.so.${LIB_MAINVER}"
    COMMAND ${CMAKE_COMMAND} -E create_symlink "libi2c.so" "libi2c.so.${LIB_VER}")

add_library(i2c_st STATIC ${CMAKE_CURRENT_SOURCE_DIR}/smbus.c ${CMAKE_CURRENT_SOURCE_DIR}/../include/i2c/smbus.h)
target_compile_options(i2c_st PRIVATE -Wstrict-prototypes -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -Wnested-externs -Winline -W -Wundef -Wmissing-prototypes -Iinclude)
set_target_properties(i2c_st PROPERTIES OUTPUT_NAME "i2c")

# install
# todo...

# uninstall
# todo...