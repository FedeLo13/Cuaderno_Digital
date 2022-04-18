#include "matricula.h"
#include "funciones_clave.c"

int main(){
    int n;
    carga_matricula();
    crea_matricula();
    modifica_matricula();
    elimina_matricula();
    lista_matricula();
    return 0;
}
void carga_matricula(){

    int cont=0,i,j,semaforo;
    char temp[100],*aux;
    const char s[2] = "-";
    FILE *f;
    f = fopen("matriculas.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }

    rewind(f);
    v_matricula = (matricula*)malloc(cont*sizeof(matricula));
    if(v_matricula == NULL){
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
                    strcpy(v_matricula[i].Id_materia,aux);
                    break;
                case 2:
                    strcpy(v_matricula[i].Id_alum,aux);
                    break;
            }
            aux = strtok(NULL,s);
            j++;
        }
    }

    fclose(f);
}

void lista_matricula(){
    int cont=0,i;
    char temp[100];
    FILE *f;
    f = fopen("matriculas.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    for(i=0;i<cont;i++){
        printf("%i. %s %s %s\n",i+1,v_matricula[i].Id_materia,v_matricula[i].Id_alum);
    }
    fclose(f);
}

void modifica_matricula(){
    int cont=0,n;
    char temp[100],c,aux[100];
    lista_usuarios();
    FILE *f;
    f = fopen("matriculas.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }

    do{
        printf("Introduce el numero correspondiente a la matricula que desea editar\n");
        scanf("%i",&n);
        fflush(stdin);
    }while(n<=0 || n>cont);
    n--;
    do{
        printf("Escriba el nuevo identificador de materia (maximo 4 digitos), o escriba x si no quiere editarlo\n");
        gets(aux);
        fflush(stdin);
        if(strcmp(aux,"x")!=0){
            strcpy(v_matricula[n].Id_materia,aux);
        }
    }while(strlen(v_usuarios[n].Id_materia) > 3);
    do{
        printf("Escriba el nuevo nombre (maximo 20 caracteres), o escriba x si no quiere editarlo\n");
        gets(aux);
        fflush(stdin);
        if(strcmp(aux,"x")!=0){
            strcpy(v_matricula[n].Id_alum,aux);
        }
    }do{
    printf("Esta seguro/a de que quiere realizar estos cambios? (s/n)\n");
    scanf("%c",&c);
    fflush(stdin);
    if(c == 'n'){
        vaciar(v_horario[n].Id_materia,strlen(v_horario[n].Id_materia));
        vaciar(v_horario[n].Id_alum,strlen(v_horario[n].Id_alum));
    }
    }while(c != 'n' && c!='s');
    fclose(f);
}


void crea_matricula(){
    int n,cont=0,i,v=1;
    char c,temp[100];
    FILE *f;
    f = fopen("matriculas.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    i=cont;
    cont++;
    v_matricula=(Matricula*)realloc(v_matricula,cont*sizeof(Matricula));
    do{
        printf("Introduzca el identificador del %s (maximo 3 digitos)\n",v_usuarios[i].Perfil_usuario);
        gets(v_usuarios[i].Id_usuario);
        fflush(stdin);
    }while(strlen(v_usuarios[i].Id_usuario) > 3);
    do{
        printf("Introduzca el nombre del %s (maximo 20 caracteres)\n",v_usuarios[i].Perfil_usuario);
        gets(v_usuarios[i].Nomb_usuario);
        fflush(stdin);
    }while(strlen(v_usuarios[i].Nomb_usuario) > 20);
    do{
        printf("Introduzca el nombre de usuario del %s (maximo 5 caracteres)\n",v_usuarios[i].Perfil_usuario);
        gets(v_usuarios[i].Usuario);
        fflush(stdin);
    }while(strlen(v_usuarios[i].Usuario) > 5);
    do{
        printf("Introduzca la contrasena del %s (maximo 8 caracteres)\n",v_usuarios[i].Perfil_usuario);
        gets(v_usuarios[i].Contrasena);
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
        v=0;
    }
    }while(c != 'n' && c!='s');
    fclose(f);
    vuelca_usuarios(v);
}

void elimina_matricula(){
    int cont=0,n,i=0,admns=0,j,v=-1;
    char temp[100];
    lista_usuarios();
    FILE *f;
    f = fopen("matriculas.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    do{
        printf("Introduce el numero correspondiente a la matricula que desea eliminar\n");
        scanf("%i",&n);
        fflush(stdin);
    }while(n<=0 || n>cont);
    n--;
    cont--;
    if (strcmp(v_matricula[n].Perfil_usuario,"administrador") == 0){
        while(i<cont && admns < 2){
            if(strcmp(v_usuarios[i].Perfil_usuario,"administrador") == 0){
                admns++;
            }
            i++;
        }
    }
    if(admns == 1){
        printf("No se puede realizar esta accion debido a que solo existe 1 administrador\n");
        v=0;
    }
    else{
        vaciar(v_matricula[n].Id_materia,strlen(v_matricula[n].Id_materia));
        vaciar(v_matricula[n].Id_alum,strlen(v_matricula[n].Id_alum));
        if(n<cont){
            for(j=n;j<cont;j++){
                strcpy(v_matricula[j].Id_materia,v_matricula[j+1].Id_materia);
                vaciar(v_matricula[j+1].Id_materia,strlen(v_matricula[j+1].Id_materia));
                strcpy(v_matricula[j].Id_alum,v_matricula[j+1].Id_alum);
                vaciar(v_matricula[j+1].Id_alum,strlen(v_usuarios[j+1].Id_alum));
            }
            v_matricula=(Matricula*)realloc(v_matricula,cont*sizeof(matricula));
         }
         else{
            v_matricula=(matricula*)realloc(v_matricula,cont*sizeof(matricula));
         }
    }
    fclose(f);
    vuelca_matricula(v);
}

void vuelca_matricula(int n){
    int cont=0,i;
    char temp[100];
    FILE *f;
    f = fopen("matriculas.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    fclose(f);
    cont= cont + n;
    f = fopen("matriculas.txt","w");
    if(f == NULL){
      printf("Error al abrir el fichero.\n");
    }
    for(i=0;i<cont;i++){
        fprintf(f,"%s-%s-%s-%s-%s",v_matricula[i].Id_materia,v_matricula[i].Id_alum);
        if(i != (cont-1)){
            fprintf(f,"\n");
        }
    }
    fclose(f);
}