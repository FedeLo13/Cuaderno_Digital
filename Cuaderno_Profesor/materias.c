#include "materias.h"
n
void materias()
{



int n;

    do{

        system("cls");
		printf("______________________________________________________________\n");
        printf("\tAsignaturas\n");
        printf("______________________________________________________________\n");
        printf("\tSeleccione una opcion:\n");
        printf("\t\t1.Matematicas Discretas\n ");
        printf("\t\t2.Sistemas Digitales \n");
        printf("\t\t3.Informatica General\n ");
        printf("\t\t4.Introduccion a la Programacion\n ");
        printf("\t\t5.Calculo \n");
        printf("\t\t6.Salir del programa\n");

        printf("\t");
		scanf("%i",&n);
		}while (n>6 || n<1);

        switch(n){

            case 1:
            	printf("______________________________________________________________\n");
                printf("\tAlumnos MD\n");
                printf("______________________________________________________________\n");

			    printf(" \n");
                system("PAUSE");
                break;

            case 2:
            	puts("______________________________________________________________\n");
                puts("\tAlumnos S.Dig\n");
                puts("______________________________________________________________\n");

			    printf(" \n");
               	system("PAUSE");
                break;

            case 3:
            	printf("______________________________________________________________\n");
                printf("\tAlumnos IG\n");
                printf("______________________________________________________________\n");

				printf(" \n");
                system("PAUSE");
                break;

            case 4:
            	printf("______________________________________________________________\n");
                printf("\tAlumnos IP\n");
                printf("______________________________________________________________\n");

				printf(" \n");
              	system("PAUSE");
                break;

            case 5:
            	printf("______________________________________________________________\n");
                printf("\tAlumnos Cal\n");
                printf("______________________________________________________________\n");

                system("PAUSE");
                break;

            case 6:
                break;
        }

    }

    guardar();
