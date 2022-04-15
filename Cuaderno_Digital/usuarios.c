#include "usuarios.h"
#include "funciones_clave.c"

int main(){
    carga_usuarios();
    crea_usuarios();
    lista_usuarios();
    return 0;
}

//cabecera: void carga_usuarios();
//precondición:
//poscondición: carga los datos del fichero en la estructura del programa
void carga_usuarios(){

    int cont=0,i,j,semaforo;
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
    for(i=0;i<cont;i++){
        j=0;
        semaforo=0;
        while(semaforo==0){
            j++;
            if(v_usuarios[i].Contrasena[j] == '\n'){
                v_usuarios[i].Contrasena[j] = '\0';
                semaforo=1;
            }
        }
    }
    fclose(f);
}
void lista_usuarios(){
    int cont=0,i;
    char temp[100];
    FILE *f;
    f = fopen("usuarios.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    for(i=0;i<cont;i++){
        printf("%i. %s %s %s\n",i+1,v_usuarios[i].Id_usuario,v_usuarios[i].Nomb_usuario,v_usuarios[i].Perfil_usuario);
    }
    fclose(f);
}
void modifica_usuarios(){
    lista_usuarios();
}


void crea_usuarios(){
    int n,cont=0,i;
    char c,temp[100];
    FILE *f;
    f = fopen("usuarios.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    i=cont;
    cont++;
    v_usuarios=(Usuario*)realloc(v_usuarios,cont*sizeof(Usuario));
    do{
        printf("Introduzca 1 para crear un profesor, 2 para crear un administrador\n");
        scanf("%i",&n);
        if(n==1){
            char prof[]={'p','r','o','f','e','s','o','r','\0'};
            strcpy(v_usuarios[i].Perfil_usuario,prof);
        }
        else{
            if(n==2){
                char adm[]= {'a','d','m','i','n','i','s','t','r','a','d','o','r','\0'};
                strcpy(v_usuarios[i].Perfil_usuario,adm);
            }
        }
    }while(n != 1 && n != 2);
    if(cont >= 100){
        sprintf(v_usuarios[i].Id_usuario, "%i",cont);
    }
    else{
        if(cont < 10){
            sprintf(v_usuarios[i].Id_usuario,"00%i",cont);
            }
            else{
                sprintf(v_usuarios[i].Id_usuario,"0%i",cont);
            }
    }
    do{
        printf("Introduzca el nombre del %s (maximo 20 caracteres)\n",v_usuarios[i].Perfil_usuario);
        scanf("%s",v_usuarios[i].Nomb_usuario);
        fflush(stdin);
    }while(strlen(v_usuarios[i].Nomb_usuario) > 20);
    do{
        printf("Introduzca el nombre de usuario del %s (maximo 5 caracteres)\n",v_usuarios[i].Perfil_usuario);
        scanf("%s",v_usuarios[i].Usuario);
        fflush(stdin);
    }while(strlen(v_usuarios[i].Usuario) > 5);
    do{
        printf("Introduzca la contrasena del %s (maximo 8 caracteres)\n",v_usuarios[i].Perfil_usuario);
        scanf("%s",v_usuarios[i].Contrasena);
        fflush(stdin);
    }while(strlen(v_usuarios[i].Contrasena) > 8);
    do{
    printf("Esta seguro/a de que quiere realizar esta operacion? (s/n)\n");
    scanf("%c",&c);
    fflush(stdin);
    if(c == 'n'){
        vaciar(v_usuarios[i].Id_usuario,strlen(v_usuarios[i].Id_usuario));
        vaciar(v_usuarios[i].Nomb_usuario,strlen(v_usuarios[i].Nomb_usuario));
        vaciar(v_usuarios[i].Perfil_usuario,strlen(v_usuarios[i].Perfil_usuario));
        vaciar(v_usuarios[i].Usuario,strlen(v_usuarios[i].Usuario));
        vaciar(v_usuarios[i].Contrasena,strlen(v_usuarios[i].Contrasena));
        v_usuarios=(Usuario*)realloc(v_usuarios,i*sizeof(Usuario));
    }
    }while(c != 'n' && c!='s');
    fclose(f);
}
