import qbs.FileInfo

Project {
  property stringList _deps: {}

  qbsSearchPaths: ["qbs-path"]
  references: [
      "app/app.qbs",
      "second-app/app.qbs",
      "lib/lib.qbs",
      "app/deploy.qbs",

  ]


}
