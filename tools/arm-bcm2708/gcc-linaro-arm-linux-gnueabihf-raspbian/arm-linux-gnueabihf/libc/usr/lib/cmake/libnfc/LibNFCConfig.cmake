#                                               -*- cmake -*-


# Use the following variables to compile and link against LibNFC:
#  LIBNFC_FOUND              - True if LibNFC was found on your system
#  LIBNFC_USE_FILE           - The file making LibNFC usable
#  LIBNFC_DEFINITIONS        - Definitions needed to build with LibNFC
#  LIBNFC_INCLUDE_DIR        - Directory where nfc/nfc.h can be found
#  LIBNFC_INCLUDE_DIRS       - List of directories of LibNFC and it's dependencies
#  LIBNFC_LIBRARY            - LibNFC library location
#  LIBNFC_LIBRARIES          - List of libraries to link against LibNFC library
#  LIBNFC_LIBRARY_DIRS       - List of directories containing LibNFC' libraries
#  LIBNFC_ROOT_DIR           - The base directory of LibNFC
#  LIBNFC_VERSION_STRING     - A human-readable string containing the version
#  LIBNFC_VERSION_MAJOR      - The major version of LibNFC
#  LIBNFC_VERSION_MINOR      - The minor version of LibNFC
#  LIBNFC_VERSION_PATCH      - The patch version of LibNFC

set ( LIBNFC_FOUND 1 )
set ( LIBNFC_USE_FILE     "/usr/local/raspberrypi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/lib/cmake/libnfc/UseLibNFC.cmake" )

set ( LIBNFC_DEFINITIONS  "" )
set ( LIBNFC_INCLUDE_DIR  "/usr/local/raspberrypi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/include" )
set ( LIBNFC_INCLUDE_DIRS "/usr/local/raspberrypi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/include" )
set ( LIBNFC_LIBRARY      "nfc" )
set ( LIBNFC_LIBRARIES    "nfc;usb" )
set ( LIBNFC_LIBRARY_DIRS "/usr/local/raspberrypi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr/lib" )
set ( LIBNFC_ROOT_DIR     "/usr/local/raspberrypi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr" )

set ( LIBNFC_VERSION_STRING "1.8.0" )
set ( LIBNFC_VERSION_MAJOR  "1" )
set ( LIBNFC_VERSION_MINOR  "8" )
set ( LIBNFC_VERSION_PATCH  "0" )

