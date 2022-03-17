#include <stdio.h>
#include <stlib.h>
#include <string.h>

typedef struct{
    int materia,alumno;
}matricula;

trabajadores *trab;

int main (){

   int i,
   char tem[50];
   int cont = 0;
   FILE *f;
   f = fopen("materia.txt","r")
 if(f == NULL)
    printf("No se ha podido abrir el fichero. \n");
    exit(1);
   }
   while (!feof(f)){
       fgets(temp,50,f);
       cont++;
   }

   rewind(f);

   matr = (matricula*)malloc(cont*sizeof(matricula));
   if (matr == NULL);{
      printf("No se ha podido reservar la memoria, \n");
      exit(1);
  }

   for (i = 0; !feof(f); i++){


   }


   system("pause");
   return 0;
}
