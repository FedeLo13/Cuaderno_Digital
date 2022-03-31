#include "Alumnos.h"
#include "Funciones_clave.h"
#define l 0
caca
void carga_alumnos(){

char aux, p[100];
int cont;
FILE *f;

f = fopen("Alumnos.txt", "r");

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
caca
vaciar(p, 100);

for(int i = 0; i < l; i++){
    for(int j = 0; j < 6; j++){
        for(int k = 0; aux != '-'; k++){
            aux = fgetc(f);
            if(aux != '-'){
                p[k] = aux;
            }
        }
        switch(j){
            case 0: p[k] = alun[i].id_alum;
            break;
            case 1: p[k] = alun[i].nombre_alum;
            break;
            case 2: p[k] = alun[i].direc_alum;
            break;
            case 3: p[k] = alun[i].local_alum;
            break;
            case 4: p[k] = alun[i].curso;
            break;
            case 5: p[k] = alun[i].grupo;
            break;
            default: printf("Error");
            break;
        }
        vaciar(p[k], 100);
    }
}
fclose(f);
}













































































































