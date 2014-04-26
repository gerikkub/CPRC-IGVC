# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "beagle_pkg: 1 messages, 2 services")

set(MSG_I_FLAGS "-Ibeagle_pkg:/home/daschulz/IGVC/beagleWksp/src/beagle_pkg/msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(beagle_pkg_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(beagle_pkg
  "/home/daschulz/IGVC/beagleWksp/src/beagle_pkg/msg/status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/beagle_pkg
)

### Generating Services
_generate_srv_cpp(beagle_pkg
  "/home/daschulz/IGVC/beagleWksp/src/beagle_pkg/srv/dem.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/beagle_pkg
)
_generate_srv_cpp(beagle_pkg
  "/home/daschulz/IGVC/beagleWksp/src/beagle_pkg/srv/ard.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/beagle_pkg
)

### Generating Module File
_generate_module_cpp(beagle_pkg
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/beagle_pkg
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(beagle_pkg_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(beagle_pkg_generate_messages beagle_pkg_generate_messages_cpp)

# target for backward compatibility
add_custom_target(beagle_pkg_gencpp)
add_dependencies(beagle_pkg_gencpp beagle_pkg_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS beagle_pkg_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(beagle_pkg
  "/home/daschulz/IGVC/beagleWksp/src/beagle_pkg/msg/status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/beagle_pkg
)

### Generating Services
_generate_srv_lisp(beagle_pkg
  "/home/daschulz/IGVC/beagleWksp/src/beagle_pkg/srv/dem.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/beagle_pkg
)
_generate_srv_lisp(beagle_pkg
  "/home/daschulz/IGVC/beagleWksp/src/beagle_pkg/srv/ard.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/beagle_pkg
)

### Generating Module File
_generate_module_lisp(beagle_pkg
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/beagle_pkg
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(beagle_pkg_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(beagle_pkg_generate_messages beagle_pkg_generate_messages_lisp)

# target for backward compatibility
add_custom_target(beagle_pkg_genlisp)
add_dependencies(beagle_pkg_genlisp beagle_pkg_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS beagle_pkg_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(beagle_pkg
  "/home/daschulz/IGVC/beagleWksp/src/beagle_pkg/msg/status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beagle_pkg
)

### Generating Services
_generate_srv_py(beagle_pkg
  "/home/daschulz/IGVC/beagleWksp/src/beagle_pkg/srv/dem.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beagle_pkg
)
_generate_srv_py(beagle_pkg
  "/home/daschulz/IGVC/beagleWksp/src/beagle_pkg/srv/ard.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beagle_pkg
)

### Generating Module File
_generate_module_py(beagle_pkg
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beagle_pkg
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(beagle_pkg_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(beagle_pkg_generate_messages beagle_pkg_generate_messages_py)

# target for backward compatibility
add_custom_target(beagle_pkg_genpy)
add_dependencies(beagle_pkg_genpy beagle_pkg_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS beagle_pkg_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/beagle_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/beagle_pkg
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(beagle_pkg_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/beagle_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/beagle_pkg
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(beagle_pkg_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beagle_pkg)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beagle_pkg\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/beagle_pkg
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(beagle_pkg_generate_messages_py std_msgs_generate_messages_py)
