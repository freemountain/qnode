var config = require('./rollup.config.js');

module.exports = Object.assign({}, config, {
	entry: './babelIndex.js',
});
