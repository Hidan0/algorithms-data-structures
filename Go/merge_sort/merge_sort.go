package main

import "fmt"

func main() {
	a := []int{9, 12, 3, 6, 4, 0, 3, 22, 7}

	fmt.Println("Unordered: ", a)
	mergeSort(&a)
	fmt.Println("Ordered: ", a)
}

func mergeSort(a *[]int) {
	X := make([]int, len(*a))
	merge_sort(a, 0, len(*a), &X)
}

func merge_sort(a *[]int, start int, end int, X *[]int) {
	if end-start > 1 {
		m := (start + end) / 2
		merge_sort(a, start, m, X)
		merge_sort(a, m, end, X)
		merge(a, start, m, end, X)
	}
}

func merge(a *[]int, start int, m int, end int, X *[]int) {
	start_1 := start
	start_2 := m
	k := 0
	for start_1 < m && start_2 < end {
		if (*a)[start_1] <= (*a)[start_2] {
			(*X)[k] = (*a)[start_1]
			start_1 += 1
		} else {
			(*X)[k] = (*a)[start_2]
			start_2 += 1
		}
		k += 1
	}

	if start_1 < m {
		for j := start_1; j < m; j++ {
			(*X)[k] = (*a)[j]
			k += 1
		}
	} else {
		for j := start_2; j < end; j++ {
			(*X)[k] = (*a)[j]
			k += 1
		}
	}

	for k := 0; k < end-start; k++ {
		(*a)[start+k] = (*X)[k]
	}
}