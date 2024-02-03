# Install script for directory: I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/DemoKeylogger")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "I:/ProgramFiles/ESP-IDF/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aes.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aria.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1write.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/base64.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/bignum.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/build_info.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/camellia.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ccm.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chacha20.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chachapoly.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/check_config.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cipher.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cmac.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/compat-2.x.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_psa.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/constant_time.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ctr_drbg.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/debug.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/des.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/dhm.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdh.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdsa.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecjpake.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecp.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/entropy.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/error.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/gcm.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hkdf.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hmac_drbg.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/legacy_or_psa.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/lms.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/mbedtls_config.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md5.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/memory_buffer_alloc.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/net_sockets.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/nist_kw.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/oid.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pem.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pk.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs12.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs5.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs7.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_time.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_util.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/poly1305.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/private_access.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/psa_util.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ripemd160.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/rsa.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha1.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha256.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha512.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cache.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ciphersuites.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cookie.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ticket.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/threading.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/timing.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/version.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crl.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crt.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_csr.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/psa" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_builtin_composites.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_builtin_primitives.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_compat.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_config.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_common.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_contexts_composites.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_contexts_primitives.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_extra.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_platform.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_se_driver.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_sizes.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_struct.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_types.h"
    "I:/ProgramFiles/ESP-IDF/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_values.h"
    )
endif()

