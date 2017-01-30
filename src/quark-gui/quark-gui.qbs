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

  Probes.NpmProbe {
    id: npm
  }

  Probes.BinaryProbe {
    id: nodejs
    names: 'node'
  }
  property string npmPath: npm.filePath
  property string nodePath: nodejs.filePath


  Group {
     name: "default app"
     files: ["../../examples/default/**"]
     qbs.install: true
     qbs.installDir: FileInfo.joinPaths(resourceDir, "default")
  }

  Group {
      // Probes dont work in QtCreator. The filePath prop is undefined.
     condition: nodejs.filePath !== undefined
     name: "NodeJs Binary"
     files: [ nodejs.filePath === undefined ? "" : nodejs.filePath ]
     qbs.install: true
     qbs.installDir: binDir
  }


  files : [
      "main.cpp"
  ]

}
