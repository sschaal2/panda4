#############################################################################
#############################################################################
#
#  This is a CMakeList.txt file originally programmed for the CLMC/AMD labs
#  at the University of Southern California and the Max-Planck-Institute for
#  Intelligent Systems. We use a mixutre of explicit makefiles and cmake, but 
#  primarily we relay on cmake for all major compile dependencies. All our
#  software is provided under a slightly modified version of the LGPL license
#  to be found at http://www-clmc.usc.edu/software/license.
#
#  Copyright by Stefan Schaal, 2014
#
#############################################################################
#############################################################################
# which version are we using

cmake_minimum_required(VERSION 2.8)

#############################################################################
# include common cmake components

include($ENV{LAB_ROOT}/config/cmake/LAB.cmake)

#############################################################################
# user defined cmake components
project(panda)

# set global compile type
set(CMAKE_BUILD_TYPE RelWithDebInfo) # Optimization with debugging info
#set(CMAKE_BUILD_TYPE Release)       # Optimization 
#set(CMAKE_BUILD_TYPE Debug)         # Debug

# local defines
include_directories(BEFORE ../include)
include_directories(BEFORE ../src)
include_directories(BEFORE ../math)
include_directories(BEFORE ../../libfranka/include)
include_directories(BEFORE /usr/include/eigen3)
include_directories(BEFORE ../../SOEM/install/include/soem)

link_directories(AFTER ../..//SOEM/install/lib)


if($ENV{HOST} MATCHES ${PANDA_HOST})
  add_definitions(-DPANDA)
  link_directories($ENV{LAB_ROOT}/libfranka/build ${CMAKE_LIBRARY_PATH})
endif()

# endeffector different from standard Franka
add_definitions(-DAXIA80)
add_definitions(-DROBOTIQ2F)

set(CMAKE_CXX_STANDARD 11)

# robot name
set(NAME panda)

# ------------------------------------------------------------------------

set(SRCS_COMMON
	SL_user_commands.c
	SL_user_common.c
	$ENV{PROG_ROOT}/SL/src/SL_kinematics.c 
	$ENV{PROG_ROOT}/SL/src/SL_dynamics.c 
	$ENV{PROG_ROOT}/SL/src/SL_invDynNE.cpp 
	$ENV{PROG_ROOT}/SL/src/SL_invDynArt.cpp
	$ENV{PROG_ROOT}/SL/src/SL_forDynComp.cpp
	$ENV{PROG_ROOT}/SL/src/SL_forDynArt.cpp
	)	

set(SRC_XMAIN
	SL_main.c
	SL_user_common.c
	)

set(SRC_XRMAIN
	SL_rmain.c
	SL_user_common.c
	)

set(SRCS_XPEST
	$ENV{PROG_ROOT}/SL/src/SL_parm_estimate.c
	${SRCS_COMMON}
	)

set(SRCS_XMOTOR
	SL_user_motor.c
	SL_user_sensor_proc_unix.c
	${SRCS_COMMON}
	)

set(SRCS_XVISION
	SL_user_vision.c
	${SRCS_COMMON}
	)

set(SRCS_XRPROBOT
	panda_servo_unix.cpp 
	SL_user_common.c 
	$ENV{PROG_ROOT}/SL/src/SL_kinematics.c 
	)

set(SRCS_OPENGL SL_user_openGL.c)
set(SRCS_TASK SL_user_task.c)
set(SRCS_SIMULATION SL_user_simulation.c)


# ------------------------------------------------------------------------

add_executable("x${NAME}" ${SRC_XMAIN})
target_link_libraries("x${NAME}" SLcommon utility ${LAB_STD_LIBS})

add_executable(xpest ${SRCS_XPEST})
target_link_libraries(xpest SLcommon utility ${LAB_STD_LIBS})

add_executable(xmotor ${SRCS_XMOTOR})
target_link_libraries(xmotor SLmotor SLcommon utility ${LAB_STD_LIBS})

#add_executable(xvision ${SRCS_XVISION})
#target_link_libraries(xvision SLvision SLcommon lwpr utility ${LAB_STD_LIBS})

add_library("${NAME}" ${SRCS_COMMON})
install(TARGETS "${NAME}" ARCHIVE DESTINATION ${LAB_LIBDIR})

add_library("${NAME}_openGL" ${SRCS_OPENGL})
install(TARGETS "${NAME}_openGL" ARCHIVE DESTINATION ${LAB_LIBDIR})

add_library("${NAME}_task" ${SRCS_TASK})
install(TARGETS "${NAME}_task" ARCHIVE DESTINATION ${LAB_LIBDIR})

add_library("${NAME}_simulation" ${SRCS_SIMULATION})
install(TARGETS "${NAME}_simulation" ARCHIVE DESTINATION ${LAB_LIBDIR})


if($ENV{HOST} MATCHES ${PANDA_HOST})

  add_executable("xr${NAME}" ${SRC_XRMAIN})
  target_link_libraries("xr${NAME}" SLcommon utility ${LAB_STD_LIBS})

  add_executable(xrprobot ${SRCS_XRPROBOT})
  target_link_libraries(xrprobot franka SLcommon utility ftcells grippers comm soem rt ${LAB_STD_LIBS})

endif()
