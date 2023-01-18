#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Declaracion constantes */
#define MAXVOL 20

/* Estructuras definidas */

struct voletos {
    char voletos[MAXVOL][7];
    char premio[MAXVOL][7];
};

/* Declaracion ejecucion programa */

void clear();
int screenMenu();
void optMenu();
void menu();
int preguntaCantVoletos(int);
void genVoletos();


    /* Ejecucion menu */

    void menu() {
        int option = 99;
        do {
            option = screenMenu();
            optMenu(option);
        } while (option != 0);
    }

        /* Parametros pantalla menu */

        int screenMenu () {
            int option = 99;
            clear();
            printf("===============================MENU===============================\n");
            printf("1) Realizar sorteo\n");
            printf("2) Ordenar numeros premiados\n");
            printf("3) Listar numeros premiados ordenados por numero\n");
            printf("4) Listar numeros premiados ordenados por premio\n");
            printf("5) Consulta lenta (sequencial) numero\n");
            printf("6) COnsulta rapida (dicotomica) numero\n");
            printf("0) Salir\n");
            printf("Introduce la opcion a selecionar: ");
            scanf("%i", &option);
            return option;
        }

        /* Opciones menu */

        void optMenu(int opt) {
            struct voletos voletos;
            switch (opt) {
            case 1:
                    genVoletos(voletos);
                break;
            
            default:
                    printf("Opcion no selecionada");
                break;
            }
        }
    
    /* Generar voletos */

    void genVoletos() {
        int i = 0, j = 0;
        int cantidad_voletos = 0;
        char voletos[20][7];
        char voleto[7];
        cantidad_voletos = preguntaCantVoletos(cantidad_voletos);
        // printf("cantidad: %i", cantidad_voletos);
        // getch();
        do {
            do
            {
                voleto[j] = rand() % cantidad_voletos + 1;
            } while (j < 7);
            for (int k = 0; k < 7; k++) {
                if (strcmp(voletos[k], voleto) != 0) {
                    strcpy(voletos[i], voleto);
                }
            }
            i++;
        } while (i < cantidad_voletos);        
    }

        /* Cantidad voletos a generar */

        int preguntaCantVoletos(int cant) {
            printf("Introduce la cantidad de voletos: ");
            scanf("%i", &cant);
            return cant;
        }

/* MAIN */

int main(int argc, char const *argv[]) {
    menu();
}

/* Funciones y acciones auxiliares */

void clear () {
    system("cls");
}