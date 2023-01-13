# this is required
SET(CMAKE_SYSTEM_NAME Linux)

# specify the cross compiler
set(CROSS_COMPILE_ROOT /usr/local/raspberrypi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/)

set(CMAKE_C_COMPILER ${CROSS_COMPILE_ROOT}arm-linux-gnueabihf-gcc)
set(CMAKE_C_COMPILER_AR ${CROSS_COMPILE_ROOT}arm-linux-gnueabihf-ar)
set(CMAKE_C_COMPILER_RANLIB ${CROSS_COMPILE_ROOT}arm-linux-gnueabihf-ranlib)
set(CMAKE_CXX_COMPILER ${CROSS_COMPILE_ROOT}arm-linux-gnueabihf-g++)


# specify install path
#c
set(CMAKE_INSTALL_PREFIX /usr/local/raspberrypi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/arm-linux-gnueabihf/libc/usr)

#curl
set(CURL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include)
set(CURL_LIBRARY ${CMAKE_INSTALL_PREFIX}/lib/libcurl.so)
#openssl crypto
set(OPENSSL_CRYPTO_LIBRARY ${CMAKE_INSTALL_PREFIX}/lib/libcrypto.so)

#openssl ssl
set(OPENSSL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include)
set(OPENSSL_SSL_LIBRARY ${CMAKE_INSTALL_PREFIX}/lib/libssl.so)


#c++
#set(CMAKE_INSTALL_PREFIX ${CROSS_COMPILE_ROOT}../arm-linux-gnueabihf/)
# where is the target environment 
SET(CMAKE_FIND_ROOT_PATH  ${CROSS_COMPILE_ROOT}../arm-linux-gnueabihf)

# search for programs in the build host directories (not necessary)
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# configure Boost and Qt
#SET(QT_QMAKE_EXECUTABLE /opt/qt-embedded/qmake)
#SET(BOOST_ROOT /opt/boost_arm)

