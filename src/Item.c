#include "../libs/Item.h"

struct ITEM {
  int id;
  char description[40];
  float price;
};

int isNull(Item item) {
  if (item == NULL)
    return 1;
  
  return 0;
}

Item new_Item(int id, const char *description, float price) {
  
  Item item = (Item) malloc(sizeof(struct ITEM));

  if (isNull(item))
    return NULL;

  item->id = id;
  strcpy(item->description, description);

  return item;
}

void destruct_Item(Item item) {
  if (!isNull(item))
    free(item);
}

int item_getId(Item item) {
  
  if (isNull(item))
    return -1;

  
  return item->id;
}

const char* item_getDescription(Item item) {
  
  if (isNull(item))
    return NULL;

  return item->description;
}

float item_getPrice(Item item) {
  if (isNull(item))
    return 0;

  return item->price;
}
