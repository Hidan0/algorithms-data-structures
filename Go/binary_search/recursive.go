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
	return rec_search(a, 0, len(*a), x)
}

func rec_search(a *[]int, sx int, dx int, x int) int {
	if dx <= sx {
		return -1
	}
	var m int = (sx + dx) / 2
	if x == (*a)[m] {
		return m
	} else if x < (*a)[m] {
		return rec_search(a, sx, m, x)
	}
	return rec_search(a, m+1, dx, x)
}
