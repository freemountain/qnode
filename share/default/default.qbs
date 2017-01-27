import qbs.base

QNodeResource {
  name: "resource.default"
  type: ["resource"]

  Group {
   //qbs.install: true
   //qbs.installDir: "lib/myproj/"
   fileTags: ["resource.input"]
   files: [
    "a.txt",
    "b.txt"
   ]
  }
}
