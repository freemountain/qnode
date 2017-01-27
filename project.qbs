import qbs.FileInfo
import qbs

Project {
    minimumQbsVersion: "1.6"
    AutotestRunner { }

    property stringList includePaths: [
      sourceDirectory + '/src/libquark/cpp',
      sourceDirectory + '/src/libqnode',
      sourceDirectory + '/vendor',
    ]


    /*
    property stringList libraryPaths: []

    */




    qbsSearchPaths: ["qbs"]
    references: [
        "share/default/default.qbs",
        "qbs/vendor/gel.qbs",

        "src/qnode-cli/qnode-cli.qbs",
        "src/qnode-gui/qnode-gui.qbs",
        "src/quark-gui/quark-gui.qbs",

        "src/libqnode/libqnode.qbs",
        "src/libquark/libquark.qbs",

        "src/node_path/node_path.qbs",

        "test/tests.qbs"
    ]

}
