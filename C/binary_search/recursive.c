#include <stdio.h>

int binary_search(int *a, int a_size, int x);
int rec_search(int *a, int sx, int dx, int x);

int main() {
  int a[] = {0, 1, 3, 6, 10, 12, 30, 32, 50};
  int size = 9;

  int search = 10;
  printf("Searching %i... index: %d\n", search, binary_search(a, size, search));

  search = 1;
  printf("Searching %i... index: %d\n", search, binary_search(a, size, search));

  search = 32;
  printf("Searching %i... index: %d\n", search, binary_search(a, size, search));

  search = 2;
  printf("Searching %i... index: %d\n", search, binary_search(a, size, search));

  return 1;
}

int binary_search(int *a, int a_size, int x) {
  return rec_search(a, 0, a_size, x);
}

int rec_search(int *a, int sx, int dx, int x) {
  if (dx <= sx) {
    return -1;
  }

  int m = (sx + dx) / 2;
  if (x == *(a + m)) {
    return m;
  } else if (x < *(a + m)) {
    return rec_search(a, sx, m, x);
  } else {
    return rec_search(a, m + 1, dx, x);
  }
}
