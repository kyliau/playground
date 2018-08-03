/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 * An input string is valid if:
 *   Open brackets must be closed by the same type of brackets.
 *   Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 */

// Iterative solution
func isValid(s string) bool {
  var stack string
  for _, v := range s {
    if strings.ContainsRune("({[", v) {
      stack += string(v)
    } else {
      l := len(stack)
      if l == 0 {
        return false
      }
      if last := stack[l-1]; (last == '(' && v != ')') || (last == '{' && v != '}') || (last == '[' && v != ']') {
        return false
      }
      stack = stack[:l-1]
    }
  }
  return len(stack) == 0
}

// Recursive solution
var pairs = map[rune]rune{
  '(' : ')',
  '[' : ']',
  '{' : '}',
}

// findClosingPair answers the following question:
// Given an open bracket ( [ or { at position i,
// return the position of the matching closing bracket.
// If no such bracket is found, return -1
func findClosingPair(s string, i int) int {
  if i >= len(s) {
    return i
  }
  c := rune(s[i]) // rune is like 'char'
  if strings.ContainsRune(")]}", c) || i >= len(s) - 1 {
    // 1st condition: Our invariant is that s[i] must be open bracket
    // 2nd condition: Reached end of string, no way to find matching bracket
    return -1
  }
  // Check the next character
  next := i + 1
  // If the next character is an open bracket, recursively find its matching pair
  for strings.ContainsRune("([{", rune(s[next])) {
    index := findClosingPair(s, next)
    if index == -1 || index + 1 >= len(s) {
      return -1
    }
    next = index + 1
  }
  if pairs[c] == rune(s[next]) {
    return next
  }
  return -1
}

func isValid(s string) bool {
  index := findClosingPair(s, 0)
  for index != -1 && index + 1 < len(s) {
    index = findClosingPair(s, index + 1)
  }
  return index != -1
}

