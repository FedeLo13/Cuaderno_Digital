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
    printf("%s\n",v_usuarios[0].Contrasena);
    printf("%s\n",v_usuarios[1].Contrasena);
    printf("%s\n",v_usuarios[2].Contrasena);
    return 0;
}

//cabecera: void carga_usuarios();
//precondición:
//poscondición: carga los datos del fichero en la estructura del programa
void carga_usuarios(){

    int cont=0,i,j,semaforo=0;
    char temp[100],*aux;
    const char s[2] = "-";
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
    for(i=0;i<cont;i++){
        j=1;
        vaciar(temp,100);
        fgets(temp,100,f);
        aux = strtok(temp,s);
        while(aux != NULL){
            switch (j){
                case 1:
                    strcpy(v_usuarios[i].Id_usuario,aux);
                    break;
                case 2:
                    strcpy(v_usuarios[i].Nomb_usuario,aux);
                    break;
                case 3:
                    strcpy(v_usuarios[i].Perfil_usuario,aux);
                    break;
                case 4:
                    strcpy(v_usuarios[i].Usuario,aux);
                    break;
                case 5:
                    strcpy(v_usuarios[i].Contrasena,aux);
                    break;
            }
            aux = strtok(NULL,s);
            j++;
        }
    }
    fclose(f);
}
