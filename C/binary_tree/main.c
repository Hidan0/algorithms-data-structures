#include "binary_tree.h"
#include <stdio.h>

int main() {
  Bit_node my_tree = bit_new(10);
  my_tree->l = bit_new(20);
  my_tree->r = bit_new(30);
  my_tree->r->l = bit_new(35);
  my_tree->l->l = bit_new(40);
  my_tree->l->l->r = bit_new(60);

  printf("Tree pre-order: ");
  bit_preorder(my_tree);

  printf("\nTree in-order: ");
  bit_inorder(my_tree);

  printf("\nTree post-order: ");
  bit_postorder(my_tree);

  Item a[] = {69, 89, 28, 39, 66, 44, 12, 2, 71};
  Bit_node from = bit_from(a, 9, 0);
  printf("\nFrom arr to bin: ");
  bit_preorder(from);
  
  printf("\n\nSummary:\n");
  bit_print_summary(from);
  return 1;
}
