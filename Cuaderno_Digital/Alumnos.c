#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//void vaciar();
void carga_alumnos();

typedef struct{
    int id_alum;
    char nombre_alum[20];
    char direc_alum[30];
    char local_alum[30];
    char curso[30];
    char grupo[10];
}Alumnos;

Alumnos *alun;

int main(){
	setlocale(LC_CTYPE, "Spanish");
    carga_alumnos();
    printf("%s", alun[0].nombre_alum);
    return 0;
}

void carga_alumnos(){

char p[100];
char *token;
int i, j, cont;
FILE *f;

f = fopen("alumnos.txt", "r");

if(f == NULL){
    printf("No se ha podido abrir el fichero.");
}

i = 0;

while(!feof(f)){
    fgets(p, 100, f);
    printf("%s", p);
    do{
    	j = 0;
    	token = strtok(p, "-");
    	printf("%s\n", token);
    	if(token == NULL){
    		printf("Error");
		}
    	switch(j){
        	case 0: alun[i].id_alum = strtol(token, NULL, 7);
        	break;
            case 1: strcpy(alun[i].nombre_alum, token);
            break;
            case 2: strcpy(alun[i].direc_alum, token);
            break;
            case 3: strcpy(alun[i].local_alum, token);
            break;
            case 4: strcpy(alun[i].curso, token);
            break;
            case 5: strcpy(alun[i].grupo, token);
            break;
            default: printf("Error");
            break;
        	}
        	j++;
        	token = strtok(NULL, "-");
	}while(j < 5);
	i++;
}
alun = (Alumnos*)malloc(cont*sizeof(Alumnos));

if(alun == NULL){
    printf("Error al reservar memoria.");
}
fclose(f);
}

//void list(){
//    for(int i = 0; i < l; i++){
        //printf("Id: %c", alun[i].id_alum);
//         printf("%c-", alun[i].nombre_alum);
  //        printf("%c-", alun[i].direc_alum);
    //       printf("%c-", alun[i].local_alum);
      //      printf("%c-", alun[i].curso);
        //     printf("%c-", alun[i].grupos);

   // }
//}

//void vaciar(char p[]){
  //  for(int i = 0; i < 100; i++){
    //    p[i] = '\0';
    //}
//}
