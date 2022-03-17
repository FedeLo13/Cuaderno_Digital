#include "Usuarios.h"
#include "Funciones_clave.h"

static void vuelva_usuarios(){

}
void carga_usuarios(){
    char aux,temp[100];
    FILE *f;
    int i,j,cont=0;
    f=fopen("Usuarios.txt","r");
    if(f == NULL){
        printf("No se ha podido abrir el fichero.\n");
        exit(1)
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }

    rewind(f);
    
    v_usuarios = (Usuario*)malloc(cont*sizeof(Usuario));

    if(v_usuarios == NULL){
        printf("No se ha podido reservar la memoria.\n");
        exit(1);
    }

    for(i=0;!feof(f);i++){
        vaciar(temp,100);
        aux='0';
        cont=0;
        for(j=0;aux!= '-';j++){
            aux= fgetc(f);
            if(aux!='-'){
                temp[j]=aux;
            }
        }
        v_usuarios[i].Id_usuario=atoi(temp);
        vaciar(temp,100);
        for(j=0;aux!= '-';j++){
            aux= fgetc(f);
            if(aux!='-'){
                temp[j]=aux;
            }
        }
        strcpy(v_usuarios[i].Nomb_usuario,temp);
        vaciar(temp,100);
        for(j=0;aux!='-';j++){
            aux= fgetc(f);
            if(aux!= '-'){
                temp[j]=aux;
            }
        }
        strcpy(v_usuarios[i].Perfil_usuario,temp);
        vaciar (temp,100);
        for(j=0;aux!='-';j++){
            aux= fgetc(f);
            if(aux!= '-'){
                temp[j]=aux;
            }
        }
        strcpy(v_usuarios[i].Usuario,temp);
        vaciar (temp,100);
        for(j=0;aux!='-';j++){
            aux= fgetc(f);
            if(aux!= '-'){
                temp[j]=aux;
            }
        }
        strcpy(v_usuarios[i].Contraseña,temp);
        vaciar (temp,100);
    }
    fclose(f)
}
int cuenta_usuarios(){
    FILE *f;
    int cont=0;

     f=fopen("Usuarios.txt","r");
    if(f == NULL){
        printf("No se ha podido abrir el fichero.\n");
        exit(1)
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    fclose(f);
    return(cont);
}
