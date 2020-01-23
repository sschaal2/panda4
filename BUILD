package(default_visibility = ["//visibility:public"])

cc_library(
    name = "panda",
    srcs = [
	"src/SL_user_commands.c",
	"src/SL_user_common.c",
	"//SL:src/SL_kinematics.c",
	"//SL:src/SL_dynamics.c",
	"//SL:src/SL_invDynNE.cpp", 
	"//SL:src/SL_invDynArt.cpp",
	"//SL:src/SL_forDynComp.cpp",
	"//SL:src/SL_forDynArt.cpp",
    ],
    textual_hdrs = glob(["include/*.h","math/*.h"]),
    includes = [
    	"include",
    	"math",		
	],
    deps = ["//utilities:utility","//lwpr:lwpr","//SL:SLcommon"],
    visibility = ["//visibility:public"],    
)

cc_library(
    name = "panda_openGL",
    srcs = [
	"src/SL_user_openGL.c",
    ],
    textual_hdrs = glob(["include/*.h","math/*.h","include/GL/*.h","include/X11/*.h"]),
    includes = [
    	"include",
    	"math",		
	],
    deps = ["//utilities:utility","//lwpr:lwpr","//SL:SLcommon"],
    visibility = ["//visibility:public"],    
)

cc_library(
    name = "panda_task",
    srcs = [
	"src/SL_user_task.c",
    ],
    textual_hdrs = glob(["include/*.h","math/*.h"]),
    includes = [
    	"include",
    	"math",		
	],
    deps = ["//utilities:utility","//lwpr:lwpr","//SL:SLcommon"],
    visibility = ["//visibility:public"],    
)

cc_library(
    name = "panda_simulation",
    srcs = [
	"src/SL_user_simulation.c",
    ],
    textual_hdrs = glob(["include/*.h","math/*.h"]),
    includes = [
    	"include",
    	"math",		
	],
    deps = ["//utilities:utility","//lwpr:lwpr","//SL:SLcommon"],
    visibility = ["//visibility:public"],    
)

cc_binary(
    name = "xpanda",
    srcs = [
	"src/SL_main.c",
	"include/X11/Xlib.h",
	"include/X11/X.h",
	"include/X11/Xfuncproto.h",
	"include/X11/Xosdefs.h",			
        ],
    includes = [
    	"include",
    	"math"	
	],
    deps = [
        "//SL:SLcommon",
	"//utilities:utility",
	":panda"
    ],
)

cc_binary(
    name = "xpest",
    srcs = [
	"//SL:src/SL_parm_estimate.c",
	"include/SL_user.h"
        ],
    includes = [
    	"include",
    	"math"
	],
    deps = [
        "//SL:SLcommon",
	"//utilities:utility",
	":panda"
    ],
    visibility = ["//visibility:public"],        
)

cc_binary(
    name = "xmotor",
    srcs = [
	"src/SL_user_motor.c",
	"src/SL_user_sensor_proc_unix.c",
	"include/SL_user.h"
        ],
    includes = [
    	"include",
    	"math"
	],
    deps = [
        "//SL:SLcommon",
        "//SL:SLmotor",	
	"//utilities:utility",
	":panda"
    ],
    visibility = ["//visibility:public"],    
)

