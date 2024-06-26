package main

import "strings"

func lengthOfLongestSubstring(s string) int {
    var longest int = 0
    for i := 0; i < len(s); i++ {
        var reminder string = ""
        for j := i; j < len(s); j++ {
            if reminder != "" && s[j] == reminder[0] {
                break
            }
            if strings.Contains(reminder, string(s[j])) {
                break
            }
            reminder += string(s[j])
        }
        if len(reminder) > longest {
            longest = len(reminder)
        }
    }
    return longest
}