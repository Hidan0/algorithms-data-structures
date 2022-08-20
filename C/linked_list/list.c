#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Node list = NULL;
  print_list(list);
  list = insert_to_head(list, 3);
  print_list(list);
  insert_to_tail(list, 5);
  list = insert_to_head(list, 2);
  list = insert_to_head(list, 0);
  print_list(list);
  insert_to_tail(list, 6);
  print_list(list);
  list = remove_value(list, 0);
  print_list(list);
  list = remove_value(list, 6);
  print_list(list);
  list = remove_value(list, 3);
  print_list(list);
  list = remove_value(list, 15);
  print_list(list);
  return 1;
}

struct node {
  int value;
  struct node *next;
};

void print_list(Node head) {
  printf("[ ");
  for (Node current = head; current != NULL; current = current->next) {
    printf("%d ", current->value);
  }
  printf("]\n");
}

Node insert_to_head(Node head, int value) {
  Node new = malloc(sizeof(Node));
  ASSERT_PTR(new);
  new->value = value;
  new->next = head;
  return new;
}

void insert_to_tail(Node head, int value) {
  if (head == NULL) {
    Node new = malloc(sizeof(Node));
    ASSERT_PTR(new);
    new->value = value;
    new->next = NULL;
  }

  Node curr = head;
  while (curr->next != NULL)
    curr = curr->next;

  Node new = malloc(sizeof(Node));
  ASSERT_PTR(new);
  new->value = value;
  new->next = NULL;
  curr->next = new;
}

Node find(Node head, int value) {
  for (Node p = head; p->next != NULL; p = p->next) {
    if (p->value == value)
      return p;
  }
  return NULL;
}

Node remove_value(Node head, int value) {
  Node prev, curr;
  for (prev = NULL, curr = head; curr != NULL && curr->value != value;
       prev = curr, curr = curr->next)
    ;

  if (curr == NULL)
    return head;

  if (prev == NULL) {
    Node p = curr->next;
    free(curr);
    return p;
  }

  prev->next = curr->next;
  free(curr);
  return head;
}
