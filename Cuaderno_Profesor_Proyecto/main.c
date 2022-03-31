#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"
#define N 6
#define n 9

int main()
{
    char U[N], c[n], ad[14]="administrador";
    int t, p, nu, i;

    nu = cuenta_usuarios();

    do{
        printf("Usuario: \n");
        fgets(U, N, stdin);
        printf("Contraseña: \n");
        fgets(c, n, stdin);
        for(i = 0; i < nu || t == 1; i++){
            if(strcmp(U, v_usuarios[i].Usuario) == 0){
                t = 1;
            }else{
                t = 0;
            }
        }
        for(i = 0; i < nu || p == 1; i++){
            if(strcmp(c, v_usuarios[i].Contrasena) == 0){
                p = 1;
            }else{
                p = 0;
            }
        }
    }while(t != 1 && p != 1);

    if(strcmp(ad, v_usuarios[i].Perfil_usuario) == 0){

    }else{

    }
}
