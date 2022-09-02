#ifndef BINARY_TREE_H
#define BINARY_TREE_H
// BIT = BInary-Tree

#ifndef Item
#define Item int
#endif

struct bit_node {
  Item item;
  struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

Bit_node bit_new(Item k);

/**
 * @brief Creates a binary tree from an array of size `size_a`. The root is a[i]. Left child is a[2*i + 1], right child is a[2*i+2].
 *
 * @param a The source array.
 * @param size_a The size of the array.
 * @param i The index of the starting point (root).
 */
Bit_node bit_from(Item a[], int size_a, int i);

void bit_printnode(Bit_node t);

void bit_inorder(Bit_node t);
void bit_preorder(Bit_node t);
void bit_postorder(Bit_node t);

/**
  * @brief Prints the binary tree as if it was a book summary.
*/
void bit_print_summary(Bit_node t);

#endif
