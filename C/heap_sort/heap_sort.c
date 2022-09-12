#include <stdio.h>

void heapify(int *a, int size_a, int node);
void heap_sort(int *a, int size_a);
void heap_delete(int *a, int size_a);

#define PRINT_A(x, size)                                                       \
  printf("[ ");                                                                \
  for (int i = 0; i < size; i++)                                               \
    printf("%d ", *(x + i));                                                   \
  printf("]\n");

#define SWAP(a, from, to)                                                      \
  int tmp = a[from];                                                           \
  a[from] = a[to];                                                             \
  a[to] = tmp

int main() {
  int A[] = {10, 20, 15, 30, 12, 40, 25, 18, 19, 10};
  int size_a = 10;

  PRINT_A(A, size_a);
  heap_sort(A, size_a);
  PRINT_A(A, size_a);
  
  int B[] = { 104 };
  int size_b = 1;
  heap_sort(B, size_b);
  PRINT_A(B, size_b);

  return 1;
}

void heap_sort(int *a, int size_a) {
  // make a heap
  for (int i = size_a - 1; i >= 0; i--)
    heapify(a, size_a, i);

  for (int i = size_a; i >= 0; i--)
    heap_delete(a, i);
}

void heapify(int *a, int size_a, int node) {
  int l = node * 2 + 1;
  int r = node * 2 + 2;
  int max_i = node;

  if (l < size_a && a[l] > a[node])
    max_i = l;
  if (r < size_a && a[r] > a[node] && a[r] > a[l])
    max_i = r;

  if (max_i != node) {
    SWAP(a, max_i, node);
    heapify(a, size_a, max_i);
  }
}

void heap_delete(int *a, int size_a) {

  if (size_a <= 0) // last element
    return;

  int l = 1; // 2 * i + 1 where i = 0
  int r = 2; // 2 * i + 2 where i = 0

  int max_i = 0;
  if (l < size_a && r < size_a && a[l] < a[r])
    max_i = r;
  else
    max_i = l;

  SWAP(a, 0, size_a - 1);
  heapify(a, size_a - 1, 0);
}
