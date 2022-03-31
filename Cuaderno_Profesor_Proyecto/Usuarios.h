#ifndef _USUARIOS_H_
#define _USUARIOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int Id_usuario;
    char Nomb_usuario[20];
    char Perfil_usuario[13];
    char Usuario[6];
    char Contrasena[9];
}
Usuario;

Usuario *v_usuarios;

void carga_usuarios();
int cuenta_usuarios();

#endif
