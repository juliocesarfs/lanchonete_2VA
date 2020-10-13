#ifndef CLIENT_H
#define CLIENT_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Command.h"

typedef struct CLIENT *Client;

Client new_Client(Command command, const char* book, float totalPrice);

void destruct_Client(Client client);

Command client_getCommand(Client client);

const char* client_getBook(Client client);

float client_getTotalPrice(Client client);


#endif