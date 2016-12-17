function(qProcess, helper) {
    var wrapper = {
        nextTick: function nextTick() {
            var result = qProcess.nextTick(arguments[0], helper.collectArgs(arguments, 1));
            return helper.throwError(result)
        },
        send: function send(msg) {
            return helper.throwError(qProcess.send(msg));
        }
    }

    return Object.freeze(wrapper);
}
