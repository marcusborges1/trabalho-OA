#include <stdio.h>
#include <stdlib.h>

#include "hard_drive.h"
#include "logic_drive.h"

/*Inicia disco rigido*/
track_array c[TRILHA_SUPERFICIE];
track_array *cylinder = c;

fatent blocks[SETOR_TRILHA];
fatlist archives[100];

void show_menu(void);

char get_menu_option(void);

int main(void) {
  char option = 0;

  archives[0].file_name[0] = 'D';
  archives[0].first_sector = 0;

  do{
    option = get_menu_option();
    switch( option ){
      case '1':
        system("clear");
        write_file();
        break;
      case '2':
        system("clear");
        read_file();
        break;
      case '3':
        system("clear");
        erase_file();
        break;
      case '4':
        system("clear");
        show_fat_table();
        break;
      case '5':
        //Leave program
        break;
    }
  }while( option != '5' );

  system("clear");
  printf("Hard Disk had turned off...\n");

  return 0;
}

void show_menu(void){
  printf("***********************\n");
  printf("*      HARD DISK     *\n");
  printf("***********************\n");

  printf("1 - Escrever Arquivo\n");
  printf("2 - Ler Arquivo\n");
  printf("3 - Apagar Arquivo\n");
  printf("4 - Mostrar tabela FAT\n");
  printf("5 - Sair\n");
}

char get_menu_option(void){
  char option = '0';
  do{
    system("clear");
    show_menu();
    scanf("%c", &option);
  }while( option < '1' || option > '5' );
  return option;
}
