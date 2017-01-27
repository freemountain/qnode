import qbs 1.0
import qbs.ModUtils
import qbs.TextFile

Product {
    type: ["dynamiclibrary", "dependencies.json"]


    property stringList _requiredFrom: []


    Depends { name: 'cpp' }

    Export {
        Depends { name: "cpp" }
        cpp.includePaths: [product.sourceDirectory]
        property var _init: {
          print("requested lib", product.name);
          return 3;
        }
    }


    Group {
        fileTagsFilter: "dynamiclibrary"
        qbs.install: true
        qbs.installDir: "lib"
    }




    Rule {
      multiplex: true
      //inputsFromDependencies: ["installable"]
      inputs: ["dynamiclibrary"]
      Artifact {
          filePath: "windeployqt.json"
          fileTags: "dependencies.json"
      }

      prepare: {
          print("hellaaa", Object.keys(inputs));
          var cmd = new JavaScriptCommand();

          cmd.outputFilePath = output.filePath;
          cmd.installRoot = product.moduleProperty("qbs", "installRoot");
          cmd.windeployqtArgs = product.windeployqtArgs;

          var ss = cmd.binaryFilePaths = inputs.installable.filter(function (artifact) {
              return artifact.fileTags.contains("application")
                      || artifact.fileTags.contains("dynamiclibrary");
          }).map(function(a) { return ModUtils.artifactInstalledFilePath(a); });

          print("ss", ss.join("\n"));
          cmd.sourceCode = function () {
              var out = 'ss.binaryFilePaths.join("\n")';

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
}
