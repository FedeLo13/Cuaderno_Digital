#ifndef _USUARIOS_H_
#define _USUARIOS_H_

#include <stdio.h>
#include <string.h>
typedef struct{
    int Id_usuario;
    char [20] Nomb_usuario;
    char [13] Perfil_usuario;
    char [6] Usuario;
    char [9] Contraseña;
}
Usuario;

Usuario *v_usuarios;

void carga_usuarios(Usuario *v_usuarios);

#endif
