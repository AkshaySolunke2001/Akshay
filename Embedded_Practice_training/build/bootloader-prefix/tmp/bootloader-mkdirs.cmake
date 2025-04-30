# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/smartiam/esp/esp-idf-v5.1.4/components/bootloader/subproject"
  "/home/smartiam/Desktop/Akshay/Embedded_Practice_training/build/bootloader"
  "/home/smartiam/Desktop/Akshay/Embedded_Practice_training/build/bootloader-prefix"
  "/home/smartiam/Desktop/Akshay/Embedded_Practice_training/build/bootloader-prefix/tmp"
  "/home/smartiam/Desktop/Akshay/Embedded_Practice_training/build/bootloader-prefix/src/bootloader-stamp"
  "/home/smartiam/Desktop/Akshay/Embedded_Practice_training/build/bootloader-prefix/src"
  "/home/smartiam/Desktop/Akshay/Embedded_Practice_training/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/smartiam/Desktop/Akshay/Embedded_Practice_training/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/smartiam/Desktop/Akshay/Embedded_Practice_training/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
