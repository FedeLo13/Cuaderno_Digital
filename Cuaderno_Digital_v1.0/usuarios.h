#ifndef _USUARIOS_H_
#define _USUARIOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Id_usuario[50];
    char Nomb_usuario[50];
    char Perfil_usuario[50];
    char Usuario[50];
    char Contrasena[50];
    }Usuario;

Usuario *v_usuarios;

void carga_usuarios();
void lista_usuarios();
void crea_usuarios();
void modifica_usuarios();
void elimina_usuarios();
void vuelca_usuarios(int);

#endif
