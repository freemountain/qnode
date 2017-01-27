import qbs 1.0

QNodeApplication {
    consoleApplication: true
    name : "app"
    files : [ "main.cpp" ]
    Depends { name: "cpp" }
    Depends { name: "lib" }
}
