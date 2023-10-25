# limit cmakeminimum version 
cmake_minimum_required(VERSION 3.1)

# include
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include/i2c)

# compile execution
add_executable(i2cdetect    ${CMAKE_CURRENT_SOURCE_DIR}/i2cdetect.c 
                            ${CMAKE_CURRENT_SOURCE_DIR}/i2cbusses.c 
                            ${CMAKE_CURRENT_SOURCE_DIR}/i2cbusses.h
                            ${CMAKE_CURRENT_SOURCE_DIR}/../version.h
                            ${CMAKE_CURRENT_SOURCE_DIR}/../include/i2c/smbus.h)
target_compile_options(i2cdetect PRIVATE    -Wstrict-prototypes -Wshadow -Wpointer-arith -Wcast-qual
                                            -Wcast-align -Wwrite-strings -Wnested-externs -Winline
                                            -W -Wundef -Wmissing-prototypes -Iinclude)
# target_link_libraries(i2cdetect PRIVATE -li2c -L${CMAKE_CURRENT_BINARY_DIR}/../lib/libi2c.so.0.1.1)
target_link_libraries(i2cdetect PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/../lib/libi2c.a)

add_executable(i2cdump  ${CMAKE_CURRENT_SOURCE_DIR}/i2cdump.c 
                        ${CMAKE_CURRENT_SOURCE_DIR}/i2cbusses.c 
                        ${CMAKE_CURRENT_SOURCE_DIR}/i2cbusses.h
                        ${CMAKE_CURRENT_SOURCE_DIR}/util.c 
                        ${CMAKE_CURRENT_SOURCE_DIR}/util.h
                        ${CMAKE_CURRENT_SOURCE_DIR}/../version.h
                        ${CMAKE_CURRENT_SOURCE_DIR}/../include/i2c/smbus.h)
target_compile_options(i2cdump PRIVATE  -Wstrict-prototypes -Wshadow -Wpointer-arith -Wcast-qual
                                        -Wcast-align -Wwrite-strings -Wnested-externs -Winline
                                        -W -Wundef -Wmissing-prototypes -Iinclude)
target_link_libraries(i2cdump PRIVATE -li2c -L${CMAKE_CURRENT_BINARY_DIR}/../lib/libi2c.so.0.1.1)
# target_link_libraries(i2cdump PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/../lib/libi2c.a)

add_executable(i2cset   ${CMAKE_CURRENT_SOURCE_DIR}/i2cset.c 
                        ${CMAKE_CURRENT_SOURCE_DIR}/i2cbusses.c 
                        ${CMAKE_CURRENT_SOURCE_DIR}/i2cbusses.h
                        ${CMAKE_CURRENT_SOURCE_DIR}/util.c 
                        ${CMAKE_CURRENT_SOURCE_DIR}/util.h
                        ${CMAKE_CURRENT_SOURCE_DIR}/../version.h
                        ${CMAKE_CURRENT_SOURCE_DIR}/../include/i2c/smbus.h)
target_compile_options(i2cset PRIVATE   -Wstrict-prototypes -Wshadow -Wpointer-arith -Wcast-qual
                                        -Wcast-align -Wwrite-strings -Wnested-externs -Winline
                                        -W -Wundef -Wmissing-prototypes -Iinclude)
target_link_libraries(i2cset PRIVATE -li2c -L${CMAKE_CURRENT_BINARY_DIR}/../lib/libi2c.so.0.1.1)
# target_link_libraries(i2cset PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/../lib/libi2c.a)


add_executable(i2cget   ${CMAKE_CURRENT_SOURCE_DIR}/i2cget.c 
                        ${CMAKE_CURRENT_SOURCE_DIR}/i2cbusses.c 
                        ${CMAKE_CURRENT_SOURCE_DIR}/i2cbusses.h
                        ${CMAKE_CURRENT_SOURCE_DIR}/util.c 
                        ${CMAKE_CURRENT_SOURCE_DIR}/util.h
                        ${CMAKE_CURRENT_SOURCE_DIR}/../version.h
                        ${CMAKE_CURRENT_SOURCE_DIR}/../include/i2c/smbus.h)
target_compile_options(i2cget PRIVATE   -Wstrict-prototypes -Wshadow -Wpointer-arith -Wcast-qual
                                        -Wcast-align -Wwrite-strings -Wnested-externs -Winline
                                        -W -Wundef -Wmissing-prototypes -Iinclude)
target_link_libraries(i2cget PRIVATE -li2c -L${CMAKE_CURRENT_BINARY_DIR}/../lib/libi2c.so.0.1.1)
# target_link_libraries(i2cget PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/../lib/libi2c.a)


add_executable(i2ctransfer  ${CMAKE_CURRENT_SOURCE_DIR}/i2ctransfer.c 
                            ${CMAKE_CURRENT_SOURCE_DIR}/i2cbusses.c 
                            ${CMAKE_CURRENT_SOURCE_DIR}/i2cbusses.h
                            ${CMAKE_CURRENT_SOURCE_DIR}/util.c 
                            ${CMAKE_CURRENT_SOURCE_DIR}/util.h
                            ${CMAKE_CURRENT_SOURCE_DIR}/../version.h
                            ${CMAKE_CURRENT_SOURCE_DIR}/../include/i2c/smbus.h)
target_compile_options(i2ctransfer PRIVATE  -Wstrict-prototypes -Wshadow -Wpointer-arith -Wcast-qual
                                            -Wcast-align -Wwrite-strings -Wnested-externs -Winline
                                            -W -Wundef -Wmissing-prototypes -Iinclude)
target_link_libraries(i2ctransfer PRIVATE -li2c -L${CMAKE_CURRENT_BINARY_DIR}/../lib/libi2c.so.0.1.1)
# target_link_libraries(i2ctransfer PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/../lib/libi2c.a)

# OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE 755
# OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ 644
# install
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/i2cdetect ${CMAKE_CURRENT_BINARY_DIR}/i2cdump ${CMAKE_CURRENT_BINARY_DIR}/i2cset ${CMAKE_CURRENT_BINARY_DIR}/i2cget ${CMAKE_CURRENT_BINARY_DIR}/i2ctransfer
        DESTINATION "${SBINDIR}"
        PERMISSIONS OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/i2cdetect.8 ${CMAKE_CURRENT_SOURCE_DIR}/i2cdump.8 ${CMAKE_CURRENT_SOURCE_DIR}/i2cset.8 ${CMAKE_CURRENT_SOURCE_DIR}/i2cget.8 ${CMAKE_CURRENT_SOURCE_DIR}/i2ctransfer.8
        DESTINATION "${MAN8DIR}"
        PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ)

# uninstall
# todo...