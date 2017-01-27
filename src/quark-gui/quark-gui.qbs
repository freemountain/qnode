import qbs.base
import qbs.FileInfo
import qbs.File
import qbs.Probes
import qbs.ModUtils

QNodeApplication {
  name: "QuarkGui"
  //stype: ["application", "app_deps",]


  Depends { name: "Qt"; submodules: ["quick", "qml"] }
  Depends { name: "quark" }
  Depends { name: "cpp" }
  Depends { name: "node_path" }

  Probes.NodeJsProbe {
    id: nodejs
  }

  Probes.NpmProbe {
    id: npm
  }
  property string npmPath: npm.filePath


  Group {
     name: "default app"
     files: ["../../examples/default/**"]
     qbs.install: true
     qbs.installDir: FileInfo.joinPaths(resourceDir, "default")
  }
/*
  Group {
     name: "ounpm_pkgt"
     fileTagsFilter: ["npm_pkg.node_path"]
     qbs.install: true
    // qbs.installSourceBase: product.destinationDirectory
     qbs.installDir: FileInfo.joinPaths(FileInfo.path(bundle.executablePath), "../Frameworks")
  }


  Group {
     name: "node_path dist"
     fileTags: ["node_path_dist"]
     qbs.install: true
     qbs.installDir: FileInfo.joinPaths(resourceDir, "node_path")
  }

  Group {
     name: "node_path disf"
     fileTags: ["node_path_files"]
     qbs.install: true
     qbs.installDir: FileInfo.joinPaths(resourceDir, "node_path_files")
  }
  */

  Group {
     name: "NodeJs Binary"
     files: [nodejs.filePath]
     qbs.install: true
     qbs.installDir: binDir
  }


  files : [
      "main.cpp"
  ]

}
