# limit cmakeminimum version 
cmake_minimum_required(VERSION 3.1)

# OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE 755
# OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ 644
# install
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/i2c/smbus.h" 
        DESTINATION "${INCDIR}/i2c"
        PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ)

# uninstall
# todo...