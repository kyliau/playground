/**
 * @param {string} s
 * @returns {boolean}
 */
var isValid = function(s) {
    var stack = [];
    for (var i = 0, n = s.length; i < n; ++i) {
        var c = s[i];
        if (c === '(' || c === '{' || c === '[') {
            stack.push(c);
        } else {
            if (stack.length === 0) {
                return false;
            }
            var b = stack.pop();
            if ((b === '(' && c !== ')') ||
                (b === '[' && c !== ']') ||
                (b === '{' && c !== '}')) {
                    return false;
            }
        }
    }
    return stack.length === 0;
};
