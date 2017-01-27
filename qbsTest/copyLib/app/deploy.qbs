import qbs
import qbs.FileInfo
import qbs.Process
import qbs.ModUtils
Product {
  name: "lib_deploy"/*
    type: [ "deployment" ]
    property bool debug: true

    Depends { name: "lib" }

    Group {
        fileTagsFilter: "deployment"
        qbs.install: true
        qbs.installDir: "deploy"
    }

    Rule{
        inputs:["qbs", "lib"]
        inputsFromDependencies: ["lib"]

        Artifact  {
            filePath: "deploy" + product.name
            fileTags: [ "deployment" ]
        }
        prepare: {
            var cmd;
            var deployqt;
            var targetOS = product.moduleProperty("qbs", "targetOS");
            var targetDep = product.dependencies[0];
            ModUtils.dumpObject(inputs.qbs);

            print("dep keys", Object.keys(product.dependencies[0]), "depy", Object.keys(product.dependencies))

            product.dependencies.forEach(function(dep) {
              print("dep: ", dep.name, dep.sourceDirectory, ModUtils.artifactInstalledFilePath(dep.name))
            });
            var targetName = targetDep.name;
            if (targetOS.contains("windows")) {
                targetName = targetName + ".exe";
                deployqt = FileInfo.joinPaths(product.moduleProperty("Qt.core", "binPath"), "windeployqt");
            } else if (targetOS.contains("osx")) {
                targetName = targetName + ".app";
                deployqt = FileInfo.joinPaths(product.moduleProperty("Qt.core", "binPath"), "macdeployqt");
            }
            var libDir = product.moduleProperty("Qt.core", "libPath");
            var pluginDir = product.moduleProperty("Qt.core", "pluginPath");
            var targetPath = targetDep.destinationDirectory + "/" + targetDep.targetName;

            if (product.debug) {
                print("deploy:" + deployqt);
                print("targetname:" + targetName);
                print("targetpath:" + targetPath);
                print("path:" + FileInfo.path(deployqt));
                print("libdir:" + libDir);
                print("plugin:" + pluginDir);
            }


            cmd = new JavaScriptCommand();
            cmd.command = deployqt;
            cmd.target = targetName;
            cmd.workingDir = targetPath;
            cmd.libdir = libDir;
            cmd.plugindir = pluginDir;
            cmd.description = "deploying: " + targetDep.name
            cmd.sourceCode = function() {
                var process = new Process();
                try {
                    process.setWorkingDirectory(workingDir);
                    process.setEnv("QTDIR", FileInfo.path(command) + "/..");
                    process.setEnv("QT_INSTALL_LIBS", libdir);
                    process.setEnv("QT_INSTALL_PLUGINS", plugindir);
                    process.exec(command, [target, "-verbose=3"]);
                    if (process.exitCode() !== 0) {
                        throw(process.readStdErr());
                    } else {
                        print(process.readStdOut());
                        print(process.readStdErr());
                    }
                } finally {
                    process.close();
                }
            };

            return cmd;
        }
    }
    */
}
