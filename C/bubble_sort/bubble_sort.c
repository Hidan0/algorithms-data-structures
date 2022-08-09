#include <stdbool.h>
#include <stdio.h>

#define PRINT_A(a, size_a)                                                     \
  printf("[ ");                                                                \
  for (int i = 0; i < size_a; i++) {                                           \
    printf("%d ", a[i]);                                                       \
  }                                                                            \
  printf("]\n");

void bubble_sort(int *a, int size_a);
void bubble_sort_knuth(int *a, int size_a);
void swap(int *a, int from, int to);

int main() {

  int a[] = {9, 10, 3, 7, 2, 66, 5, 8, 0, 2};
  int size_a = 10;

  printf("Unordered: ");
  PRINT_A(a, size_a);
  bubble_sort(a, size_a);
  printf("Ordered: ");
  PRINT_A(a, size_a);

  int b[] = {9, 10, 3, 7, 2, 6, 5, 8, 21, 2};

  printf("Unordered: ");
  PRINT_A(b, size_a);
  bubble_sort_knuth(b, size_a);
  printf("Ordered: ");
  PRINT_A(b, size_a);
}

void swap(int *a, int from, int to) {
  int tmp = a[from];
  a[from] = a[to];
  a[to] = tmp;
}

void bubble_sort(int *a, int size_a) {
  int i = 1;
  bool has_changed;
  do {
    has_changed = false;
    for (int j = 1; j <= size_a - i; j++) {
      if (a[j] < a[j - 1]) {
        swap(a, j, j-1);
        has_changed = true;
      }
    }
    i += 1;
  } while (has_changed && i <= size_a);
}

void bubble_sort_knuth(int *a, int size_a) {
  int first_in_order = size_a;
  int t;
  do {
    t = 0;
    for (int j = 1; j < first_in_order; j++) {
      if (a[j] < a[j - 1]) {
        swap(a, j, j-1);
        t = j;
      }
    }
    first_in_order = t;
  } while (t > 0);
}
