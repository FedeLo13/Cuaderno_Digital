#ifndef _MATRICULA_H_
#define _MATRICULA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
    char id_materia[5];
    char id_alum[7];
}matricula;

matricula *v_matricula;

void lista_matricula();
void carga_matricula();
void modifuca_matricula();
void crea_matricula();
void elimina_matricula();
void endmatr();

#endif
