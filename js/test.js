var fs = require('fs');
var util = require('util');

console.log(Object.keys(fs));

fs.writeFile("/Users/dodo/Projekte/top/qNode/build/greekAnthem1.txt", 'latin1ÄÖPLssssÜ', {
  encoding: "utf8",
  flag: "wr"
},function(err) {
console.log('result', err);
});

//setTimeout(function(err, data) {}, 2000);
