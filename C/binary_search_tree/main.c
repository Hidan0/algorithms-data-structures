#include "binary_search_tree.h"
#include <stdio.h>

#define ASSERT_EQ(x, y)                                                        \
  if (x != y) {                                                                \
    printf("[ERR] assert error %s:%d\n", __FILE__, __LINE__);                  \
    return -1;                                                                 \
  }

int main() {
  Bist_node t = bist_insert(NULL, 50);
  t = bist_insert(t, 25);
  t = bist_insert(t, 65);
  t = bist_insert(t, 20);
  t = bist_insert(t, 14);
  t = bist_insert(t, 32);
  t = bist_insert(t, 5);

  bist_inorder(t);
  printf("\nMax: %d\n", bist_max(t)->key);
  printf("Min: %d\n", bist_min(t)->key);

  ASSERT_EQ(NULL, bist_find(t, 100));
  ASSERT_EQ(14, bist_find(t, 14)->key);
  
  //leaf 
  t = bist_remove(t, 65);
  bist_inorder(t);
  printf("\n");

  t = bist_remove(t, 25);
  bist_inorder(t);

  // root
  t = bist_remove(t, 50);
  printf("\n");
  bist_inorder(t);

  return 1;
}
