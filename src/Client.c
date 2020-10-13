#include "../libs/Client.h"

struct CLIENT {
  int id;
  char name[40];
  Command command;
  char book[40];
  float totalPrice;
};

int isNullClient(Client client) {
  if (client == NULL) 
    return 1;
  
  return 0;
}

Client new_Client(const char* name, int id) {
  Client client = (Client) malloc(sizeof(struct CLIENT));

  if (isNullClient(client))
    return NULL;
  

  strcpy(client->name, name);
  client->id = id;
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

char* client_getName(Client client) {
  if (isNullClient(client))
    return 0;
  
  return client->name;
}

int client_getId(Client client) {
  if (isNullClient(client))
    return 0;
  
  return client->id;
}


void client_addOrder(Client client, Menu menu, const char* orderName) {

  command_add(client->command, menu_getItemByDescription(menu, orderName));

  client->totalPrice = command_getTotalPrice(client->command);
}


void client_toPrint(Client client) {

  printf("%d - %s\n", client_getId(client), client_getName(client));
}
