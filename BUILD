package(default_visibility = ["//visibility:public"])

cc_library(
    name = "panda",
    srcs = [
        "src/SL_user_commands.c",
        "src/SL_user_common.c",
        "//experimental/users/sschaal/SL/SL:src/SL_dynamics.c",
        "//experimental/users/sschaal/SL/SL:src/SL_forDynArt.cpp",
        "//experimental/users/sschaal/SL/SL:src/SL_forDynComp.cpp",
        "//experimental/users/sschaal/SL/SL:src/SL_invDynArt.cpp",
        "//experimental/users/sschaal/SL/SL:src/SL_invDynNE.cpp",
        "//experimental/users/sschaal/SL/SL:src/SL_kinematics.c",
    ],
    includes = [
        "include",
        "math",
    ],
    textual_hdrs = glob([
        "include/*.h",
        "math/*.h",
    ]),
    deps = [
        "//experimental/users/sschaal/SL/SL:SLcommon",
        "//experimental/users/sschaal/SL/lwpr",
        "//experimental/users/sschaal/SL/utilities:utility",
    ],
)

cc_library(
    name = "panda_openGL",
    srcs = [
        "src/SL_user_openGL.c",
    ],
    includes = [
        "include",
        "math",
    ],
    textual_hdrs = glob([
        "include/*.h",
        "math/*.h",
        "include/GL/*.h",
        "include/X11/*.h",
    ]),
    deps = [
        "//experimental/users/sschaal/SL/SL:SLcommon",
        "//experimental/users/sschaal/SL/lwpr",
        "//experimental/users/sschaal/SL/utilities:utility",
        "//third_party/freeglut:freeglut_base",
        "//third_party/glu:native",
        "//third_party/Xorg:libX11",	
    ],
)

cc_library(
    name = "panda_task",
    srcs = [
        "src/SL_user_task.c",
    ],
    includes = [
        "include",
        "math",
    ],
    textual_hdrs = glob([
        "include/*.h",
        "math/*.h",
    ]),
    deps = [
        "//experimental/users/sschaal/SL/SL:SLcommon",
        "//experimental/users/sschaal/SL/lwpr",
        "//experimental/users/sschaal/SL/utilities:utility",
    ],
)

cc_library(
    name = "panda_simulation",
    srcs = [
        "src/SL_user_simulation.c",
    ],
    includes = [
        "include",
        "math",
    ],
    textual_hdrs = glob([
        "include/*.h",
        "math/*.h",
    ]),
    deps = [
        "//experimental/users/sschaal/SL/SL:SLcommon",
        "//experimental/users/sschaal/SL/lwpr",
        "//experimental/users/sschaal/SL/utilities:utility",
    ],
)

cc_binary(
    name = "xpanda",
    srcs = [
        "src/SL_main.c",
    ],
    includes = [
        "include",
        "math",
    ],
    deps = [
        ":panda",
        "//experimental/users/sschaal/SL/SL:SLcommon",
        "//experimental/users/sschaal/SL/utilities:utility",
        "//third_party/Xorg:libX11",	
	
    ],
)

cc_binary(
    name = "xpest",
    srcs = [
        "include/SL_user.h",
        "//experimental/users/sschaal/SL/SL:src/SL_parm_estimate.c",
    ],
    includes = [
        "include",
        "math",
    ],
    deps = [
        ":panda",
        "//experimental/users/sschaal/SL/SL:SLcommon",
        "//experimental/users/sschaal/SL/utilities:utility",
    ],
)

cc_binary(
    name = "xmotor",
    srcs = [
        "include/SL_user.h",
        "src/SL_user_motor.c",
        "src/SL_user_sensor_proc_unix.c",
    ],
    includes = [
        "include",
        "math",
    ],
    deps = [
        ":panda",
        "//experimental/users/sschaal/SL/SL:SLcommon",
        "//experimental/users/sschaal/SL/SL:SLmotor",
        "//experimental/users/sschaal/SL/utilities:utility",
    ],
)
