var t = require('typedarray');

console.log('createProxy', t.createProxy);

var p = t.createProxy({
  a: 4
}, {});


console.log('p["a"]:', p['a']);
//console.log(Object.keys(p));
console.log("end");
