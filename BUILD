# Every SL directory has a symbolic link to config/bazel to access the config files as local path.
# While not pretty, this allows BUILD files to be independt of the SL_ROOT workspace path, and only
# SL.bzl needs to be adjusted
load(":bazel/SL.bzl", "FEATURES", "SL_ROOT", "SL_VISIBILITY")

package(
    default_visibility = SL_VISIBILITY,
    features = FEATURES,
)

licenses(["notice"])

exports_files(["LICENSE"])

# the name of this robot: various rules use the NAME such that BUILD files are easy to adapt to another robot
NAME = "panda"

# the filegroups are needed for the final build of binaries, which is best done in the "user" directory of
# a robot. Using these filegroups may create bazel warnings, which can be ignored.
filegroup(
    name = "main_srcs",
    srcs = [
        "src/SL_main.c",
    ],
)

filegroup(
    name = "motor_srcs",
    srcs = [
        "include/SL_user.h",
        "src/SL_user_motor.c",
        "src/SL_user_sensor_proc_unix.c",
    ],
)

# the following libraries are needed for the different binaries of the SL robot processes

# the library for the main program, which starts all other processes
cc_library(
    name = "panda",
    srcs = [
        "src/SL_user_commands.c",
        "src/SL_user_common.c",
        SL_ROOT + "SL:kin_and_dyn_srcs",
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
        SL_ROOT + "SL:SLcommon",
        SL_ROOT + "lwpr",
        SL_ROOT + "utilities:utility",
    ],
)

# graphics and visualization library
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
    ]),
    deps = [
        SL_ROOT + "SL:SLcommon",
        SL_ROOT + "lwpr",
        SL_ROOT + "utilities:utility",
        "//third_party/Xorg:libX11",
        "//third_party/freeglut:headers",
        "//third_party/freeglut:native",
        "//third_party/glu:native",
    ],
)

# the task process, which is the core process for a user to modify
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
        SL_ROOT + "SL:SLcommon",
        SL_ROOT + "lwpr",
        SL_ROOT + "utilities:utility",
    ],
)

# the physical simulation
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
        SL_ROOT + "SL:SLcommon",
        SL_ROOT + "lwpr",
        SL_ROOT + "utilities:utility",
    ],
)
