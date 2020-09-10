// rename.go -- rename file names (Go version)

package main

import (
	"os"
	"fmt"
	"strings"
)

func usage() {
	fmt.Println("usage: rename current_string replacement file_pattern")
	os.Exit(1)
}

func main() {
	if len(os.Args) < 4 {
		usage()
	}
	currentString := os.Args[1]
	replaceString := os.Args[2]
	files := os.Args[3:]
	var new_file string
	var err error
	for _, file := range files {
		new_file = strings.ReplaceAll(file, currentString, replaceString)
		err = os.Rename(file, new_file)
		if err != nil {
			fmt.Println(err)
			os.Exit(1)
		}
	}
}
