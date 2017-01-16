var buble = require('rollup-plugin-buble');
var json = require('rollup-plugin-json');
var nodeResolve = require('rollup-plugin-node-resolve');
var commonjs = require('rollup-plugin-commonjs');

module.exports = {
	moduleName: 'transpiler',
	format: 'cjs',
	plugins: [
		json(),
		commonjs(),
		buble({
			include: [
				'./**',
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
		})
	]
};
