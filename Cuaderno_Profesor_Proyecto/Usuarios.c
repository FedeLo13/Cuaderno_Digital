#include "Usuarios.h"
#include "Funciones_clave.h"

void carga_usuarios(Usuario *v_usuarios){
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
        for(j=0,aux!= '-',j++){
            aux= fgetc(f);
            if(aux!='-'){
                temp[j]=aux
            }
        }
    }
    fclose(f)
}