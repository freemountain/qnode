import qbs.base 1.0
import qbs.TextFile
import qbs.Probes
import qbs.ModUtils
import qbs.FileInfo
import qbs.File

Product {
  name: 'extern_node'
  type: 'extern_bin'

  Probes.BinaryProbe {
    id: wget
    names: 'wget'
  }
  Probes.BinaryProbe {
    id: curl
    names: 'curl'
  }

  Probes.BinaryProbe {
    id: tar
    names: 'tar'
  }

  property string curlBin: curl.filePath
  property string wgetBin: wget.filePath
  property string tarBin: tar.filePath

  property string linux32Url: 'https://nodejs.org/dist/v7.5.0/node-v7.5.0-linux-x86.tar.xz'

  Rule {
    multiplex: true
    Artifact {
        filePath: "node-v7.5.0-linux-x86.tar.xz"
        fileTags: ["extern_node_archive"]
    }

    prepare: {
        var dl = new Command(product.wgetBin, [product.linux32Url]);
        dl.workingDirectory = FileInfo.path(output.filePath)

        return [dl];
    }
  }

  Rule {
    inputs: ["extern_node_archive"]
    Artifact {
        filePath: "node"
        fileTags: ["extern_bin"]
    }

    prepare: {
        var extract = new Command(product.tarBin, [
          'xpvf', 'node-v7.5.0-linux-x86.tar.xz',
          '-C', '.'
        ]);
        extract.workingDirectory = FileInfo.path(output.filePath)

        var copy = new JavaScriptCommand();
        copy.sourceCode = function() {
          File.copy(FileInfo.path(output.filePath)+ '/node-v7.5.0-linux-x86/bin/node', output.filePath);
        };
        copy.silent = true;

        return [extract, copy];
    }
  }
}
