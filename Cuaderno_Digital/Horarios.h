#ifndef _HORARIOS_H_
#define _HORARIOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
    char id_profesor[4];
    char dia_clase[6];
    char hora_clase[7];
    char id_materia[5];
    char grupo[11];
}Horarios;

Horarios *horar;

void listhorar();
void carga_horarios();
void modhorar();
void addhorar();
void delhorar();
void endhorar();

#endif
