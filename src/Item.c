#include "../libs/Item.h"

struct ITEM {
  int id;
  char description[40];
  float price;
};

int isNullItem(Item item) {
  if (item == NULL)
    return 1;
  
  return 0;
}

Item new_Item(int id, const char *description, float price) {
  
  Item item = (Item) malloc(sizeof(struct ITEM));

  if (isNullItem(item))
    return NULL;

  item->id = id;
  strcpy(item->description, description);
  item->price = price;

  return item;
}

void destruct_Item(Item item) {
  if (!isNullItem(item))
    free(item);
}

int item_getId(Item item) {
  
  if (isNullItem(item))
    return -1;

  
  return item->id;
}

const char* item_getDescription(Item item) {
  
  if (isNullItem(item))
    return NULL;

  return item->description;
}

float item_getPrice(Item item) {
  if (isNullItem(item))
    return 0;

  return item->price;
}

int item_isEquals(Item item, Item itemCompared) {

  if (item->id == itemCompared->id
    && strcmp(item_getDescription(item), item_getDescription(itemCompared)) == 0
  ) {
    return 1;
  }

  return 0;
}