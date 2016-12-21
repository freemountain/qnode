var assert = module.exports = {};

assert.fail = function fail(msg) {
    throw new Error(msg);
}
