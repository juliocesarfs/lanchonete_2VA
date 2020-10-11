#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <stdlib.h>

#include "Item.h"

typedef struct COMMAND *Command;

int isNullCommand(Command command);

Command new_Command();

void destruct_Command(Command command);

Command command_add(Command command, Item item);

void command_remove(Command command, Item item);

Item command_getItemById(Command command, int id);

Item command_getItemByDescription(Command command, const char* description);

void command_toPrint(Command command);

#endif