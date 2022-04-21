#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Calificaciones.h"

void CargarCalificaciones(){
    FILE *f;
    f = fopen("Calificaciones.txt","r");
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
    }
}

void ListarCalificaciones(){
    int nCalificaciones = CuentaCalificaciones();
    for(int i = 0; i<nCalificaciones;i++){
        printf("%s %s %s %s %s\n",calificaciones[i].fecha,calificaciones[i].descripcion, calificaciones[i].idMateria, calificaciones[i].idAlumno,calificaciones[i].nota);
    }
}

void EscribirCalificaciones(){
    FILE *f;
    int nCalificaciones= CuentaCalificaciones();
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
    int nCalificaciones = CuentaCalificaciones();
    nCalificaciones++;
    calificaciones  = realloc(calificaciones,(nCalificaciones) * sizeof(Calificacion));

    char fecha[11];
    char descripcion[31];
    char idMateria[5];
    char idAlumno[7];
    char nota[3];

    int o = nCalificaciones - 1;
    int repetido = 0;
        repetido = 0;
        printf ("\t INTRODUCE LA FECHA DEL EXAMEN\n");
        fflush (stdin);
        scanf ("%10s",fecha);

        repetido = 0;
        printf ("\t INTRODUCE LA UNIDAD DEL EXAMEN\n");
        fflush (stdin);
        fgets(descripcion,30,stdin);
        for(int i=0; i<10;i++){
            if(descripcion[i] == '\n'){
                descripcion[i] = '\0';
            }
        }

        repetido = 0;
        printf ("\t INTRODUCE LA ID DE LA MATERIA\n");
        fflush (stdin);
        scanf ("%4s",idMateria);

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
    int nCalificaciones = CuentaCalificaciones();

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
        EscribirCalificaciones();
    }else{
        printf("No se ha encontrado la calificación a eliminar\n");
    }
    free(calificaciones);
}
int CuentaCalificaciones(){
    int cont=0;
    char temp[100];
    FILE *f;
    f = fopen("calificaciones.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    fclose(f);
    return(cont);
}
void ModificaCalificaciones(){
    int i, j, l;
    l= CuentaCalificaciones();
	char c, dat[31];
	for(i = 0; i < l; i++){
        printf("(%i)%s %s %s\n",i+1,calificaciones[i].idMateria,calificaciones[i].idAlumno,calificaciones[i].descripcion);
	}
	printf("¿Que calificacion desea modificar?\n");
	scanf("%i", &i);
	fflush(stdin);
	i--;
			do{
				printf("¿Que dato desea modificar?\n");
				printf("(1)Fecha\n");
				printf("(2)Descripcion\n");
				printf("(3)Id de la Materia\n");
				printf("(4)Id del alumno\n");
				printf("(5)nota\n");
				scanf("%i", &j);
				fflush(stdin);
				switch(j){
					case 1:
                        do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(calificaciones[i].fecha, dat);
                        }while(strlen(calificaciones[i].fecha) > 11);
					break;
					case 2:
					    do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(calificaciones[i].descripcion, dat);
                        }while(strlen(calificaciones[i].descripcion) > 31);
					break;
					case 3:
					    do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(calificaciones[i].idMateria, dat);
					    }while(strlen(calificaciones[i].idMateria) > 5);
					break;
					case 4:
					    do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(calificaciones[i].idAlumno, dat);
					    }while(strlen(calificaciones[i].idAlumno) > 7);
					break;
					case 5:
					    do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(calificaciones[i].nota, dat);
					    }while(strlen(calificaciones[i].nota) > 3);
					break;
					default: printf("Numero incorrecto.\n");
					break;
				}
				printf("¿Desea hacer otra modificacion? y/n\n");
				c = getc(stdin);
				fflush(stdin);
			}while(c != 'n');
}
