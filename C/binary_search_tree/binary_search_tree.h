#ifndef BIST
#define BIST
// BInary Search Tree

struct bist_node {
  int key;
  struct bist_node *l, *r;
};

typedef struct bist_node *Bist_node;

void bist_inorder(Bist_node t);

Bist_node bist_max(Bist_node t);
Bist_node bist_min(Bist_node t);

Bist_node bist_find(Bist_node t, int k);

Bist_node bist_insert(Bist_node t, int k);
Bist_node bist_remove(Bist_node t, int k);

#endif
