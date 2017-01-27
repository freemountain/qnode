import "../imports/QNodeProduct.qbs" as QNodeProduct

QNodeProduct {
 name: "cutehacks.gel"


 type: "staticlibrary"
 Depends { name: "cpp" }


 Depends { name: "Qt"; submodules: ["qml"] }

 files: [
    "../../vendor/gel/jsvalueiterator.h",
    "../../vendor/gel/jsonlistmodel.h",
    "../../vendor/gel/collection.h",
    "../../vendor/gel/gel.h",
    "../../vendor/gel/jsonlistmodel.cpp",
    "../../vendor/gel/collection.cpp",
    "../../vendor/gel/gel.cpp"
 ]
}
