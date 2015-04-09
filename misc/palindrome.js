// Find the length of the shortest palindrome
// that can be formed by adding 0 or more characters
// in front of a string

var readline = require('readline');
var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false
});

var word;

rl.on('line', function (str) {
    word = str;
});

// The following function returns true if 'string'
// is a palindrome, false otherwise.
function isPalindrome(string) {
    var left = 0;
    var right = string.length - 1;
    while (string[left] === string[right] && left < right) {
        ++left;
        --right;
    }
    return string[left] === string[right];
}

// The following function returns the length of longest
// palindrome that can be formed from the beginning
// of the specificied 'string'
// eg. 'racecarabc' -> 7 (racecar)
function longestPalindrome(string) {
    for (var i = string.length; i > 0; --i) {
        if (isPalindrome(string.substring(0, i))) {
            return i;
        }
    }
    return 0;
}

rl.on('close', function () {
    console.log(word.length * 2 - longestPalindrome(word));
});
