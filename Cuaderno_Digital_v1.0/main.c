#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#include "funciones_clave.h"
#include "alumnos.h"
#define N 6
#define n 9

void usuarios();
void alum();
void mat();
void hor();
void admin();

int main()
{
    char U[N], c[n], ad[14]="administrador";
    int t, p, nu, i;

    do{ //Log in//
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
        admin();
    }else{

    }
    return 0;
}

void admin(){ //Menu Principal//
    int c;
    do{
        printf("¿Que operacion desea realizar?\n");
        printf("(1) Gestion de usuarios.\n");
        printf("(2) Gestion de alumnos\n");
        printf("(3) Gestion de materias\n");
        printf("(4) Gestion de horarios.\n");
        printf("(5) Cerrar el programa\n");
        scanf("%i", &c);
        switch(c){
            case 1: usuarios();
            break;
            case 2: alum();
            break;
            case 3: mat();
            break;
            case 4: hor();
            break;
            case 5: system("pause");
            default: printf("Operacion no reconocida");
            break;
        }
    }while(c >= 6);
}

void usuarios(){ //Funcion de usuarios//
    int c;
    do{
        printf("(1) Añadir usuario.\n");
        printf("(2) Eliminar usuario.\n");
        printf("(3) Modificar ususarios\n");
        printf("(4) Listar usuarios\n");
        printf("(5) Volver al menu principal.\n");
        scanf("%i", &c);
        switch(c){
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
                admin();
            break;
            default: printf("Operacion incorrecta.\n");
            break;
        }
    }while(c >= 6);
}

void alum(){   //Funcion de alumnos//
    int c;
    do{
        printf("(1) Añadir alumno.\n");
        printf("(2) Eliminar alumno.\n");
        printf("(3) Modificar alumnos\n");
        printf("(4) Listar alumnos\n");
        printf("(5) Volver al menu principal.\n");
        scanf("%i", &c);
        switch(c){
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
                admin();
            break;
            default: printf("Operacion incorrecta.\n");
            break;
    }
}while(c>=6);
}
void mat(){
    int c;
    do{
        printf("(1) Añadir materias.\n");
        printf("(2) Eliminar materias.\n");
        printf("(3) Modificar materias\n");
        printf("(4) Listar materias\n");
        printf("(5) Volver al menu principal.\n");
        scanf("%i", &c);
        switch(c){
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
                admin();
            break;
            default: printf("Operacion incorrecta.\n");
            break;
    }
    }while(c >= 6);
}

void hor(){
    int c;
    do{
        printf("(1) Añadir hora.\n");
        printf("(2) Eliminar hora.\n");
        printf("(3) Modificar horarios\n");
        printf("(4) Listar horarios\n");
        printf("(5) Volver al menu principal.\n");
        scanf("%i", &c);
        switch(c){
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
                admin();
            break;
            default: printf("Operacion incorrecta.\n");
            break;
    }
    }while(c >= 6);
}
