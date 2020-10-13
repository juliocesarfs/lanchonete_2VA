// JULIO CESAR AFONSO FERNANDES
// SERÁ NECESSÁRIO O MinGW para executar com o GCC no Windows

// Navegue até a pasta do projeto (JulioCesar_lanchonete)
// No cmd, execute exatamente o seguinte comando:

// gcc -o program main.c src/BookStack.c src/Item.c src/Menu.c src/Command.c src/Client.c src/ListClient.c src/Schedule.c

//Após, digite execute no cmd o comando: program 


#include "libs/Schedule.h"


int main() {
  setlocale(LC_ALL, "Portuguese");

  start();
  stop();
  
  return 0;
}