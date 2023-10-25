# limit cmakeminimum version 
cmake_minimum_required(VERSION 3.1)

# include
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include/i2c)

# compile execution
add_executable(eeprog   ${CMAKE_CURRENT_SOURCE_DIR}/eeprog.c 
                        ${CMAKE_CURRENT_SOURCE_DIR}/24cXX.c 
                        ${CMAKE_CURRENT_SOURCE_DIR}/24cXX.h
                        ${CMAKE_CURRENT_SOURCE_DIR}/../include/i2c/smbus.h)
target_compile_options(eeprog PRIVATE -Iinclude)
# target_link_libraries(eeprog PRIVATE -li2c -L${CMAKE_CURRENT_BINARY_DIR}/../lib/libi2c.so.0.1.1)
target_link_libraries(eeprog PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/../lib/libi2c.a)

# OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE 755
# OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ 644
# install
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/eeprog
        DESTINATION "${SBINDIR}"
        PERMISSIONS OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/eeprog.8 
        DESTINATION "${MAN8DIR}"
        PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ)

# uninstall
# todo...