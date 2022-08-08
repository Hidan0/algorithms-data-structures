#include <stdio.h>

#define PRINT_A(a, size_a)           \
  printf("[ ");                      \
  for (int i = 0; i < size_a; i++) { \
    printf("%d ", a[i]);             \
  }                                  \
  printf("]\n");                     \

void insertion_sort(int *a, int size_a);

int main() {
  int a[] = {9, 10, 3, 7, 2, 66, 5, 8, 0, 2};
  int size_a = 10;
   
  printf("Unordered: ");
  PRINT_A(a, size_a);
  insertion_sort(a, size_a);
  printf("Ordered: ");
  PRINT_A(a, size_a);
}

void insertion_sort(int *a, int size_a) {
    for (int k = 1; k < size_a; k++) {
        int x = *(a + k);
        int j = k - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;          
        }
        a[j+1] = x;
    }
}
