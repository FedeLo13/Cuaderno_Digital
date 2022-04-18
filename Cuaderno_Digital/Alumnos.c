#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "alumnos.h"
#include "funciones_clave.c"

void list();
void carga_alumnos();
void modalum();
void addalum();
void delalum();

int l;

int main(){
	setlocale(LC_CTYPE, "Spanish");
    carga_alumnos();
    addalum();
    printf("%s\n", alun[l].id_alum);
	printf("%s\n", alun[l].nombre_alum);
	printf("%s\n", alun[l].direc_alum);
	printf("%s\n", alun[l].local_alum);
	printf("%s\n", alun[l].curso);
	printf("%s\n", alun[l].grupo);
    return 0;
}

void carga_alumnos(){

char p[100], *token;
const char s[2] = "-";
int i, j, cont, semaforo;
FILE *f;

f = fopen("alumnos.txt", "r");

if(f == NULL){
    printf("No se ha podido abrir el fichero.");
}

cont = 0;

while(!feof(f)){
    fgets(p, 100, f);
    cont++;
}

l = cont;

alun = (Alumnos*)malloc(l*sizeof(Alumnos));

if(alun == NULL){
    printf("Error al reservar memoria.");
}

rewind(f);

for(i = 0; i < l; i++){
	vaciar(p, 100);
	fgets(p, 100, f);
	token = strtok(p, s);
	j = 1;
	while(token != NULL){
		switch(j){
        	case 1: strcpy(alun[i].id_alum, token);
        	break;
            case 2: strcpy(alun[i].nombre_alum, token);
            break;
            case 3: strcpy(alun[i].direc_alum, token);
            break;
            case 4: strcpy(alun[i].local_alum, token);
            break;
            case 5: strcpy(alun[i].curso, token);
            break;
            case 6: strcpy(alun[i].grupo, token);
            break;
        }
		token = strtok(NULL, s);
		j++;
	}
}
fclose(f);
}

void addalum(){
	char c;
	do{
    l++;
	alun = (Alumnos*)realloc(alun, l);
	if(alun == NULL){
		printf("ERROR");
	}
	do{
		printf("Introduce el id del nuevo alumno.\n");
		gets(alun[l].id_alum);
		fflush(stdin);
	}while(strlen(alun[l].id_alum) > 7);
	do{
		printf("Introduce el nombre del nuevo alumno.\n");
		gets(alun[l].nombre_alum);
		fflush(stdin);
	}while(strlen(alun[l].nombre_alum) > 21);
	do{
		printf("Introduce la direccion del nuevo alumno.\n");
		gets(alun[l].direc_alum);
		fflush(stdin);
	}while(strlen(alun[l].direc_alum) > 31);
	do{
		printf("Introduce la localidad del nuevo alumno.\n");
		gets(alun[l].local_alum);
		fflush(stdin);
	}while(strlen(alun[l].local_alum) > 31);
	do{
		printf("Introduce el curso del nuevo alumno.\n");
		gets(alun[l].curso);
		fflush(stdin);
	}while(strlen(alun[l].curso) > 31);
	do{
		printf("Introduce el grupo del nuevo alumno.\n");
		gets(alun[l].grupo);
		fflush(stdin);
	}while(strlen(alun[l].grupo) > 11);
	printf("¿Quieres introducir otro alumno? s/n \n");
	scanf("%c", c);
	}while(c == 's');
}

void list(){
	int i;
	char id[6];

	for(i = 0; i < l; i++){
        printf("%s - ", alun[i].id_alum);
        printf("%s\n", alun[i].nombre_alum);
	}

	printf("Selecciona un id: \n");
	fgets(id, 6, stdin);

	for(i = 0; i <= l; i++){
		if(strcoll(id, alun[i].id_alum) == 0){
			printf("%s\n", alun[i].id_alum);
			printf("%s\n", alun[i].nombre_alum);
			printf("%s\n", alun[i].direc_alum);
			printf("%s\n", alun[i].local_alum);
			printf("%s\n", alun[i].curso);
			printf("%s\n", alun[i].grupo);
			i = l+1;
		}
	}
}

void delalum(){
	int i, j;
	char nom[20];
	printf("¿Que alumno desea eliminar?\n");
	fgets(nom, 20, stdin);
	for(i = 0; i < l; i++){
		if(strcmp(nom, alun[i].nombre_alum)){
			j = i;
			i = l+1;
		}
	}
	for(j; j < l; j++){
	strcpy(alun[j].id_alum, alun[j+1].id_alum);
	strcpy(alun[j].nombre_alum, alun[j+1].nombre_alum);
	strcpy(alun[j].direc_alum, alun[j+1].direc_alum);
	strcpy(alun[j].local_alum, alun[j+1].local_alum);
	strcpy(alun[j].curso, alun[j+1].curso);
	strcpy(alun[j].grupo, alun[j+1].grupo);
	}
	l = l-1;
	alun = (Alumnos*)realloc(alun, l);
}

void modalum(){
	int i, j;
	char c, nom[20], dat[30];
	printf("¿Que alumno desea modificar?\n");
	fgets(nom, 20, stdin);
	for(i = 0; i < l; i++){
		if(strcmp(nom, alun[i].nombre_alum)){
			do{
				printf("¿Que dato desea modificar?\n");
				printf("(1)Nombre\n");
				printf("(2)Direccion\n");
				printf("(3)Localidad\n");
				printf("(4)Curso\n");
				printf("(5)Grupo\n");
				scanf("%i", j);
				switch(j){
					case 1: printf("Introduce el nuevo dato: \n");
						fgets(dat, 20, stdin);
						strcpy(alun[i].nombre_alum, dat);
					break;
					case 2: printf("Introduce el nuevo dato: \n");
						fgets(dat, 30, stdin);
						strcpy(alun[i].direc_alum, dat);
					break;
					case 3: printf("Introduce el nuevo dato: \n");
						fgets(dat, 30, stdin);
						strcpy(alun[i].local_alum, dat);
					break;
					case 4: printf("Introduce el nuevo dato: \n");
						fgets(dat, 30, stdin);
						strcpy(alun[i].curso, dat);
					break;
					case 5: printf("Introduce el nuevo dato: \n");
						fgets(dat, 10, stdin);
						strcpy(alun[i].grupo, dat);
					break;
					default: printf("Numero incorrecto.\n");
					break;
				}
				printf("¿Desea hacer otra modificacion? y/n\n");
				scanf("%c", c);
			}while(c != 'n');
			i = l+1;
		}
	}

}

void end(){
	FILE *f;
	int i;
	f = fopen("alumnos.txt", "w");
	if(f == NULL){
		printf("ERROR\n");
	}

	for(i = 0; i<l; i++){
		fprintf(f, "$s-", alun[i].id_alum);
		fprintf(f, "$s-", alun[i].nombre_alum);
		fprintf(f, "$s-", alun[i].direc_alum);
		fprintf(f, "$s-", alun[i].local_alum);
		fprintf(f, "$s-", alun[i].curso);
		fprintf(f, "$s", alun[i].grupo);
		fprintf(f, "\n");
	}
	fclose(f);
}


