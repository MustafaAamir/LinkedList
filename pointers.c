#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int num;
  struct NODE *next;
};

int lengthCheck(struct NODE *header) {
  int count = 0;
  struct NODE *current = header;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

struct NODE *firstThreenums() {
  struct NODE *header = NULL;
  struct NODE *second = NULL;
  struct NODE *third = NULL;

  header = malloc(sizeof(struct NODE));
  second = malloc(sizeof(struct NODE));
  third = malloc(sizeof(struct NODE));

  header->num = 'a';
  header->next = second;
  header->next->num = 'b';
  header->next->next = third;
  header->next->next->num = 'c';
  header->next->next->next = NULL;

  return header;
}

void printingElements(struct NODE *LinkedList) {
  int len = lengthCheck(LinkedList);
  if (len == 0) {
    printf("there are not elements.");
  } else {
    struct NODE *current = LinkedList;
    for (int i = 0; i < len; i++) {
      printf("%d = %d\n", i, current->num);
      current = current->next;
    }
    printf("\n\n");
  }
}

struct NODE *allocate(struct NODE **LinkedList, int num) {
  struct NODE *newnode;
  newnode = malloc(sizeof(struct NODE));
  newnode->num = num;
  newnode->next = *LinkedList;
  *LinkedList = newnode;
  return *LinkedList;
}

struct NODE *pop(struct NODE **LinkedList) { return *LinkedList; }

int main(void) {
  struct NODE *MyLinkedList = NULL;
  printf("linkedlist length: %d\n", lengthCheck(MyLinkedList));
  printingElements(MyLinkedList);

  // allocation
  allocate(&MyLinkedList, 1);
  allocate(&MyLinkedList, 2);
  allocate(&MyLinkedList, 3);
  allocate(&MyLinkedList, 4);
  printingElements(MyLinkedList);
  pop(&MyLinkedList);
  printingElements(MyLinkedList);
  return 0;
}
