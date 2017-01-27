import qbs 1.0

Lib {
    //type: "dynamiclibrary"
    name: "lib"
    files: [
        "lib.cpp",
        "lib.h",
    ]

    Group {
        fileTagsFilter: "dependencies.json"
        qbs.install: true
        qbs.installDir: "libB"
    }
    /*
    Depends { name: 'cpp' }

    Export {
        Depends { name: "cpp" }
        cpp.includePaths: [product.sourceDirectory]
    }



    Group {
        fileTagsFilter: "dynamiclibrary"
        qbs.install: true
        qbs.installDir: "lib"
    }


    Rule {
      multiplex: true
      inputsFromDependencies: ["dynamiclibrary"]

      Artifact {
          filePath: "windeployqt.json"
          fileTags: ["dependencies.json"]
      }

      prepare: {
          var cmd = new JavaScriptCommand();
          cmd.description = "windeployqt";
          cmd.outputFilePath = output.filePath;
          cmd.installRoot = product.moduleProperty("qbs", "installRoot");
          cmd.windeployqtArgs = product.windeployqtArgs;

          cmd.binaryFilePaths = inputs.installable.filter(function (artifact) {
              return artifact.fileTags.contains("application")
                      || artifact.fileTags.contains("dynamiclibrary");
          }).map(function(a) { return ModUtils.artifactInstalledFilePath(a); });


          cmd.sourceCode = function () {
              var out = cmd.binaryFilePaths.join("\n");

              var tf;
              try {
                  tf = new TextFile(outputFilePath, TextFile.WriteOnly);
                  tf.write(out);
              } finally {
                  if (tf) tf.close();
              }
          };
          return [cmd];
      }
  }
  */
}
