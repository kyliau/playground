func toGoatLatin(s string) string {
  reader := strings.NewReader(s)
  scanner := bufio.NewScanner(reader)
  scanner.Split(bufio.ScanWords)
  builder := strings.Builder{}
  count := 1
  for scanner.Scan() {
    if builder.Len() > 0 {
      builder.WriteRune(' ')
    }
    text := scanner.Text()
    first := rune(text[0])
    if !strings.ContainsRune("aeiouAEIOU", first) {
      builder.WriteString(text[1:])
      builder.WriteRune(first)
    } else {
      builder.WriteString(text)
    }
    builder.WriteString("ma")
    for i := 0; i < count; i++ {
      builder.WriteRune('a')
    }
    count++
  }
  return builder.String()
}
