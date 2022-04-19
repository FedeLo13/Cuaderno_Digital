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
}horarios;

horarios *v_horarios;

void lista_horararios();
void carga_horarios();
void modificar_horararios();
void crea_horarios();
void borrar_horararios();
void endhorar();

#endif
