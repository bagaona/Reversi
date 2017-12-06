<<<<<<< HEAD:cmake-build-debug/src/lib/google_tests/cmake_install.cmake
# Install script for directory: /home/amir/CLionProjects/Reversi/src/lib/google_tests
=======
# Install script for directory: /home/or/Reversi/lib/google_tests
>>>>>>> 456c8e050bc478252d3dbe28a005ef31db23c70b:cmake-build-debug/lib/google_tests/cmake_install.cmake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
<<<<<<< HEAD:cmake-build-debug/src/lib/google_tests/cmake_install.cmake
  include("/home/amir/CLionProjects/Reversi/cmake-build-debug/src/lib/google_tests/googlemock/cmake_install.cmake")
=======
  include("/home/or/Reversi/cmake-build-debug/lib/google_tests/googlemock/cmake_install.cmake")
>>>>>>> 456c8e050bc478252d3dbe28a005ef31db23c70b:cmake-build-debug/lib/google_tests/cmake_install.cmake

endif()

