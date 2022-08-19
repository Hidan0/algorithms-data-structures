package main

import "fmt"

func main() {
	a := []int{9, 12, 3, 6, 4, 0, 3, 22, 7}

	fmt.Println("Unordered: ", a)
	quickSort(&a)
	fmt.Println("Ordered: ", a)
}

func quickSort(a *[]int) {
	quick_sort(a, 0, len(*a))
}

func quick_sort(a *[]int, start int, end int) {
	for end-start > 1 {
		m := partition(a, start, end)
		if m-start < end-m {
			quick_sort(a, start, m)
			start = m + 1
		} else {
			quick_sort(a, m+1, end)
			end = m
		}
	}
}

func partition(a *[]int, start int, end int) int {
	pivot := (*a)[start]
	sx := start
	dx := end

	for sx < dx {

		for ok := true; ok; ok = (*a)[dx] > pivot {
			dx -= 1
		}

		for ok := true; ok; ok = sx < dx && (*a)[sx] <= pivot {
			sx += 1
		}

		if sx < dx {
			swap(a, sx, dx)
		}
	}

	swap(a, start, dx)
	return dx
}

func swap(a *[]int, from int, to int) {
	tmp := (*a)[from]
	(*a)[from] = (*a)[to]
	(*a)[to] = tmp
}
