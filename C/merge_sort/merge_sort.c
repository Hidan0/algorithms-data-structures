#include <stdio.h>

#define PRINT_A(a, size_a)                                                     \
  printf("[ ");                                                                \
  for (int i = 0; i < size_a; i++) {                                           \
    printf("%d ", a[i]);                                                       \
  }                                                                            \
  printf("]\n");

void merge_sort(int *a, int size_a);
void r_merge_sort(int *a, int start, int end, int *X);
void merge(int *a, int start, int m, int end, int *X);

int main() {
  int a[] = {9, 10, 3, 7, 2, 66, 5, 8, 0, 2};
  int size_a = 10;

  printf("Unordered: ");
  PRINT_A(a, size_a);
  merge_sort(a, size_a);
  printf("Ordered: ");
  PRINT_A(a, size_a);

  return 1;
}

void merge_sort(int *a, int size_a) {
  int X[size_a];
  r_merge_sort(a, 0, size_a, X);
}

void r_merge_sort(int *a, int start, int end, int *X) {
  if (end - start > 1) {
    int m = (start + end) / 2;
    r_merge_sort(a, start, m, X);
    r_merge_sort(a, m, end, X);
    merge(a, start, m, end, X);
  }
}

void merge(int *a, int start, int m, int end, int *X) {
  int start_1 = start;
  int start_2 = m;
  int k = 0;
  while (start_1 < m && start_2 < end) {
    if (a[start_1] <= a[start_2]) {
      X[k] = a[start_1];
      start_1 += 1;
    } else {
      X[k] = a[start_2];
      start_2 += 1;
    }
    k += 1;
  }

  if (start_1 < m) {
    for (int j = start_1; j < m; j++) {
      X[k] = a[j];
      k += 1;
    }
  } else {
    for (int j = start_2; j < end; j++) {
      X[k] = a[j];
      k += 1;
    }
  }

  for (int k = 0; k < end - start; k++) {
    a[start + k] = X[k];
  }
}
