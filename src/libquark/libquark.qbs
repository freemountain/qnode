import qbs.base

QNodeLibrary {
 name: "quark"

Depends{ name: "cutehacks.gel"}
 Depends { name: "Qt"; submodules: ["qml", "quick"] }

 files: [
    "qml.qrc",

    //"cpp/main.cpp",
    "cpp/rootstore.cpp",
    "cpp/environment.cpp",
    "cpp/quarkprocess.cpp",
    "cpp/debugger.cpp",
    "cpp/rootstore.h",
    "cpp/environment.h",
    "cpp/quarkprocess.h",
    "cpp/either.h",
    "cpp/logger.h",
    "cpp/debugger.h"
 ]
}
