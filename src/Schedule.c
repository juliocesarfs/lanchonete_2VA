#include "../libs/Schedule.h"

typedef struct CLIENT_SERVED {
  int id;
  char name[40];
  char book[40];
  float totalPrice;
} ClientServed;

ClientServed clientsServed[50];

static ListClient listClient;
static BookStack bookStack;
static Menu menu;

#define SIZE_NAME 40
#define SIZE_BOOK 40
#define SIZE_DESCRIPTION 40


int flag = 1;
int indexClientsServed = 0;

static int OPTIONS() {
  int option;

  do {

    system("clear");
    system("cls");

    printf("1. Inserir Item no cardápio\n"); //DONE
    printf("2. Inserir Cliente na fila\n"); //DONE
    printf("3. Inserir Livro na pilha\n"); //DONE
    printf("4. Inserir pedido na comanda do cliente\n"); //DONE
    printf("5. Listar cardápio\n"); //DONE
    printf("6. Listar fila de clientes\n"); //DONE
    printf("7. Listar pilha de livros\n"); //DONE
    printf("8. Listar comanda do primeiro da fila\n"); //DONE
    printf("9. Fechar conta do cliente\n");  //DONE
    printf("10. RELATÓRIO CLIENTES ATENDIDOS\n"); //DONE
    printf("11. Sair\n");
    scanf("%d", &option);

    system("clear");
    system("cls");

    if(option < 1 || option > 11) //VALIDAÇÃO DA OPTION
      printf("Opção inválida! (Digite as opções disponiveis no menu)\n");
    else
      break;

  } while (flag);

  return option;
}

static void insertItemMenu(Menu menu) {
  int id;
  char description[SIZE_DESCRIPTION];
  float price;
  int iteration = 1;

  printf("\n==========Inserção no cardápio==========\n");
  while (1) {
    setbuf(stdin, NULL);

    printf("%dº - Item\n", iteration++);
    printf("Código: ");
    scanf("%d", &id);

    setbuf(stdin, NULL);

    printf("Descrição: ");
    fgets(description, SIZE_DESCRIPTION, stdin);
    description[strlen(description) - 1] = '\0';

    setbuf(stdin, NULL);

    printf("Preço: ");
    scanf("%f", &price);

    setbuf(stdin, NULL);

    Item item = new_Item(id, description, price);
    menu_add(menu, item);

    printf("Deseja continuar inserindo? [s/n]");
    fgets(description, SIZE_DESCRIPTION, stdin);
    description[strlen(description) - 1] = '\0';

    setbuf(stdin, NULL);

    if(strcmp(description, "n") == 0 || strcmp(description, "N") == 0)
      break;

    setbuf(stdin, NULL);


    printf("\n");
  }
}

static void insertClientQueue(ListClient listClient) {
  Client client = NULL;

  int id;
  char name[40];
  Command command = new_Command();
  float totalPrice;

  system("clear");
  system("cls");

  setbuf(stdin, NULL);

  do {

    system("cls");
    system("clear");

    printf("==== Inserção de clientes ====\n");


    printf("Código: ");
    scanf("%d", &id);

    setbuf(stdin, NULL);

    printf("Nome: ");
    fgets(name, SIZE_NAME, stdin);
    name[strlen(name) - 1] = '\0';

    setbuf(stdin, NULL);

    client = new_Client(name, id);
    listClient_add(listClient, client);

    printf("Deseja continuar inserindo? [s/n]");
    fgets(name, SIZE_DESCRIPTION, stdin);
    name[strlen(name) - 1] = '\0';

    setbuf(stdin, NULL);

    if(strcmp(name, "n") == 0 || strcmp(name, "N") == 0)
      break;

    
    system("clear");
    system("cls");

    printf("\n");

  } while(flag);

}

static void insertBookStack(BookStack bookStack) {
  char name[SIZE_BOOK];

  system("clear");
  system("cls");

  setbuf(stdin, NULL);

  do {

    system("cls");
    system("clear");

    printf("==== Inserção de Livros ====\n");
    printf("Nome: ");
    fgets(name, SIZE_NAME, stdin);
    name[strlen(name) - 1] = '\0';

    setbuf(stdin, NULL);

    bookStack = bookStack_add(bookStack, name);

    printf("Deseja continuar inserindo? [s/n]");
    fgets(name, SIZE_DESCRIPTION, stdin);
    name[strlen(name) - 1] = '\0';

    setbuf(stdin, NULL);

    if(strcmp(name, "n") == 0 || strcmp(name, "N") == 0)
      break;

    
    system("clear");
    system("cls");

    printf("\n");

  } while(flag);  
}

