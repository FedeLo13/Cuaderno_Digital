#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int materia,alumno;
}matricula;

matricula *v_matriculas;

void carga_matriculas(){

   int i,j;
   char aux;
   char temp[50];
   int cont = 0;
   FILE *f;
   f = fopen("materia.txt","r");
 if(f == NULL){
    printf("No se ha podido abrir el fichero. \n");
    exit(1);
   }
   while (!feof(f)){
       fgets(temp,50,f);
       cont++;
   }

   rewind(f);

   v_matriculas = (matricula*)malloc(cont*sizeof(matricula));
   if (v_matriculas == NULL){
      printf("No se ha podido reservar la memoria, \n");
      exit(1);
  }

   for (i = 0; !feof(f); i++){
      vaciar(temp);
      aux = 'o';
    for (j = 0; aux != '-'; i++);
        aux = fgetc(f);
   }
}

void vaciar(char temp[]){
   int i;


    for(i = 0; i<50; i++)
        temp[i] = '\0';
}
