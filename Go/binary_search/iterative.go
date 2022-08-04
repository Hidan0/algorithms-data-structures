package main

import "fmt"

func main() {
	a := []int{0, 1, 3, 6, 10, 12, 30, 32, 50}

	search := 10

	fmt.Println("Searching", search, "... index:", binary_search(&a, search))
	search = 1
	fmt.Println("Searching", search, "... index:", binary_search(&a, search))
	search = 32
	fmt.Println("Searching", search, "... index:", binary_search(&a, search))
	search = 2
	fmt.Println("Searching", search, "... index:", binary_search(&a, search))
}

func binary_search(a *[]int, x int) int {
	sx := 0
	dx := len(*a)
	pos := -1

	for dx > sx && pos == -1 {
		m := (sx + dx) / 2
		if x == (*a)[m] {
			pos = m
		} else if x < (*a)[m] {
			dx = m
		} else {
			sx = m + 1
		}
	}
	return pos
}
