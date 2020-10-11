#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>

#include "Item.h"

typedef struct MENU *Menu;

Menu new_Menu();

void destruct_Menu(Menu menu);

Menu menu_add(Menu menu, Item item);

void menu_remove(Menu menu, Item item);

Menu menu_getItemById(Menu menu, int id);

Menu menu_getItemByDescription(Menu menu, const char* description);

void menu_toPrint(Menu menu);

#endif