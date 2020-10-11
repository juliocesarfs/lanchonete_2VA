#include "../libs/Menu.h"

struct MENU {
  Item item;
  struct MENU *next;
};

int isNullMenu(Menu menu) {
  if (menu == NULL)
    return 1;
  
  return 0;
}

Menu new_Menu() {
  Menu menu = (Menu) malloc(sizeof(struct MENU));

  if (isNullMenu(menu))
    return NULL;

  menu->item = NULL;
  menu->next = NULL;

  return menu;
}

void destruct_Menu(Menu menu) {
  Menu node = menu->next;

  while (!isNullMenu(node)) {
    Menu aux = node->next;
    destruct_Item(node->item);
    free(node);
    node = aux;
  }

  free(menu);
}

Menu menu_add(Menu menu, Item item) {

  if (isNullMenu(menu))
    return menu;
  
  Menu node = menu->next;

  Menu newNode = new_Menu();
  newNode->item = item;

  newNode->next = node;
  menu->next = newNode;

  return menu;
}

void menu_remove(Menu menu, Item item) {
  if (isNullMenu(menu) || item == NULL)
    return;
  
  Menu prev = NULL;
  Menu node = menu->next;

  while (!isNullMenu(node) && !item_isEquals(node->item, item)) {
    prev = node;
    node = node->next;
  }

  if (isNullMenu(prev)) {
    menu->next = node->next;
  } else {
    prev->next = node->next;
  }

  destruct_Item(node->item);
  free(node);
}

Item menu_getItemById(Menu menu, int id) {

  if (isNullMenu(menu))
    return NULL;
  
  Menu node = menu->next;

  while (!isNullMenu(node)) {
    if (item_getId(node->item) == id) {
      Item item = new_Item(id, item_getDescription(node->item), item_getPrice(node->item));
      return item;
    }

    node = node->next;
  }

  return NULL;
}

Item menu_getItemByDescription(Menu menu, const char* description) {

  if (isNullMenu(menu))
    return NULL;
  
  Menu node = menu->next;

  while (!isNullMenu(node)) {
    if (strcmp(item_getDescription(node->item), description) == 0) {
      Item item = new_Item(item_getId(node->item), description, item_getPrice(node->item));
      return item;
    }

    node = node->next;
  }

  return NULL;
}

void menu_toPrint(Menu menu) {
  Menu node = menu->next;

  if (isNullMenu(menu) || isNullMenu(node)) {
    printf("[ ]");
    return;
  } 

  while (!isNullMenu(node)) {
    printf("%d - %s - %.2f\n", item_getId(node->item), item_getDescription(node->item), item_getPrice(node->item));
    node = node->next;
  }
}
