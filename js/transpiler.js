var buble = require( 'buble' );

module.exports = function(src) {
  return buble.transform( source ).code;
}
