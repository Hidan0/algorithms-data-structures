#include <stdio.h>

int binary_search(int *a, int a_size, int x);

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
  int sx = 0;
  int dx = a_size;
  int pos = -1;

  while ((sx < dx) && pos == -1) {
    int m = (sx + dx) / 2;
    if (x == *(a + m)) {
      pos = m;
    } else if (x < *(a + m)) {
      dx = m;
    } else {
      sx = m + 1;
    }
  }
  return pos;
}
