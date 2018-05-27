var crypto = require('crypto');
var ed25519 = require('./');

let seed = [194,145,232,132,188,66,229,74,48,83,103,173,0,246,239,236,207,80,112,111,131,30,173,1,54,187,233,255,2,236,148,200]

// Alice likes to be random, and remembers that the MakeKeypair function takes a 32 byte buffer
var aliceSeed = new Buffer(seed, 'hex')
console.log(aliceSeed)
var aliceKeypair = ed25519.MakeKeypair(aliceSeed);
console.log(aliceKeypair)
