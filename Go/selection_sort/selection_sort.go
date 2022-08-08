package main

import "fmt"

func main() {
	a := []int{9, 12, 3, 6, 4, 0, 3, 22, 7}

	fmt.Println("Unordered: ", a)
	selection_sort(&a)
	fmt.Println("Ordered: ", a)
}

func selection_sort(a *[]int) {
	for k := 0; k <= len(*a)-2; k++ {
		m := k
		for j := k + 1; j <= len(*a)-1; j++ {
			if (*a)[j] < (*a)[m] {
				m = j
			}
		}
		tmp := (*a)[k]
		(*a)[k] = (*a)[m]
		(*a)[m] = tmp
	}
}
