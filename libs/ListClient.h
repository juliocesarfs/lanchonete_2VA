#ifndef LIST_CLIENT_H
#define LIST_CLIENT_H

#include <stdio.h>
#include <stdlib.h>

#include "Client.h"

typedef struct LIST_CLIENT *ListClient;

int isNullListClient(ListClient listClient);

ListClient new_ListClient();

void destruct_ListClient(ListClient listClient);

ListClient listClient_add(ListClient listClient, Client client);

void listClient_remove(ListClient listClient);

Client listClient_getClientById(ListClient listClient, int id);

void listClient_toPrint(ListClient listClient);

#endif