#include "../libs/BookStack.h"

struct BOOK_STACK {
  char name[40];
  struct BOOK_STACK *next;
};

int isNullBookStack(BookStack bookStack) {
  if (bookStack == NULL)
    return 1;
  
  return 0;
}

BookStack new_BookStack() {

  BookStack bookStack = (BookStack) malloc(sizeof(struct BOOK_STACK));

  if (isNullBookStack(bookStack))
    return NULL;

  bookStack->next = NULL;
  strcpy(bookStack->name, "null");

  return bookStack;
}

void destruct_BookStack(BookStack bookStack) {

  if (isNullBookStack(bookStack))
    return;

  BookStack node = bookStack->next;

  while (!isNullBookStack(node)) {
    BookStack aux = node->next;
    free(node);
    node = aux;
  }

  free(bookStack);
}

BookStack bookStack_add(BookStack bookStack, const char* name) {
  if (isNullBookStack(bookStack) || name == NULL)
    return bookStack;
  
  BookStack *new;
  BookStack newNode = (BookStack) malloc(sizeof(struct BOOK_STACK));

  strcpy(newNode->name, name);
  newNode->next = bookStack->next;

  bookStack->next = newNode;

  return bookStack;
}

void bookStack_remove(BookStack bookStack) {
  BookStack topElement;
  topElement = bookStack->next;

  bookStack->next = topElement->next;
  free(topElement);
}

char* bookStack_getBookByName(BookStack bookStack) {
  return bookStack->next->name;
}

void bookStack_toPrint(BookStack bookStack) {
  BookStack node = bookStack->next;

  if (isNullBookStack(bookStack) || isNullBookStack(node)) {
    printf("[ ]\n");
    return;
  }

  printf("Pilha de livros:\n");
  while (!isNullBookStack(node)) {
    printf("%s\n", node->name);
    node = node->next;
  }
}

