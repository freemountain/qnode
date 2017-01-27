#QNode && Quark


## Build

- add qt to path
- build qbs: `./configure`
- config qbs
  - `./build/tools/qbs/bin/qbs setup-toolchains --detect`
  - `./build/tools/qbs/bin/qbs setup-qt --detect`
  - Follow step in the generated warning, something like:
    - qbs config profiles.<my-own-qt>.baseProfile xcode-macosx-x86_64
  - `./build/tools/qbs/bin/qbs config defaultProfile <my-own-qt>`
- build all the stuff
  - `./build/tools/qbs/bin/qbs build`
- build path is `build/default`
- install path is `build/default/install-root`
