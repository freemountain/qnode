import qbs.base 1.0
import qbs.FileInfo
import qbs.File
import qbs.ModUtils


QNodeProduct {
  type: ["application", "app_deps", "resource", "node_path_files", "node_path_dist", "bundle.resource", "bundle.bin"]

  Depends { name: "cpp" }
  Depends { name: "bundle" }
  bundle.isBundle: qbs.targetOS.contains("darwin")
  property bool isBundle: bundle.isBundle

  cpp.rpaths: {
    if(!qbs.targetOS.contains("darwin")) return [ "$ORIGIN/../lib/" + project.app_target ];

    var libPrefix = bundle.isBundle ? "@executable_path/../Frameworks" :  "@executable_path/../lib"

    return [ Qt.core.libPath, "@executable_path/../Frameworks",  "@executable_path/../lib" ];
  }


  Group {
    fileTagsFilter: ["application"]
    qbs.install: true
    qbs.installDir: bundle.isBundle
                    ? FileInfo.path(bundle.executablePath)
                    : FileInfo.joinPaths(product.name, "bin")
  }

  /*
  Group {
      name: ".icns"
      condition: qbs.targetOS.contains("darwin")
      files: [ "Fish.icns" ]
      qbs.install: true
      qbs.installDir: install_data_path
  }
  */

  Group {
      fileTagsFilter: ["infoplist"]
      qbs.install: bundle.isBundle && !bundle.embedInfoPlist
      qbs.installDir: FileInfo.joinPaths(FileInfo.path(bundle.infoPlistPath))
  }


  Group {
      fileTagsFilter: ["aggregate_infoplist"]
      qbs.install: bundle.isBundle
      qbs.installDir: FileInfo.path(bundle.infoPlistPath)
  }

  Group {
      fileTagsFilter: ["pkginfo"]
      qbs.install: true
      qbs.installDir: FileInfo.path(bundle.pkgInfoPath)
  }

  Group {
      fileTagsFilter: "app_deps"
      qbs.install: true
      qbs.installDir: bundle.isBundle
        ? FileInfo.joinPaths(FileInfo.path(bundle.executablePath), "../Frameworks")
        : FileInfo.joinPaths(product.name, "lib")
  }

  Group {
      fileTagsFilter: "bundle.resource"
      qbs.install: true
      qbs.installSourceBase: product.destinationDirectory
      qbs.installDir: bundle.isBundle
        ? FileInfo.joinPaths(FileInfo.path(bundle.executablePath), "../Resources")
        : FileInfo.joinPaths(product.name, "resources")
  }


  Group {
      fileTagsFilter: "bundle.bin"
      qbs.install: true
      qbs.installDir: bundle.isBundle
        ? FileInfo.joinPaths(FileInfo.path(bundle.executablePath))
        : FileInfo.joinPaths(product.name, "bin")
  }


Rule {
    inputsFromDependencies:["resource"]
    inputs: ["resource"]
    Artifact {
        filePath: FileInfo.joinPaths(input.baseDir, input.fileName)
        fileTags: ["bundle.resource"]
    }

    prepare: {
      var cmd = new JavaScriptCommand();

      cmd.sourceCode = function() {
        File.copy(input.filePath, output.filePath);
      };
      cmd.silent = true;

      return [cmd];
    }
}

Rule {
    inputsFromDependencies:["extern_bin"]
    inputs:["extern_bin"]

    Artifact {
        filePath: FileInfo.joinPaths(input.baseDir, input.fileName)
        fileTags: ["bundle.bin"]
    }

    prepare: {
      var cmd = new JavaScriptCommand();

      cmd.sourceCode = function() {
        File.copy(input.filePath, output.filePath);
      };
      cmd.silent = true;

      return [cmd];
    }
}

Rule {
    inputs:["lib"]
    inputsFromDependencies: ["dynamiclibrary"]

    outputArtifacts: {
        var tags = ["app_deps"];
        var filePath = product.isBundle
          ? FileInfo.joinPaths(product.destinationDirectory, product.name + ".app/Contents/Frameworks", input.fileName)
          : FileInfo.joinPaths(product.destinationDirectory, "lib", input.fileName)

        return [{
            filePath: filePath,
            fileTags: tags
        }];
    }

    outputFileTags: ["app_deps"]

    prepare: {
        var cmd = new JavaScriptCommand();
        cmd.description = "copying " + input.filePath + " to " + output.filePath;
        cmd.sourceCode = function() {
          if(!input.fileTags.contains("dynamiclibrary")) return;

            File.copy(input.filePath, output.filePath);
        };
        return cmd;
    }
}

}
