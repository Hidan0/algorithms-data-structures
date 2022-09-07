#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>

#define ASSERT_PTR(x)                                                          \
  if (!x) {                                                                    \
    printf("Memory error at %s:%d", __FILE__, __LINE__);                       \
    exit(EXIT_FAILURE);                                                        \
  }

Avl_Node avl_insert(Avl_Node t, int k) {
  if (!t) {
    Avl_Node new = malloc(sizeof(struct avl_node));
    ASSERT_PTR(new);
    new->value = k;
    return new;
  }

  if (k < t->value) {
    t->l = avl_insert(t->l, k);
  } else {
    t->r = avl_insert(t->r, k);
  }

  int bf = get_balanced_factor(t);

  if (bf > 1 && k > t->l->value)
    return avl_rotate_right(t);

  if (bf < -1 && k < t->r->value)
    return avl_rotate_left(t);

  if (bf > 1 && k > t->l->value) {
    t->l = avl_rotate_left(t->l);
    return avl_rotate_right(t);
  }
  if (bf < -1 && k < t->r->value) {
    t->r = avl_rotate_right(t->r);
    return avl_rotate_left(t);
  }

  return t;
}

int height(Avl_Node t) {
  if (!t)
    return -1;

  int lh = height(t->l);
  int rh = height(t->r);

  return lh > rh ? lh + 1 : rh + 1;
}

int get_balanced_factor(Avl_Node t) { return height(t->l) - height(t->r); }

// right rotation of the pivot
Avl_Node avl_rotate_right(Avl_Node a) {
  Avl_Node b = a->l;
  Avl_Node t2 = b->r;

  a->l = t2;
  b->r = a;

  return b;
}

// left rotation of the pivot
Avl_Node avl_rotate_left(Avl_Node a) {
  Avl_Node b = a->r;
  Avl_Node t2 = b->l;

  a->r = t2;
  b->l = a;

  return b;
}

void print_inorder(Avl_Node t) {
  if (t) {
    print_inorder(t->l);
    printf("%d ", t->value);
    print_inorder(t->r);
  }
}

Avl_Node avl_max(Avl_Node t) {
  if (t == NULL)
    return NULL;

  Avl_Node n = t;
  while (n->r) {
    n = n->r;
  }
  return n;
}

Avl_Node avl_delete(Avl_Node t, int k) {
  if (!t)
    return NULL;

  if (k < t->value)
    t->l = avl_delete(t->l, k);
  else if (k > t->value)
    t->r = avl_delete(t->r, k);
  // else is root
  else {
    if (!t->l) { // left child is null
      Avl_Node tmp = t->r;
      free(t);
      return tmp;
    } else if (!t->r) {
      Avl_Node tmp = t->l;
      free(t);
      return tmp;
    } else {
      Avl_Node max = avl_max(t->l);
      t->value = max->value;
      free(max);
      // avl_delete(t->l, max->value);
    }
  }
  
  int bf = get_balanced_factor(t);
  
  if (bf == 2 && get_balanced_factor(t->l) >= 0) {
    return avl_rotate_right(t);
  } else if (bf == 2 && get_balanced_factor(t->l) == -1) {
    t->l = avl_rotate_left(t->l);
    return avl_rotate_right(t);
  }

  if (bf == -2 && get_balanced_factor(t->r) <= 0) {
    return avl_rotate_right(t);
  } else if (bf == -2 && get_balanced_factor(t->r) == 1) {
    t->r = avl_rotate_right(t->r);
    return avl_rotate_left(t);
  }
  return t;
}
