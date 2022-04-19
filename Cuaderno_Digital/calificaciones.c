#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Calificaciones.h"

int CargarCalificaciones(Calificacion **ptr){
    FILE *f;
    f = fopen("Calificaciones.txt","r");
    Calificacion *calificaciones;
    calificaciones = malloc(sizeof(Calificacion));
    char ch = fgetc(f);
    int o = 0;
    if(ch != EOF){
        fseek(f,-1L,SEEK_CUR);

        do{
            int i = 0;
            ch=fgetc(f);

             do{
                calificaciones[o].fecha[i] = ch;
                i++;
                ch=fgetc(f);
            }while(ch != '-');
            calificaciones[o].fecha[i] = '\0';

            i = 0;
            ch = fgetc(f);

             do{
                calificaciones[o].descripcion[i] = ch;
                i++;
                ch=fgetc(f);
            }while(ch != '-');
            calificaciones[o].descripcion[i] = '\0';

            i = 0;
            ch = fgetc(f);

            do{
                calificaciones[o].idMateria[i] = ch;
                i++;
                ch=fgetc(f);
            }while(ch != '-');
            calificaciones[o].idMateria[i] = '\0';

            i = 0;
            ch = fgetc(f);
            do{
                calificaciones[o].idAlumno[i] = ch;
                i++;
                ch=fgetc(f);
            }while(ch != '-');
            calificaciones[o].idAlumno[i] = '\0';

            i = 0;
            ch = fgetc(f);
            do{
                calificaciones[o].nota[i] = ch;
                i++;
                ch=fgetc(f);
            }while(ch != '\n' && ch != EOF);
            calificaciones[o].nota[i] = '\0';

            if(ch != EOF){
                o++;
                calificaciones = realloc(calificaciones,(o + 1) * sizeof(Calificacion));
            }

        }while(ch != EOF);

        *ptr = calificaciones;
        return o+1;
    }
    return 0;
}

void ListarCalificaciones(){
    Calificacion *calificaciones;
    int nCalificaciones = CargarCalificaciones(&calificaciones);

    for(int i = 0; i<nCalificaciones;i++){
        printf("%s %s %s %s %s\n",calificaciones[i].fecha,calificaciones[i].descripcion, calificaciones[i].idMateria, calificaciones[i].idAlumno,calificaciones[i].nota);
    }
}

void EscribirCalificaciones(Calificacion *calificaciones, int nCalificaciones){
    FILE *f;
    f = fopen("Calificaciones.txt","w");
    for(int i = 0; i<nCalificaciones;i++){
        fprintf(f,"%s-%s-%s-%s-%s", calificaciones[i].fecha, calificaciones[i].descripcion, calificaciones[i].idMateria, calificaciones[i].idAlumno, calificaciones[i].nota);
        if(i!=nCalificaciones-1){
            fprintf(f,"\n");
        }
    }
}

