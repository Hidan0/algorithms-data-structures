#include "avl_tree.h"
#include <stdio.h>

#define ASSERT_EQ(x, y)                                                        \
  if (x != y) {                                                                \
    printf("[ERR] assert error %s:%d\n", __FILE__, __LINE__);                  \
    return -1;                                                                 \
  }

int main() {
  Avl_Node t = avl_insert(NULL, 15);
  t = avl_insert(t, 10);
  t = avl_insert(t, 6);
  t = avl_insert(t, 7);
  t = avl_insert(t, 8);
  t = avl_insert(t, 3);
  t = avl_insert(t, 4);
  print_inorder(t);
  
  t = avl_delete(t, 4);
  t = avl_delete(t, 6);
  t = avl_delete(t, 3);
  t = avl_delete(t, 15);
  printf("\n");
  print_inorder(t);
  return 1;
}
