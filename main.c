#include "libs/Menu.h"
#include "libs/Command.h"
#include "libs/BookStack.h"
#include "libs/Client.h"
#include "libs/ListClient.h"


int main() {

  ListClient listClient = new_ListClient();
  
  Menu menu = new_Menu();
  Item item = new_Item(2, "Hamburger", 10.2);
  menu_add(menu, item);
  Item item2 = new_Item(5, "Pao de queijo", 20);
  menu_add(menu, item2);
  Item item3 = new_Item(7, "Hot-Dog", 5);
  menu_add(menu, item3);

  Client client = new_Client("Julio", 1);
  listClient_add(listClient, client);
  
  Client client2 = new_Client("Rodrigo", 2);
  listClient_add(listClient, client2);


  client_addOrder(client, menu, "Hamburger");
  client_addOrder(client, menu, "Hot-Dog");

  client_addOrder(client2, menu, "Hamburger");


  //printf("%.2f", client_getBook(client));
  //Client clientTest = listClient_getClientById(listClient, 2);

  //printf("%s", client_getName(clientTest));


  listClient_toPrint(listClient);
  listClient_remove(listClient);

  listClient_toPrint(listClient);

  return 0;
}