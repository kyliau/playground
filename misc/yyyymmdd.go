package main

import "fmt"

func isValidDateHelper(year, month, day int) bool {
	if year <= 0 || month <= 0 || day <= 0 {
		return false
	}
	if month == 2 {
		return (year%4 == 0 && day <= 29) || day <= 28
	}
	if month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 {
		return day <= 31
	}
	return month < 12 && day <= 30
}

func isValidDate(val [3]int) bool {
	return isValidDateHelper(val[0], val[1], val[2]) ||
		isValidDateHelper(val[0], val[2], val[1]) ||
		isValidDateHelper(val[2], val[0], val[1]) ||
		isValidDateHelper(val[2], val[1], val[0])
}

func main() {
	tests := []struct {
		val1, val2, val3 int
		result           bool
	}{
		{2010, 1, 2, true},
		{2010, 2, 1, true},
		{2000, 1, 31, true},
		{2000, 2, 29, true},
		{2010, 32, 1, false},
		{2000, 2, 30, false},
		{2001, 2, 29, false},
	}
	for _, test := range tests {
		var str string
		if result := isValidDate([3]int{test.val1, test.val2, test.val3}); result == test.result {
			str = "PASSED"
		} else {
			str = "FAILED"
		}
		fmt.Printf("%v/%v/%v %v\n", test.val1, test.val2, test.val3, str)
	}
}
