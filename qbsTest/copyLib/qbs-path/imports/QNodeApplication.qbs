import qbs 1.0
import qbs.ModUtils
import qbs.FileInfo
import qbs.File

Product {
    type: ["application", "app_deps"]

    Depends { name: "cpp" }
    Depends { name: "bundle" }
    bundle.isBundle: true

    property string installDir: "."

    Group {
        fileTagsFilter: ["application"]
        qbs.install: true//install
        qbs.installDir: bundle.isBundle ? FileInfo.joinPaths(installDir, FileInfo.path(bundle.executablePath)) : installDir
    }

    Group {
        fileTagsFilter: ["aggregate_infoplist"]
        qbs.install: true//install && bundle.isBundle && !bundle.embedInfoPlist
        qbs.installDir: FileInfo.joinPaths(installDir, FileInfo.path(bundle.infoPlistPath))
    }

    Group {
        fileTagsFilter: ["pkginfo"]
        qbs.install: true//nstall && bundle.isBundle
        qbs.installDir: FileInfo.joinPaths(installDir, FileInfo.path(bundle.pkgInfoPath))
    }

    Group {
        fileTagsFilter: "app_deps"
        qbs.install: true
        qbs.installDir:FileInfo.joinPaths(installDir, FileInfo.path(bundle.executablePath), "../Frameworks")
    }


    Rule {
        inputs:["qbs", "lib"]
        inputsFromDependencies: ["dynamiclibrary"]

        outputArtifacts: {
            var tags = ["app_deps"];
            print("ds", input.fileTags);
            if(!input.fileTags.contains("dynamiclibrary")) return [];

            return [{
                filePath: FileInfo.joinPaths(product.destinationDirectory, product.name + ".app/Contents/Frameworks",
                                             input.fileName),
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
