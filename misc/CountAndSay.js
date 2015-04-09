// Problem statement:
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.
//
// Note: The sequence of integers will be represented as a string.

/**
 * @param {number} n
 * @returns {string}
 */
var countAndSay = function(n) {
    var sequence = ["1", "11", "21", "1211", "111221"];
    for (var i = 5; i < n; ++i) {
        sequence[i] = '';
        var prev = sequence[i-1];
        var char = prev[0], count = 1;
        for (var j = 1; j < prev.length; ++j) {
            if (prev[j] === char) {
                ++count;
            } else {
                sequence[i] += count + '' + char;
                char = prev[j];
                count = 1;
            }
        }
        if (char === prev[prev.length - 1]) {
            sequence[i] += count + '' + char;    
        }
    }
    return sequence[n-1];
};
