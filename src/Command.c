#include "../libs/Command.h"

struct COMMAND {
  Item item;
  struct COMMAND *next;
};

int isNullCommand(Command command) {
  if (command == NULL)
    return 1;
  
  return 0;
}

Command new_Command() {
  Command command = (Command) malloc(sizeof(struct COMMAND));

  if (isNullCommand(command))
    return NULL;

  command->item = NULL;
  command->next = NULL;

  return command;
}

void destruct_Command(Command command) {
  Command node = command->next;

  while (!isNullCommand(node)) {
    Command aux = node->next;
    destruct_Item(node->item);
    free(node);
    node = aux;
  }

  free(command);
}

Command command_add(Command command, Item item) {

  if (isNullCommand(command))
    return command;

  if (isNullItem(item))
    return;
  
  Command node = command->next;

  Command newNode = new_Command();
  newNode->item = item;

  newNode->next = node;
  command->next = newNode;

  return command;
}

void command_remove(Command command, Item item) {
  if (isNullCommand(command) || item == NULL)
    return;
  
  Command prev = NULL;
  Command node = command->next;

  while (!isNullCommand(node) && !item_isEquals(node->item, item)) {
    prev = node;
    node = node->next;
  }

  if (isNullCommand(prev)) {
    command->next = node->next;
  } else {
    prev->next = node->next;
  }

  destruct_Item(node->item);
  free(node);
}

Item command_getItemById(Command command, int id) {

  if (isNullCommand(command))
    return NULL;
  
  Command node = command->next;

  while (!isNullCommand(node)) {
    if (item_getId(node->item) == id) {
      Item item = new_Item(id, item_getDescription(node->item), item_getPrice(node->item));
      return item;
    }

    node = node->next;
  }

  return NULL;
}

Item command_getItemByDescription(Command command, const char* description) {

  if (isNullCommand(command))
    return NULL;
  
  Command node = command->next;

  while (!isNullCommand(node)) {
    if (strcmp(item_getDescription(node->item), description) == 0) {
      Item item = new_Item(item_getId(node->item), description, item_getPrice(node->item));
      return item;
    }

    node = node->next;
  }

  return NULL;
}

void command_toPrint(Command command) {
  Command node = command->next;

  if (isNullCommand(command) || isNullCommand(node)) {
    printf("[ ]");
    return;
  } 

  while (!isNullCommand(node)) {
    printf("%d - %s - %.2f\n", item_getId(node->item), item_getDescription(node->item), item_getPrice(node->item));
    node = node->next;
  }
}
