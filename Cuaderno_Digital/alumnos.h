#ifndef _ALUMNOS_H_
#define _ALUMNOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
    char id_alum[7];
    char nombre_alum[21];
    char direc_alum[31];
    char local_alum[31];
    char curso[31];
    char grupo[11];
}Alumnos;

Alumnos *alun;

void carga_alumnos();
#endif
