# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "I:/ProgramFiles/ESP-IDF/esp-idf/components/bootloader/subproject"
  "I:/Projects/ESP-IDF/DemoKeylogger/build/bootloader"
  "I:/Projects/ESP-IDF/DemoKeylogger/build/bootloader-prefix"
  "I:/Projects/ESP-IDF/DemoKeylogger/build/bootloader-prefix/tmp"
  "I:/Projects/ESP-IDF/DemoKeylogger/build/bootloader-prefix/src/bootloader-stamp"
  "I:/Projects/ESP-IDF/DemoKeylogger/build/bootloader-prefix/src"
  "I:/Projects/ESP-IDF/DemoKeylogger/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "I:/Projects/ESP-IDF/DemoKeylogger/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "I:/Projects/ESP-IDF/DemoKeylogger/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
