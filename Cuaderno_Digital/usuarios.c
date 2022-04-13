#include "usuarios.h"
#include "funciones_clave.c"

typedef struct{
    char Id_usuario[50];
    char Nomb_usuario[50];
    char Perfil_usuario[50];
    char Usuario[50];
    char Contrasena[50];
    }Usuario;

Usuario *v_usuarios;


int main(){
    carga_usuarios();
    return 0;
}

//cabecera: void carga_usuarios();
//precondición:
//poscondición: carga los datos del fichero en la estructura del programa
void carga_usuarios(){

    int cont=0,i,j;
    char temp[100],aux[100];
    FILE *f;
    f = fopen("usuarios.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }

    rewind(f);

    v_usuarios = (Usuario*)malloc(cont*sizeof(Usuario));
    if(v_usuarios == NULL){
        printf("No se ha podido reservar la memoria.\n");
    }

    for(i=0; i<1; i++){
            vaciar(temp,100);
        for(j=0;v_usuarios[i].Id_usuario[j]=='-';j++){
            v_usuarios[i].Id_usuario[j]= fgetc(f);
        }
        v_usuarios[i].Id_usuario[j-1]='\0';
        printf("%s",v_usuarios[i].Id_usuario);
    }
    fclose(f);
}
