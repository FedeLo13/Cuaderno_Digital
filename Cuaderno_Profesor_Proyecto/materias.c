#include "materias.h"
#include <string.h>
#include <stdlib.h>

typedef struct{

    int id_materia;
    char nombre_materia;
    char abrev_materia;
}   materias;

materias *mat;

int main ()
{
    int id=4;
    char mat [50];

    f=fopen ("materias.txt","r");
    if (f==NULL)
    {
        printf ("Error\n");
        exit (1);
    }

    while (!feof(f))
    {
        fgets(temps,50,f);
        id++;
    }

    rewind (f);
    mat = (materias*)malloc(id*sizeof(materias));

      if (mat==NULL)
    {
        printf ("Error\n");
        exit (1);
    }
    for (i = 0; !feof(f);i++)
    {
        vaciar(mat);
        aux = '0';
        for(j = 0; aux!= '-'; j++)
        {
            aux = fgetc (f)
            if (aux != '-')
            {
                mat[j] = aux;
            }
        }
        copiar (mat,i);
    }

    system ("pause")
}
void vaciar (char mat[])
{
    int i;
    for (i = 0; i<50; i++)
    {
        mat[i ='\0'];
    }
}
void copiar(char mat[], int i){
    int N = strlen(mat) + 1;
    mat(i) .nombre = char*)malloc(N*sizeof(char));

    if (trab(i).nombre == NULL){

       printf("No se ha podido reservar memoria. \n");
       exit(1);

    }
    for (i = 0; !feof(f); i++){
        vaciar(temp);
        aux = '0';
        for (j=0; aux!='-';j++){
        aux = fgetc (f);
        if (aux!= '-'){
            mat[j] = aux;

        }
        }
        copiar (mat,i)
        fgets(mat,50,f);
        mat[i].nombre=atoi(mat0);
    }
}
