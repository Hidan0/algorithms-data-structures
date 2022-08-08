package main

import "fmt"

func main() {
	a := []int{9, 12, 3, 6, 4, 0, 3, 22, 7}

	fmt.Println("Unordered: ", a)
	insertion_sort(&a)
	fmt.Println("Ordered: ", a)
}

func insertion_sort(a *[]int) {
	for k := 1; k < len(*a); k++ {
		x := (*a)[k]
		j := k - 1
		for j >= 0 && (*a)[j] > x {
			(*a)[j+1] = (*a)[j]
			j--
		}
		(*a)[j+1] = x
	}
}