#include <stdio.h>

#define PRINT_A(a, size_a)           \
  printf("[ ");                      \
  for (int i = 0; i < size_a; i++) { \
    printf("%d ", a[i]);             \
  }                                  \
  printf("]\n");                     \

void selection_sort(int *a, int size_a);

int main() {
  int a[] = {9, 10, 7, 2, 66, 5, 8, 0, 2};
  int size_a = 9;
   
  printf("Unordered: ");
  PRINT_A(a, size_a);
  selection_sort(a, size_a);
  printf("Ordered: ");
  PRINT_A(a, size_a);
}

void selection_sort(int *a, int size_a) {
  for (int k = 0; k <= size_a - 2; k++) {
    int m = k;
    for (int j = k + 1; j <= size_a - 1; j++) {
      if (*(a + j) < *(a + m)) {
        m = j; 
      }
    }
    int tmp = *(a + m);
    *(a + m) = *(a + k);
    *(a + k) = tmp;
  }
}
