import qbs.base
import qbs.FileInfo
import qbs.File
import qbs.Probes
import qbs.ModUtils

QNodeApplication {
  name: "QuarkGui"

  Depends { name: "Qt"; submodules: ["quick", "qml"] }

  Depends { name: "quark" }
  Depends { name: "cpp" }

  Depends { name: "node_path" }
  Depends { name: "default" }
  Depends { name: "extern_node" }

  Probes.BinaryProbe {
    id: nodejs
    names: 'node'
  }

  Group {
      // Probes dont work in QtCreator and only on osx. The filePath prop is undefined.
     //condition: nodejs.filePath !== undefined && qbs.targetOS.contains("darwin")
     condition: false
     files: [ nodejs.filePath === undefined ? "" : nodejs.filePath ]
     fileTags: ["extern_bin"]
  }



  files : [
      "main.cpp"
  ]

}
