import qbs 1.0

QNodeApplication {
    consoleApplication: true
    name : "secondapp"
    files : [ "main.cpp" ]
    Depends { name: "cpp" }
    Depends { name: "lib" }
}
