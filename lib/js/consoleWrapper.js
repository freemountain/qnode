function(qConsole, helper, ctx) {
    var format = ctx.require("util").format;
    var wrapper = {
        log: function log() {
            qConsole.log(format.apply(null, arguments));
        }
    }

    return Object.freeze(wrapper);
}
