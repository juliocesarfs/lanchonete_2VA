#include "../libs/Client.h"

struct CLIENT {
  Command command;
  char book[40];
  float totalPrice;
};

int isNullClient(Client client) {
  if (client == NULL) 
    return 1;
  
  return 0;
}

Client new_Client() {
  Client client = (Client) malloc(sizeof(struct CLIENT));

  if (isNullClient(client))
    return NULL;
  
  client->command = new_Command();
  strcpy(client->book, "null");
  client->totalPrice = 0;


  return client;
}

void destruct_Client(Client client) {
  if (isNullClient(client))
    return;
  
  destruct_Command(client->command);

  free(client);
}

Command client_getCommand(Client client) {
  if (isNullClient(client))
    return NULL;
  
  return client->command;
}

const char* client_getBook(Client client) {
  if (isNullClient(client))
    return NULL;
  
  return client->book;
}

float client_getTotalPrice(Client client) {
  if (isNullClient(client))
    return 0;
  
  return client->totalPrice;
}


void client_addOrder(Client client, Menu menu, const char* orderName) {
  command_add(client->command, menu_getItemByDescription(menu, orderName));

  client->totalPrice = command_getTotalPrice(client->command);
}


void client_toPrint(Client client) {

  printf("%s - R$ %.2f\n", client->book, client_getTotalPrice(client));
  command_toPrint(client->command);
}
