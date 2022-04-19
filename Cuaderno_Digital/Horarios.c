#include "horarios.h"
#include "funciones_clave.c"

int main(){
    int n;
    carga_horarios();
    crea_horarios();
    modifica_horarios();
    elimina_horarios();
    lista_horarios();
    return 0;
}

void carga_horarios(){

    int cont=0,i,j,semaforo;
    char temp[100],*aux;
    const char s[2] = "-";
    FILE *f;
    f = fopen("horarios.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }

    rewind(f);
    v_horarios = (horarios*)malloc(cont*sizeof(horarios));
    if(v_horarios == NULL){
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
                    strcpy(v_horarios[i].Id_profesor,aux);
                    break;
                case 2:
                    strcpy(v_horarios[i].Dia_clase,aux);
                    break;
                case 3:
                    strcpy(v_horarios[i].Hora_clase,aux);
                    break;
                case 4:
                    strcpy(v_horarios[i].Id_materia,aux);
                    break;
                case 5:
                    strcpy(v_horarios[i].Grupo,aux);
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
            if(v_horarios[i].Grupo[j] == '\n'){
                v_horarios[i].Grupo[j] = '\0';
                semaforo=1;
            }
        }
    }
    fclose(f);
}

void lista_horarios(){
    int cont=0,i;
    char temp[100];
    FILE *f;
    f = fopen("horarios.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    for(i=0;i<cont;i++){
        printf("%i. %s %s %s\n",i+1,v_horarios[i].Id_profesor,v_horarios[i].Dia_clase,v_horarios[i].Hora_clase,v_horarios[i].Id_materia,v_horarios[i].Grupo);
    }
    fclose(f);
}

