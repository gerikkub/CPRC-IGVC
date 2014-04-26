# Install script for directory: /home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/src/beagle_pkg

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/install")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/beagle_pkg/msg" TYPE FILE FILES
    "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/src/beagle_pkg/msg/status.msg"
    "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/src/beagle_pkg/msg/imu_msg.msg"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/beagle_pkg/srv" TYPE FILE FILES
    "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/src/beagle_pkg/srv/dem.srv"
    "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/src/beagle_pkg/srv/ard.srv"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/beagle_pkg/cmake" TYPE FILE FILES "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/build/beagle_pkg/catkin_generated/installspace/beagle_pkg-msg-paths.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/devel/include/beagle_pkg")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/devel/share/common-lisp/ros/beagle_pkg")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/devel/lib/python2.7/dist-packages/beagle_pkg")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/devel/lib/python2.7/dist-packages/beagle_pkg")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/build/beagle_pkg/catkin_generated/installspace/beagle_pkg.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/beagle_pkg/cmake" TYPE FILE FILES "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/build/beagle_pkg/catkin_generated/installspace/beagle_pkg-msg-extras.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/beagle_pkg/cmake" TYPE FILE FILES
    "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/build/beagle_pkg/catkin_generated/installspace/beagle_pkgConfig.cmake"
    "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/build/beagle_pkg/catkin_generated/installspace/beagle_pkgConfig-version.cmake"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/beagle_pkg" TYPE FILE FILES "/home/daschulz/igvcCode/CPRC-IGVC/Code/Software Implementation/RosIntegration/rosWksp/src/beagle_pkg/package.xml")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

