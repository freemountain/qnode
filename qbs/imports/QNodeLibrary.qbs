import qbs.base 1.0
import qbs.FileInfo

QNodeProduct {
    type: "dynamiclibrary"
    Depends { name: "cpp" }
    Depends { name: "bundle" }

    bundle.isBundle: project.frameworksBuild

    cpp.sonamePrefix: "@rpath"
}
