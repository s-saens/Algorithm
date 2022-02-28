package main

import "fmt"

func main () {

	m := make(map[string] int)

	m["key1"] = 1
	m["key2"] = 2
	m["key3"] = 4
	m["key4"] = 8

	m = map[string]int{
		"key5" : 16,
		"key6" : 32,
		"key7" : 64,
	}

	for key, value := range m {
		fmt.Printf("KEY: %s\t", key)
		fmt.Printf("VAL: %d\n", value)
	}

	var r = []rune{'1', '2'}

	fmt.Println("AAAA + ", function1("asdasd", r));
}

func function1 (str string, any []rune) int {
	for i, ch:= range str {
		fmt.Println(i, string(ch))
	}
	return 1
}