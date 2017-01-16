var buble = require('./src/node_modules/rollup-plugin-buble');
var json = require('./src/node_modules/rollup-plugin-json');
var nodeResolve = require('./src/node_modules/rollup-plugin-node-resolve');
var commonjs = require('./src/node_modules/rollup-plugin-commonjs');

module.exports = {
	entry: './src/src/index.js',
	moduleName: 'buble',
	format: 'umd',
	plugins: [
		json(),
		commonjs(),
		buble({
			include: [
				'src/**',
				'node_modules/acorn-object-spread/**',
				'node_modules/unicode-loose-match/**',
				'node_modules/regexpu-core/**'
			],
			transforms: {
				dangerousForOf: true,
				arrow: true
			}
		}),
		nodeResolve({
			jsnext: true,
			//skip: external
		})
	],
	//external: external,
	/*globals: {
		'acorn/dist/acorn.js': 'acorn',
		'magic-string': 'MagicString'
	},*/
	sourceMap: true
};
