#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

#define ASSERT_PTR(x)                                                          \
  if (x == NULL) {                                                             \
    printf("Mem error.");                                                      \
    exit(EXIT_FAILURE);                                                        \
  }

void bist_inorder(Bist_node t) {
  if (t) {
    bist_inorder(t->l);
    printf("%d ", t->key);
    bist_inorder(t->r);
  }
}

Bist_node bist_max(Bist_node t) {
  if (t == NULL)
    return NULL;

  Bist_node n = t;
  while (n->r) {
    n = n->r;
  }
  return n;
}

Bist_node bist_min(Bist_node t) {
  if (t == NULL)
    return NULL;

  Bist_node n = t;
  while (n->l) {
    n = n->l;
  }
  return n;
}

// Recursive binary search
// Bist_node bist_find(Bist_node t, int k) {
//   if (t == NULL)
//     return NULL;

//   if (k < t->key) {
//     return bist_find(t->l, k);
//   } else if (k > t->key) {
//     return bist_find(t->r, k);
//   }
//   return t;
// }

// Iterative binary search
Bist_node bist_find(Bist_node t, int k) {
  Bist_node p;
  for (p = t; p != NULL && p->key != k; p = k < p->key ? p->l : p->r)
    ;
  return p;
}

// Recursive insert
Bist_node bist_insert(Bist_node t, int k) {
  if (t == NULL) {
    Bist_node n = malloc(sizeof(struct bist_node));
    ASSERT_PTR(n);
    n->key = k;
    return n;
  }

  if (k < t->key) {
    t->l = bist_insert(t->l, k);
  } else {
    t->r = bist_insert(t->r, k);
  }
  return t;
}

// Iterative insert
// Bist_node bist_insert(Bist_node t, int k) {
//   Bist_node n = malloc(sizeof(struct bist_node));
//   ASSERT_PTR(n);
//   n->key = k;

//   Bist_node father = NULL;
//   Bist_node p = t;
//   while (p != NULL) {
//     father = p;
//     p = k < p->key ? p->l : p->r;
//   }

//   if (father == NULL)
//     return n;
//   else if (k < father->key)
//     father->l = n;
//   else
//     father->r = n;

//   return t;
// }

Bist_node bist_remove(Bist_node t, int k) {
  Bist_node father = NULL;
  Bist_node p = t;

  while (p != NULL && p->key != k) {
    father = p;
    p = k < p->key ? p->l : p->r;
  }

  if (p != NULL) {
    if (p->l == NULL) {
      if (father != NULL) {
        if (p->key < father->key)
          father->l = p->r;
        else
          father->r = p->r;
      } else {
        t = t->r;
      }
      free(p);
    } else if (p->r == NULL) {
      if (father != NULL) {
        if (p->key < father->key)
          father->l = p->l;
        else
          father->r = p->l;
      } else {
        t = t->l;
      }
      free(p);
    } else {
      Bist_node f_max = p;
      Bist_node max = p->l;
      while (max->r != NULL) {
        f_max = max;
        max = max->r;
      }

      p->key = max->key;
      if (f_max == p)
        p->l = max->l;
      else
        f_max->r = max->l;
      free(max);
    }
  }

  return t;
}