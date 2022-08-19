#include <stdio.h>

#define SWAP(a, from, to)                                                      \
  int tmp = a[from];                                                           \
  a[from] = a[to];                                                             \
  a[to] = tmp

#define PRINT_A(a, size_a)                                                     \
  printf("[ ");                                                                \
  for (int i = 0; i < size_a; i++) {                                           \
    printf("%d ", a[i]);                                                       \
  }                                                                            \
  printf("]\n");

int partition(int *a, int start, int end);
void m_quick_sort(int *a, int start, int end);
void quick_sort(int *a, int size_a);

int main() {
  int a[] = {8, 20, 12, 9, 11, 42, 51, 3, 2, 35};
  int size_a = 10;
  
  printf("Unordered: ");
  PRINT_A(a, size_a);
  quick_sort(a, size_a);
  printf("Ordered: ");
  PRINT_A(a, size_a);
    
  return 1;
}

void quick_sort(int *a, int size_a) { m_quick_sort(a, 0, size_a); }

int partition(int *a, int start, int end) {
  int pivot = a[start];
  int sx = start;
  int dx = end;
  while (sx < dx) {
    do {
      dx -= 1;
    } while (a[dx] > pivot);

    do {
      sx += 1;
    } while (sx < dx && a[sx] <= pivot);

    if (sx < dx) {
      SWAP(a, sx, dx);
    }
  }
  SWAP(a, start, dx);
  return dx;
}

void m_quick_sort(int *a, int start, int end) {
  while (end - start > 1) {
    int m = partition(a, start, end);
    if (m - start < end - m) {
      m_quick_sort(a, start, m);
      start = m + 1;
    } else {
      m_quick_sort(a, m + 1, end);
      end = m;
    }
  }
}
