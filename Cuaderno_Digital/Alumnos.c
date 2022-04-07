#include"alumnos.h"
#include"funciones_clave.h"

int l = 0;

void carga_alumnos();

int main(){
    carga_alumnos();
}

void carga_alumnos(){

char aux, p[100];
int cont;
FILE *f;
int k;

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

alun = (Alumnos*)malloc(cont*sizeof(Alumnos));

if(alun == NULL){
    printf("Error al reservar memoria.");
}
vaciar(p, 100);

for(int i = 0; i < l; i++){
    for(int j = 0; j < 6; j++){
        for(k = 0; aux != '-'; k++){
            aux = fgetc(f);
            if(aux != '-'){
                p[k] = aux;
            }
        }
        switch(j){
            case 0: strcpy(alun[i].id_alum, p);
            break;
            case 1: strcpy(alun[i].nombre_alum, p);
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
        vaciar(p[k], 100);
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
