#include "libs/Menu.h"
#include "libs/Command.h"
#include "libs/BookStack.h"
#include "libs/Client.h"


int main() {

  
  Menu menu = new_Menu();
  Item item = new_Item(2, "Hamburger", 10.2);
  menu_add(menu, item);
  Item item2 = new_Item(5, "Pao de queijo", 20);
  menu_add(menu, item2);
  Item item3 = new_Item(7, "Hot-Dog", 5);
  menu_add(menu, item3);

  Client client = new_Client();
  Client client2 = new_Client();

  client_addOrder(client, menu, "Hamburger");
  client_addOrder(client, menu, "Hot-Dog");

  client_addOrder(client2, menu, "Hamburger");


  //printf("%.2f", client_getBook(client));
  client_toPrint(client2);

  return 0;
}