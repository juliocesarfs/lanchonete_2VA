#ifndef CLIENT_H
#define CLIENT_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Command.h"
#include "Menu.h"
#include "BookStack.h"

typedef struct CLIENT *Client;

Client new_Client();

void destruct_Client(Client client);

Command client_getCommand(Client client);

const char* client_getBook(Client client);

float client_getTotalPrice(Client client);

void client_toString(Client client);

void client_addOrder(Client client, Menu menu, const char* orderName);

void client_toPrint(Client client);




#endif