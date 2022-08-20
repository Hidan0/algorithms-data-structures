#ifndef LIST
#define LIST

#define ASSERT_PTR(x)                                                          \
  if (x == NULL) {                                                             \
    printf("Mem err.");                                                        \
    exit(EXIT_FAILURE);                                                        \
  }

typedef struct node *Node;

Node insert_to_head(Node head, int value);

void insert_to_tail(Node head, int value);

void print_list(Node head);

Node find(Node head, int value);

Node remove_value(Node head, int value);

Node insert_ordered(Node head, int value);

#endif