static void insertItemCommand(Client client) {
  char description[SIZE_DESCRIPTION];
  int iteration = 1;

  if (isNullListClient(listClient)) {
    printf("Nenhum cliente está na fila!");

    return;
  }

  printf("\n==========Inserção na comanda do Primeiro da fila==========\n");
  while (1) {
    setbuf(stdin, NULL);

    printf("%dº - Item\n", iteration++);
    printf("Descrição: ");
    fgets(description, SIZE_DESCRIPTION, stdin);
    description[strlen(description) - 1] = '\0';

     setbuf(stdin, NULL);

    Item item = menu_getItemByDescription(menu, description);

    if(item == NULL) {
      printf("Esse item não está disponivel no cardápio!");
      
    } else {
      client_addOrder(client, menu, description);
    }
    
    

  
    printf("Deseja inserir mais algum pedido? [s/n]");
    fgets(description, SIZE_DESCRIPTION, stdin);
    description[strlen(description) - 1] = '\0';

    setbuf(stdin, NULL);

    if(strcmp(description, "n") == 0 || strcmp(description, "N") == 0)
      break;

    setbuf(stdin, NULL);

    printf("\n");
  }
}

static void closeClientServed(Client client) {

  char book[40];
  setbuf(stdin, NULL);

  clientsServed[indexClientsServed].id = client_getId(client);
  strcpy(clientsServed[indexClientsServed].name, client_getName(client));
  clientsServed[indexClientsServed].totalPrice = client_getTotalPrice(client);

  strcpy(book, bookStack_getBook(bookStack));
  strcpy(clientsServed[indexClientsServed].book, book);
  
  printf("Conta do %s fechada com sucesso!\n", clientsServed[indexClientsServed].name);
  printf("\nPressione ENTER para continuar...\n");
  getchar();

  indexClientsServed++;
  listClient_remove(listClient);
}

static void showClientQueue() {

  setbuf(stdin, NULL);

  printf("==== FILA DE CLIENTES ===\n");
  listClient_toPrint(listClient);

  printf("\nPressione ENTER para continuar...\n");
  getchar();
}

static void showMenu() {

  setbuf(stdin, NULL);

  printf("==== CARDÁPIO ===\n");
  menu_toPrint(menu);

  printf("\nPressione ENTER para continuar...\n");
  getchar();
}

static void showBookStack() {

  setbuf(stdin, NULL);

  printf("==== PILHA DE LIVROS ===\n");
  bookStack_toPrint(bookStack);

  printf("\nPressione ENTER para continuar...\n");
  getchar();
}

static void showCommandFirstClient(Client client) {
  
  setbuf(stdin, NULL);
  
  printf("=== COMANDA PRIMEIRO DA FILA ===\n");
  printf("Nome: %s\n", client_getName(client));
  command_toPrint(client_getCommand(client));

  printf("\nPressione ENTER para continuar...\n");
  getchar();
}

static void showAllClientsServed() {

  setbuf(stdin, NULL);

  float TOTAL = 0;
  printf("=== RELATÓRIO CLIENTES ATENDIDOS ===\n");
  for (int i = 0; i < indexClientsServed; i++) {
    printf("%d - %s - Livro: %s - R$ %.2f\n", clientsServed[i].id, clientsServed[i].name, clientsServed[i].book, clientsServed[i].totalPrice);
    TOTAL += clientsServed[i].totalPrice;
  }

  printf("\nTOTAL: %.2f", TOTAL);

  printf("\nPressione ENTER para continuar...\n");
  getchar();
}

void start() {

  listClient = new_ListClient();
  menu = new_Menu();
  bookStack = new_BookStack();

  int keep = 1;

  do {

    int option =  OPTIONS();

    switch (option) {

      case 11:
        keep = 0;
        break;
      
      case 10:
        showAllClientsServed();
        break;
      
      case 9:
        closeClientServed(listClient_getFirstClient(listClient));
        break;

      case 8:
        showCommandFirstClient(listClient_getFirstClient(listClient));
        break;
      
      case 7:
        showBookStack(bookStack);
        break;

      case 6:
        showClientQueue(listClient);
        break;

      case 5:
        showMenu(menu);
        break;
      
      case 4:
        insertItemCommand(listClient_getFirstClient(listClient));
        break;

      case 3:
        insertBookStack(bookStack);
        break;

      case 2:
        insertClientQueue(listClient);
        break;

      case 1:
        insertItemMenu(menu);
        break;
    }

  } while (keep);
}

void stop() {
  destruct_BookStack(bookStack);
  destruct_ListClient(listClient);
}

