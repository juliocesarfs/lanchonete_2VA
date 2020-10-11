#include "libs/Menu.h"
#include "libs/Command.h"


int main() {

  Menu menu = new_Menu();
  Item item = new_Item(2, "Macarrao", 10.2);
  menu_add(menu, item);
  
  Item item2 = new_Item(5, "Cebola", 10.2);
  menu_add(menu, item2);

  Item item3 = new_Item(7, "Salada", 11.2);
  menu_add(menu, item3);

  Command command = new_Command();

  command_add(command, menu_getItemByDescription(menu, "Salada"));
  command_add(command, menu_getItemByDescription(menu, "Arroz"));
  command_add(command, menu_getItemByDescription(menu, "Cebola"));



  command_toPrint(command);

  //menu_toPrint(menu);

  return 0;
}