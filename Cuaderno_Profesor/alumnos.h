#ifndef _ALUMNOS_H_
#define _ALUMNOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id_alum;
    char nombre_alum[20];
    char direc_alum[30];
    char local_alum[30];
    char curso[30];
    char grupo[10];
}Alumnos;

Alumnos *alun;

void carga_alumnos();
#endif
