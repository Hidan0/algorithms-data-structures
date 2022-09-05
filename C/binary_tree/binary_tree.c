#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

#define ASSERT_PTR(x)                                                          \
  if (x == NULL) {                                                             \
    printf("Memory error.");                                                   \
    exit(EXIT_FAILURE);                                                        \
  }

Bit_node bit_new(Item k) {
  Bit_node t = malloc(sizeof(struct bit_node));
  ASSERT_PTR(t);
  t->item = k;
  return t;
}

void bit_printnode(Bit_node t) { printf("%d", t->item); }

void bit_inorder(Bit_node t) {
  if (t) {
    bit_inorder(t->l);
    printf(" ");
    bit_printnode(t);
    bit_inorder(t->r);
  }
}

void bit_preorder(Bit_node t) {
  if (t) {
    bit_printnode(t);
    printf(" ");
    bit_preorder(t->l);
    bit_preorder(t->r);
  }
}
void bit_postorder(Bit_node t) {
  if (t) {
    bit_postorder(t->l);
    bit_postorder(t->r);
    printf(" ");
    bit_printnode(t);
  }
}

Bit_node bit_from(Item a[], int size_a, int i) {
  if (i < size_a) {
    Bit_node root = bit_new(*(a + i));
    root->l = bit_from(a, size_a, 2 * i + 1);
    root->r = bit_from(a, size_a, 2 * i + 2);
    return root;
  }
  return NULL;
}

void m_bit_print_summary(Bit_node t, int spacing) {
  if (t) {
    if (spacing > 0) {
      for (int i = 0; i < spacing; i++)
        printf("  ");
    }
    printf("*%d\n", t->item);

    m_bit_print_summary(t->l, spacing + 1);
    m_bit_print_summary(t->r, spacing + 1);
  }
}

void bit_print_summary(Bit_node t) { m_bit_print_summary(t, 0); }
