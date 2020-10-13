#include "../libs/ListClient.h"

struct LIST_CLIENT {
  Client client;
  struct LIST_CLIENT *next;
};

int isNullListClient(ListClient listClient) {
  if (listClient == NULL)
    return 1;
  
  return 0;
}

ListClient new_ListClient() {
  ListClient listClient = (ListClient) malloc(sizeof(struct LIST_CLIENT));

  if (isNullListClient(listClient))
    return NULL;

  listClient->client = NULL;
  listClient->next = NULL;

  return listClient;
}

void destruct_ListClient(ListClient listClient) {
  ListClient node = listClient->next;

  while (!isNullListClient(node)) {
    ListClient aux = node->next;
    destruct_Client(node->client);
    free(node);
    node = aux;
  }

  free(listClient);
}

ListClient listClient_add(ListClient listClient, Client client) {

  if (isNullListClient(listClient))
    return listClient;
  
  ListClient newNode;
  ListClient aux = listClient;

  newNode = (ListClient) malloc(sizeof(struct LIST_CLIENT));
  newNode->client = client;
  newNode->next = NULL;

  while (aux->next != NULL) {
    aux = aux->next;
  }

  aux->next = newNode;


  return listClient;
}

void listClient_remove(ListClient listClient) {
  if (isNullListClient(listClient))
    return;
  
  ListClient firstElement;
  firstElement = listClient->next;
  
  listClient->next = firstElement->next;
  free(firstElement);
}

Client listClient_getClientById(ListClient listClient, int id) {

  if (isNullListClient(listClient))
    return NULL;
  
  ListClient node = listClient->next;

  while (!isNullListClient(node)) {
    if (client_getId(node->client) == id) {

      Client client = new_Client(client_getName(node->client), client_getId(node->client));
      return client;
    }

    node = node->next;
  }

  return NULL;
}


void listClient_toPrint(ListClient listClient) {
  ListClient node = listClient->next;

  
  while (!isNullListClient(node)) {
    client_toPrint(node->client);
    node = node->next;
  }
}
