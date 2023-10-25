# limit cmakeminimum version 
cmake_minimum_required(VERSION 3.1)

# set global variable 
set(PREFIX "/usr/local" CACHE INTERNAL "linux usr")
set(BINDIR "${PREFIX}/bin" CACHE INTERNAL "linux bin")
set(SBINDIR "${PREFIX}/sbin" CACHE INTERNAL "linux sbin")
set(MANDIR "${PREFIX}/share/man" CACHE INTERNAL "linux man")
set(MAN3DIR "${MANDIR}/man3" CACHE INTERNAL "linux man3")
set(MAN8DIR "${MANDIR}/man8" CACHE INTERNAL "linux man8")
set(INCDIR "${PREFIX}/include" CACHE INTERNAL "linux include")
set(LIBDIR "${PREFIX}/lib" CACHE INTERNAL "linux lib")

# compile flags
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_C_FLAGS_DEBUG "-O2 -Wall -fpic -D_REENTRANT")

# add and build subdirectory
add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(eeprom)
add_subdirectory(stub)
add_subdirectory(tools)
add_subdirectory(eeprog)
# add_subdirectory(py-smbus)