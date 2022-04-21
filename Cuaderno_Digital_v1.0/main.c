#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "usuarios.h"
#include "funciones_clave.h"
#include "alumnos.h"
#include "materias.h"
#include "Matricula.h"
#include "Horarios.h"
#include "Calificaciones.h"
#define N 6
#define n 9

void usuarios();
void alum();
void mat();
void hor();
void admin();
void prof();

int main()
{
    char U[N], c[n], ad[14]="administrador";
    int t, p, nu, i;
    setlocale(LC_CTYPE, "Spanish");
    nu = cuenta_usuarios();

    do{ //Log in//
        printf("Usuario: \n");
        fgets(U, N, stdin);
        printf("Contrase�a: \n");
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
        //prof();
    }
    return 0;
}

void admin(){ //Menu Principal//
    int c;
    do{
        printf("�Que operacion desea realizar?\n");
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
    carga_usuarios();
    do{
        printf("(1) A�adir usuario.\n");
        printf("(2) Eliminar usuario.\n");
        printf("(3) Modificar ususarios\n");
        printf("(4) Listar usuarios\n");
        printf("(5) Volver al menu principal.\n");
        scanf("%i", &c);
        switch(c){
            case 1: crea_usuarios();
            break;
            case 2: elimina_usuarios();
            break;
            case 3: modifica_usuarios();
            break;
            case 4: lista_usuarios();
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
    carga_alumnos();
    do{
        printf("(1) A�adir alumno.\n");
        printf("(2) Eliminar alumno.\n");
        printf("(3) Modificar alumnos\n");
        printf("(4) Listar alumnos\n");
        printf("(5) Volver al menu principal.\n");
        scanf("%i", &c);
        switch(c){
            case 1: addalum();
            break;
            case 2: delalum();
            break;
            case 3: modalum();
            break;
            case 4: listalum();
            break;
            case 5:
                admin();
            break;
            default: printf("Operacion incorrecta.\n");
            break;
        }
    }while(c>=6);
    endalum();
}
void mat(){
    int c;
    CargarMaterias();
    do{
        printf("(1) A�adir materias.\n");
        printf("(2) Eliminar materias.\n");
        printf("(3) Modificar materias\n");
        printf("(4) Listar materias\n");
        printf("(5) Volver al menu principal.\n");
        scanf("%i", &c);
        switch(c){
            case 1: CrearMateria();
            break;
            case 2: EliminarMaterias();
            break;
            case 3: ModificarMaterias();
            break;
            case 4: ListarMaterias();
            break;
            case 5:
                admin();
            break;
            default: printf("Operacion incorrecta.\n");
            break;
    }
    }while(c >= 6);
    EscribirMaterias();
}

void hor(){
    int c;
    carga_horarios();
    do{
        printf("(1) A�adir hora.\n");
        printf("(2) Eliminar hora.\n");
        printf("(3) Modificar horarios\n");
        printf("(4) Listar horarios\n");
        printf("(5) Volver al menu principal.\n");
        scanf("%i", &c);
        switch(c){
            case 1: crea_horarios();
            break;
            case 2: elimina_horarios();
            break;
            case 3: modifica_horarios();
            break;
            case 4: lista_horarios();
            break;
            case 5:
                admin();
            break;
            default: printf("Operacion incorrecta.\n");
            break;
    }
    }while(c >= 6);

}

void prof(){
    char c[11], d[51], s;
    int i, j, k, m, z, v[100], ja, y;
    m = CuentaMaterias;
    carga_alumnos();
    carga_matricula();
    do{
        y = 0;
        printf("¿Que grupo quiere consultar?\n");
        gets(c);
        printf("¿Que materia desea consultar\n?");
        gets(d);
        printf("(1) Listar alumno\n");
        printf("(2) Calificaciones\n");
        printf("(3) Volver\n");
        scanf("%i", &z);
        switch(z){
            case 1: for(i = 0; i < m ; i++){
                        if(strcmp(d, materias[i].nomMateria) == 0){
                            for(j = 0; j < ; j++){
                                if(strcmp(v_matricula[j].Id_materia, materias[i].idMateria) == 0){
                                    for(k = 0; k < l; k++){
                                        if(strcmp(alun[k].id_alum, v_matricula[j].Id_alum) == 0 && strcmp(alun[k].grupo, c) == 0){
                                            v[y] = k;
                                            y++;
                                            printf("(%i)\n", y+1)
                                            printf("%s\n", alun[k].id_alum);
                                            printf("%s\n", alun[k].nombre_alum);
                                            printf("%s\n", alun[k].direc_alum);
                                            printf("%s\n", alun[k].local_alum);
                                            printf("%s\n", alun[k].curso);
                                            printf("%s\n\n", alun[k].grupo);
                                        }
                                    }
                                }
                            }
                        }
                    }
                    printf("Desea modificar algun dato?\n");
                    s = getc(s);
                    if(c == s){
                    printf("¿Que alumno desea modificar?\n");
                    scanf("%i", &y);
                    fflush(stdin);
                    y--;
                    do{
                        printf("¿Que dato desea modificar?\n");
                        printf("(1)Nombre\n");
                        printf("(2)Direccion\n");
                        printf("(3)Localidad\n");
                        printf("(4)Curso\n");
                        printf("(5)Grupo\n");
                        scanf("%i", &ja);
                        fflush(stdin);
                        switch(ja){
                            case 1:
                                do{
                                    printf("Introduce el nuevo dato: \n");
                                    gets(dat);
                                    fflush(stdin);
                                    strcpy(alun[v[y]].nombre_alum, dat);
                                }while(strlen(alun[v[y]].nombre_alum) > 21);
					break;
					case 2:
					    do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(alun[v[y]].direc_alum, dat);
                        }while(strlen(alun[v[y]].direc_alum) > 31);
					break;
					case 3:
					    do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(alun[v[y]].local_alum, dat);
					    }while(strlen(alun[v[y]].local_alum) > 31);
					break;
					case 4:
					    do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(alun[v[y]].curso, dat);
					    }while(strlen(alun[v[y]].curso) > 31);
					break;
					case 5:
					    do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(alun[v[y]].grupo, dat);
					    }while(strlen(alun[v[y]].grupo) > 11);
					break;
					default: printf("Numero incorrecto.\n");
					break;
				}
				printf("¿Desea hacer otra modificacion? y/n\n");
				c = getc(stdin);
				fflush(stdin);
			}while(c != 'n');
            }

            break;

            case 2: for(i = 0; i < ; i++){
                        if(strcmp(materias[i].nomMateria, d) == 0){
                            for(j = 0; j < ; j++){
                                if(strcmp(, materias[i].idMateria){
                                    for(k = 0, k < l; k++){
                                        if(strcmp(, alun[k].id_alum) == 0 && strcmp(alun[k].grupo, c)){
                                            printf("%s-", alun[i].nombre_alum);
                                            printf("%s\n", v_matricula[j].)
                                        }
                                    }
                                }
                            }
                        }
                    }


            break;
            case 3:

            break;
            default: printf("Operacion incorrecta\n");
<            break;
        }
        printf("¿Desea realizar otra operacion?\n");
        s = getc(s);
    }while(s == 's');

}
