package main

import "fmt"

func main() {
	a := []int{9, 12, 3, 6, 4, 0, 3, 22, 7}

	fmt.Println("Unordered: ", a)
	bubble_sort(&a)
	fmt.Println("Ordered: ", a)
}

func swap(a *[]int, from int, to int) {
	tmp := (*a)[from]
	(*a)[from] = (*a)[to]
	(*a)[to] = tmp
}

func bubble_sort(a *[]int) {
	i := 1
	var has_changed bool

	for {
		has_changed = false
		for j := 1; j <= len(*a)-i; j++ {
			if (*a)[j] < (*a)[j-1] {
				swap(a, j, j-1)
				has_changed = true
			}
		}
		i++

		if !has_changed && i > len(*a) {
			break
		}
	}
}
