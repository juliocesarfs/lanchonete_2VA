#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ITEM *Item;

Item new_Item(int id, const char *description, float price);

void destruct_Item(Item item);

int item_getId(Item item);

const char* item_getDescription(Item item);

float item_getPrice(Item item);

int item_isEquals(Item item, Item itemCompared);

#endif