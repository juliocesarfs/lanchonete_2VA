#ifndef BOOK_STACK_H
#define BOOK_STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct BOOK_STACK *BookStack;

int isNullBookStack(BookStack bookStack);

BookStack new_BookStack();

void destruct_BookStack(BookStack bookStack);

BookStack bookStack_add(BookStack bookStack, const char* name);

void bookStack_remove(BookStack bookStack);

char* bookStack_getBook(BookStack bookStack);

void bookStack_toPrint(BookStack bookStack);

#endif