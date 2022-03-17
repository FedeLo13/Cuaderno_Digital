#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <"Usuario.h">
#define N 6
#defien n 9

int main()
{
    char U[N], c[n], ad[13];
    int t, p, nu;

    ad = "administrador";
    nu = cuentausuarios();

    do{
        printf("Usuario: \n");
        fgets(U, N, stdin);
        prinf("Contraseña: \n");
        fgets(c, n, stdin);
        for(i = 0; i < nu || t == 1; i++){
            if(strcmp(U, v_usuarios[i].Usuario) == 0){
                t = 1;
            }else{
                t = 0;
            }
        }
        for(i = 0; i < nu || p == 1; i++){
            if(strcmp(c, v_usuarios[i].Contraseña) == 0){
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
