# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/coderbug/esp/esp-idf/components/bootloader/subproject"
  "/home/coderbug/workspace/capstone/capstone-project-smartpillow/build/bootloader"
  "/home/coderbug/workspace/capstone/capstone-project-smartpillow/build/bootloader-prefix"
  "/home/coderbug/workspace/capstone/capstone-project-smartpillow/build/bootloader-prefix/tmp"
  "/home/coderbug/workspace/capstone/capstone-project-smartpillow/build/bootloader-prefix/src/bootloader-stamp"
  "/home/coderbug/workspace/capstone/capstone-project-smartpillow/build/bootloader-prefix/src"
  "/home/coderbug/workspace/capstone/capstone-project-smartpillow/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/coderbug/workspace/capstone/capstone-project-smartpillow/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/coderbug/workspace/capstone/capstone-project-smartpillow/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
