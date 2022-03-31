#include "Usuarios.h"
#include "Funciones_clave.h"
//Precondición:
//Poscondición: Carga en el vector de usuarios los datos del fichero
void carga_usuarios(){
    char aux,temp[100];                                    //Declaración de variables auxiliares
    FILE *f;
    int i,j,cont=0;
    f=fopen("usuarios.txt","r");                           //Apertura de fichero y prueba de error
    if(f == NULL){
        printf("No se ha podido abrir el fichero.\n");
    }
    while(!feof(f)){                                       //Cuenta el número de filas en el fichero.
        fgets(temp,100,f);
        cont++;
    }

    rewind(f);

    v_usuarios = (Usuario*)malloc(cont*sizeof(Usuario));   //Inicialización del vector dinámico de usuarios y prueba de error

    if(v_usuarios == NULL){
        printf("No se ha podido reservar la memoria.\n");
    }                                                    //Hasta aquí funciona bien de momento
    for(i=0;i<cont;i++){                                 //Bucle encargado de cargar los datos del fichero en el vector
        vaciar(temp,100);
        aux='0';

        for(j=0;aux!= '-';j++){
            aux= fgetc(f);
            if(aux!='-'){
                temp[j]=aux;
                fflush(stdin);
            }
        }
        v_usuarios[i].Id_usuario=atoi(temp);
        fflush(stdin);
        printf("%i\n",v_usuarios[i].Id_usuario);
        aux='0';
        for(j=0;aux!= '-';j++){
            aux= fgetc(f);
            if(aux!= '-'){
                v_usuarios[i].Nomb_usuario[j]=aux;
                fflush(stdin);
            }
        }
        printf("%s\n",v_usuarios[i].Nomb_usuario);
        aux='0';
        for(j=0;aux!='-';j++){
            aux= fgetc(f);
            if(aux!= '-'){
                v_usuarios[i].Perfil_usuario[j]=aux;
                fflush(stdin);
            }
        }
        printf("%s\n",v_usuarios[i].Perfil_usuario);
        aux='0';
        for(j=0;aux!='-';j++){
            aux= fgetc(f);
            if(aux!= '-'){
                v_usuarios[i].Usuario[j]=aux;
                fflush(stdin);
            }
        }
        printf("%s\n",v_usuarios[i].Usuario);
        aux='0';
        for(j=0;aux!='-';j++){
            aux= fgetc(f);
            if(aux!= '-'){
                v_usuarios[i].Contrasena[j]=aux;
                fflush(stdin);
            }
        }
        printf("%s\n",v_usuarios[i].Contrasena);
        vaciar (temp,100);
    }
    fclose(f);
}
int cuenta_usuarios(){
    FILE *f;
    int cont=0;
    char temp[100];

     f=fopen("Usuarios.txt","r");
    if(f == NULL){
        printf("No se ha podido abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    fclose(f);
    return(cont);
}
