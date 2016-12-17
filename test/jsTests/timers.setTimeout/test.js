var timers = require('timers');
var process = require('process');

timers.setTimeout(process.send, 1, 1);
//timers.setTimeout(process.send, 2, 2);

//var id = timers.setTimeout(process.send, 3, 3);

//timers.clearTimeout(id);
//process.send(0);
