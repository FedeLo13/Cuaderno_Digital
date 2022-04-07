#include"alumnos.h"

//void vaciar();
void carga_alumnos();

typedef struct{
    char id_alum[7];
    char nombre_alum[20];
    char direc_alum[30];
    char local_alum[30];
    char curso[30];
    char grupo[10];
}Alumnos;

Alumnos *alun;

int main(){
    carga_alumnos();
    printf("%s", alun[0].nombre_alum);
    return 0;
}

void carga_alumnos(){

char aux, p[100];
int cont, k, i, j;
FILE *f;

aux = '\0';

f = fopen("alumnos.txt", "r");

if(f == NULL){
    printf("No se ha podido abrir el fichero.");
}

cont = 0;

while(!feof(f)){
    fgets(p, 100, f);
    printf("%s", p);
    cont++;
}
alun = (Alumnos*)malloc(cont*sizeof(Alumnos));

if(alun == NULL){
    printf("Error al reservar memoria.");
}

for(i = 0; i < cont-1; i++){

    for(j = 0; j < 6; j++){

        for(k = 0; aux != '-'; k++){
			aux = fgetc(f);
			p[k] = aux;
			printf("%c", p[k]);
            } //strtok
        switch(j){
        	case 0: 
        	break;
            case 1: printf("%s", p); strcpy(alun[i].nombre_alum, p);
            break;
            case 2: strcpy(alun[i].direc_alum, p);
            break;
            case 3: strcpy(alun[i].local_alum, p);
            break;
            case 4: strcpy(alun[i].curso, p);
            break;
            case 5: strcpy(alun[i].grupo, p);
            break;
            default: printf("Error");
            break;
        	}	
    	}
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