void CrearCalificacion()
{
    Calificacion *calificaciones;
    int nCalificaciones = CargarCalificaciones(&calificaciones);
    nCalificaciones++;
    calificaciones  = realloc(calificaciones,(nCalificaciones) * sizeof(Calificacion));

    char fecha[11];
    char descripcion[31];
    char idMateria[5];
    char idAlumno[7];
    char nota[3];

    int o = nCalificaciones - 1;
    int repetido = 0;
   // do{
        repetido = 0;
        printf ("\t INTRODUCE LA FECHA DEL EXAMEN\n");
        fflush (stdin);
        scanf ("%10s",fecha);
       /* for(int i=0;i<o;i++){
            if(strcmp(fecha,calificaciones[i].fecha) == 0){
                repetido = 1;
                printf("ESE ID DE MATERIA YA EXISTE\n");
            }
        }
    }while(repetido == 1);*/

    //do{
        repetido = 0;
        printf ("\t INTRODUCE LA UNIDAD DEL EXAMEN\n");
        fflush (stdin);
        fgets(descripcion,30,stdin);
        for(int i=0; i<10;i++){
            if(descripcion[i] == '\n'){
                descripcion[i] = '\0';
            }
        }
        /*for(int i=0;i<o;i++){
            if(strcmp(nomMateria,materias[i].nomMateria) == 0){
                repetido = 1;
                printf("ESE NOMBRE DE MATERIA YA EXISTE\n");
            }
        }
    }while(repetido == 1);*/

    //do{
        repetido = 0;
        printf ("\t INTRODUCE LA ID DE LA MATERIA\n");
        fflush (stdin);
        scanf ("%4s",idMateria);
        /*for(int i=0;i<o;i++){
        if(strcmp(idMateria,materias[i].idMateria) == 0){
                repetido = 1;
                printf("ESA ABREVIATUR YA EXISTE\n");
            }
        }
    }while(repetido == 1);*/

            repetido = 0;
        printf ("\t INTRODUCE LA ID DEL ALUMNO\n");
        fflush (stdin);
        scanf ("%6s",idAlumno);

        repetido = 0;
        printf ("\t INTRODUCE LA NOTA\n");
        fflush (stdin);
        scanf ("%2s",nota);


    strcpy(calificaciones[o].fecha, fecha);
    strcpy(calificaciones[o].descripcion, descripcion);
    strcpy(calificaciones[o].idMateria, idMateria);
    strcpy(calificaciones[o].idAlumno, idAlumno);
    strcpy(calificaciones[o].nota, nota );

    fflush(stdin);
    free(calificaciones);

    FILE *f;
    f = fopen("Calificaciones.txt","r+");
    char ch = fgetc(f);

    while(ch != EOF){
        ch = fgetc(f);
    }

    fprintf(f,"\n%s-%s-%s-%s-%s", fecha, descripcion, idMateria,idAlumno,nota);
    fclose(f);
}

void EliminarCalificacion(){
    Calificacion *calificaciones;
    int nCalificaciones = CargarCalificaciones(&calificaciones);

    char fecha[11];
    char descripcion[31];
    char idMateria[5];
    char idAlumno[7];
    
    printf("INTRODUZCA LA FECHA DE LA CALIFICACION QUE QUIERA ELIMINAR\n");
    fflush(stdin);
    scanf("%10s",fecha);
    printf("INTRODUZCA LA DESCRIPCIÓN\n");
    fflush(stdin);
    fgets(descripcion,30,stdin);
        for(int i=0; i<30;i++){
            if(descripcion[i] == '\n'){
                descripcion[i] = '\0';
            }
        }
    printf("INTRODUZCA EL ID DE LA MATERIA\n");
    fflush(stdin);
    scanf("%4s",idMateria);
    printf("INTRODUZCA EL ID DEL ALUMNO\n");
    fflush(stdin);
    scanf("%6s",idAlumno);

    int pos;
    int encontrado = 0;
    for(int i=0;i<nCalificaciones;i++){
        if(strcmp(calificaciones[i].fecha, fecha) == 0 && strcmp(calificaciones[i].descripcion, descripcion) == 0 && strcmp(calificaciones[i].idMateria,idMateria) == 0 && strcmp(calificaciones[i].idAlumno,idAlumno)==0){
            i = pos;
            encontrado = 1;
        }
    }
    if(encontrado == 1){
        calificaciones--;
        for(int i=pos; i<nCalificaciones;i++){
            strcpy(calificaciones[i].fecha, calificaciones[i+1].fecha);
            strcpy(calificaciones[i].descripcion, calificaciones[i+1].descripcion);
            strcpy(calificaciones[i].idMateria, calificaciones[i+1].idMateria);
            strcpy(calificaciones[i].idAlumno, calificaciones[i+1].idAlumno);
            strcpy(calificaciones[i].nota, calificaciones[i+1].nota);
        }
        EscribirCalificaciones(calificaciones,nCalificaciones);
    }else{
        printf("No se ha encontrado la calificación a eliminar\n");
    }
    free(calificaciones);
}