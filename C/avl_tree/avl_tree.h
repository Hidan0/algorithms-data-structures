#ifndef AVL
#define AVL

struct avl_node {
	int value;
	struct avl_node *l, *r;
};

typedef struct avl_node *Avl_Node;

void print_inorder(Avl_Node t);

int get_balanced_factor(Avl_Node t);

Avl_Node avl_insert(Avl_Node t, int k);
Avl_Node avl_delete(Avl_Node t, int k);

Avl_Node avl_rotate_right(Avl_Node p);
Avl_Node avl_rotate_left(Avl_Node p);

#endif
