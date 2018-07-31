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
