var timers = require('timers');
var process = require('process');

//timers.setTimeout(process.send, 1, 1);
timers.setInterval(function(n) {
  console.log('\niiiii', n);
}, 4000, 2);

console.log('hi');

timers.setImmediate(function(a, b) {
  console.log("imm", a + b);
}, 1, 2);