void modifica_horarios(){
    int cont=0,n;
    char temp[100],c,aux[100];
    lista_horarios();
    FILE *f;
    f = fopen("horarios.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }

    do{
        printf("Introduce el numero horario que desea editar\n");
        scanf("%i",&n);
        fflush(stdin);
    }while(n<=0 || n>cont);
    n--;
    do{
        printf("Escriba el nuevo dia (maximo 1 digitos), o escriba x si no quiere editarlo\n");
        gets(aux);
        fflush(stdin);
        if(strcmp(aux,"x")!=0){
            strcpy(v_horarios[n].Dia_clase,aux);
        }
    }while(strlen(v_horarios[n].Dia_clase) > 1);
    do{
        printf("Escriba la nueva hora (maximo 1 caracter), o escriba x si no quiere editarlo\n");
        gets(aux);
        fflush(stdin);
        if(strcmp(aux,"x")!=0){
            strcpy(v_horarios[n].Hora_clase,aux);
        }
    }while(strlen(v_horarios[n].Hora_clase) > 1);
    do{
        printf("Escriba el nuevo identificador de materia (maximo 4 caracteres), o escriba x si no quiere editarlo\n");
        gets(aux);
        fflush(stdin);
        if(strcmp(aux,"x")!=0){
            strcpy(v_horarios[n].Id_materia,aux);
        }
    }while(strlen(v_horarios[n].Id_materia) > 4);
    do{
        printf("Escriba el nuevo grupo(maximo 10 caracteres), o escriba x si no quiere editarlo\n");
        gets(aux);
        fflush(stdin);
        if(strcmp(aux,"x")!=0){
            strcpy(v_horarios[n].Grupo,aux);
        }
    }while(strlen(v_horarios[n].Grupo) > 10);
    do{
    printf("Esta seguro/a de que quiere realizar estos cambios? (s/n)\n");
    scanf("%c",&c);
    fflush(stdin);
    if(c == 'n'){
        vaciar(v_horarios[n].Id_profesor,strlen(v_horarios[n].Id_profesor));
        vaciar(v_horarios[n].Dia_clase,strlen(v_horarios[n].Dia_clase));
        vaciar(v_horarios[n].Hora_clase,strlen(v_horarios[n].Hora_clase));
        vaciar(v_horarios[n].Id_materia,strlen(v_horarios[n].Id_materia));
        vaciar(v_horarios[n].Grupo,strlen(v_horarios[n].Grupo));
    }
    }while(c != 'n' && c!='s');
    fclose(f);
}


void crea_horarios(){
    int n,cont=0,i,v=1;
    char c,temp[100];
    FILE *f;
    f = fopen("horarios.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    i=cont;
    cont++;
    v_horarios=(horarios*)realloc(v_horarios,cont*sizeof(horarios));
    do{
        printf("Introduzca el dia %s (maximo 5 digitos)\n",v_horarios[i].Dia_clase);
        gets(v_horarios[i].Dia_clase);
        fflush(stdin);
    }while(strlen(v_horarios[i].Dia_clase) > 5);
    do{
        printf("Introduzca la hora %s (maximo 6 caracteres)\n",v_horarios[i].Hora_clase);
        gets(v_horarios[i].Hora_clase);
        fflush(stdin);
    }while(strlen(v_horarios[i].Hora_clase) > 6);
    do{
        printf("Introduzca la materia %s (maximo 5 caracteres)\n",v_horarios[i].Id_materia);
        gets(v_horarios[i].Id_materia);
        fflush(stdin);
    }while(strlen(v_horarios[i].Id_materia) > 5);
    do{
        printf("Introduzca el grupo %s (maximo 10 caracteres)\n",v_horarios[i].Grupo);
        gets(v_horarios[i].Grupo);
        fflush(stdin);
    }while(strlen(v_horarios[i].Grupo) > 10);
    do{
    printf("Esta seguro/a de que quiere realizar esta operacion? (s/n)\n");
    scanf("%c",&c);
    fflush(stdin);
    if(c == 'n'){
        vaciar(v_horarios[i].Id_profesor,strlen(v_horarios[i].Id_profesor));
        vaciar(v_horarios[i].Dia_clase,strlen(v_horarios[i].Dia_clase));
        vaciar(v_horarios[i].Hora_clase,strlen(v_horarios[i].Hora_clase));
        vaciar(v_horarios[i].Id_materia,strlen(v_horarios[i].Id_materia));
        vaciar(v_horarios[i].Grupo,strlen(v_horarios[i].Grupo));
        v_horarios=(horarios*)realloc(v_horarios,i*sizeof(horarios));
        v=0;
    }
    }while(c != 'n' && c!='s');
    fclose(f);
    vuelca_horarios(v);
}

void elimina_horarios(){
    int cont=0,n,i=0,dia=0,j,v=-1;
    char temp[100];
    lista_horarios();
    FILE *f;
    f = fopen("horarios.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    do{
        printf("Introduce el numero correspondiente al horario que desea eliminar\n");
        scanf("%i",&n);
        fflush(stdin);
    }while(n<=0 || n>cont);
    n--;
    cont--;
    if (strcmp(v_horarios[n].Dia_clase,"horarios") == 0){
        while(i<cont && dia < 2){
            if(strcmp(v_horarios[i].Dia_clase,"horarios") == 0){
                dia++;
            }
            i++;
        }
    }
    if(dia == 1){
        printf("No se puede realizar esta accion debido a que solo existe 1 horario\n");
        v=0;
    }
    else{
        vaciar(v_horarios[n].Id_profesor,strlen(v_horarios[n].Id_profesor));
        vaciar(v_horarios[n].Dia_clase,strlen(v_horarios[n].Dia_clase));
        vaciar(v_horarios[n].Hora_clase,strlen(v_horarios[n].Hora_clase));
        vaciar(v_horarios[n].Id_materia,strlen(v_horarios[n].Id_materia));
        vaciar(v_horarios[n].Grupo,strlen(v_horarios[n].Grupo));
        if(n<cont){
            for(j=n;j<cont;j++){
                strcpy(v_horarios[j].Id_profesor,v_horarios[j+1].Id_profesor);
                vaciar(v_horarios[j+1].Id_profesor,strlen(v_horarios[j+1].Id_profesor));
                strcpy(v_horarios[j].Dia_clase,v_horarios[j+1].Dia_clase);
                vaciar(v_horarios[j+1].Dia_clase,strlen(v_horarios[j+1].Dia_clase));
                strcpy(v_horarios[j].Hora_clase,v_horarios[j+1].Hora_clase);
                vaciar(v_horarios[j+1].Hora_clase,strlen(v_horarios[j+1].Hora_clase));
                strcpy(v_horarios[j].Id_materia,v_horarios[j+1].Id_materia);
                vaciar(v_horarios[j+1].Id_materia,strlen(v_horarios[j+1].Id_materia));
                strcpy(v_horarios[j].Grupo,v_horarios[j+1].Grupo);
                vaciar(v_horarios[j+1].Grupo,strlen(v_horarios[j+1].Grupo));
            }
            v_horarios=(horarios*)realloc(v_horarios,cont*sizeof(horarios));
         }
         else{
            v_horarios=(horarios*)realloc(v_horarios,cont*sizeof(horarios));
         }
    }
    fclose(f);
    vuelca_horarios(v);
}

void vuelca_horarios(int n){
    int cont=0,i;
    char temp[100];
    FILE *f;
    f = fopen("hoarios.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    fclose(f);
    cont= cont + n;
    f = fopen("horarios.txt","w");
    if(f == NULL){
      printf("Error al abrir el fichero.\n");
    }
    for(i=0;i<cont;i++){
        fprintf(f,"%s-%s-%s-%s-%s",v_horarios[i].Id_profesor,v_horarios[i].Dia_clase,v_horarios[i].Hora_clase,v_horarios[i].Id_materia,v_horarios[i].Grupo);
        if(i != (cont-1)){
            fprintf(f,"\n");
        }
    }
    fclose(f);
}
