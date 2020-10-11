#include "libs/Menu.h"

int main() {

  Menu menu = new_Menu();
  Item item = new_Item(2, "Macarrao", 10.2);
  menu_add(menu, item);
  
  Item item2 = new_Item(5, "Cebola", 10.2);
  menu_add(menu, item2);

  Item item3 = new_Item(7, "Salada", 11.2);
  menu_add(menu, item3);

  menu_toPrint(menu);

  menu_remove(menu, item3);

  menu_toPrint(menu);

  return 0;
}