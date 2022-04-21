#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Materias.h"

void CargarMaterias(){
    FILE *f;
    f = fopen("Materias.txt","r");
    materias = malloc(sizeof(Materia));
    char ch = fgetc(f);
    int o = 0;
    if(ch != EOF){
        fseek(f,-1L,SEEK_CUR);

        do{
            int i = 0;
            ch=fgetc(f);

            do{
                materias[o].idMateria[i] = ch;
                i++;
                ch=fgetc(f);
            }while(ch != '-');
            materias[o].idMateria[i] = '\0';

            i = 0;
            ch = fgetc(f);
            do{
                materias[o].nomMateria[i] = ch;
                i++;
                ch=fgetc(f);
            }while(ch != '-');
            materias[o].nomMateria[i] = '\0';

            i = 0;
            ch = fgetc(f);
            do{
                materias[o].abrMateria[i] = ch;
                i++;
                ch=fgetc(f);
            }while(ch != '\n' && ch != EOF);
            materias[o].abrMateria[i] = '\0';

            if(ch != EOF){
                o++;
                materias = realloc(materias,(o + 1) * sizeof(Materia));
            }

        }while(ch != EOF);
    }
}

void EscribirMaterias(){
    FILE *f;
    int nMaterias= CuentaMaterias();
    f = fopen("Materias.txt","w");
    for(int i = 0; i<nMaterias;i++){
        fprintf(f,"%s-%s-%s",materias[i].idMateria,materias[i].nomMateria,materias[i].abrMateria);
        if(i != nMaterias-1){
            fprintf(f,"\n");
        }
    }
}

void ListarMaterias(){
    int nMaterias = CuentaMaterias();

    for(int i = 0; i<nMaterias;i++){
        printf("%s %s %s\n",materias[i].idMateria,materias[i].nomMateria,materias[i].abrMateria);
    }
}


void CrearMateria()
{
    int nMaterias = CuentaMaterias();
    nMaterias++;
    materias  = realloc(materias,(nMaterias) * sizeof(Materia));

    char idMateria[5];
    char nomMateria[51];
    char abrMateria[4];
    int o = nMaterias - 1;
    int repetido = 0;
    do{
        repetido = 0;
        printf ("\t INTRODUCE UN ID PARA LA NUEVA MATERIA\n");
        fflush (stdin);
        scanf ("%4s",idMateria);
        for(int i=0;i<o;i++){
            if(strcmp(idMateria,materias[i].idMateria) == 0){
                repetido = 1;
                printf("ESE ID DE MATERIA YA EXISTE\n");
            }
        }
    }while(repetido == 1);

    do{
        repetido = 0;
        printf ("\t INTRODUCE UN NOMBRE PARA LA NUEVA MATERIA\n");
        fflush (stdin);
        fgets(nomMateria,50,stdin);
        for(int i=0; i<50;i++){
            if(nomMateria[i] == '\n'){
                nomMateria[i] = '\0';
            }
        }
        for(int i=0;i<o;i++){
            if(strcmp(nomMateria,materias[i].nomMateria) == 0){
                repetido = 1;
                printf("ESE NOMBRE DE MATERIA YA EXISTE\n");
            }
        }
    }while(repetido == 1);

    do{
        repetido = 0;
        printf ("\t INTRODUCE UNA ABREVIATURA PARA LA NUEVA MATERIA\n");
        fflush (stdin);
        scanf ("%3s",abrMateria);
        for(int i=0;i<o;i++){
            if(strcmp(abrMateria,materias[i].abrMateria) == 0){
                repetido = 1;
                printf("ESA ABREVIATUR YA EXISTE\n");
            }
        }
    }while(repetido == 1);

    strcpy(materias[o].idMateria, idMateria);
    strcpy(materias[o].nomMateria, nomMateria);
    strcpy(materias[o].abrMateria, abrMateria);

    fflush(stdin);
    free(materias);

    FILE *f;
    f = fopen("Materias.txt","r+");
    char ch = fgetc(f);

    while(ch != EOF){
        ch = fgetc(f);
    }

    fprintf(f,"\n%s-%s-%s", idMateria, nomMateria, abrMateria);
    fclose(f);
}
void EliminarMaterias ()
{
    int nMaterias = CuentaMaterias();

    int m;
    char idMateria[5];

    if (nMaterias == 0){
        printf ("\tNo existe ninguna materia creada\n");
    }else{

        printf ("\tINTRODUCE EL ID DE LA MATERIA QUE DESEA ELIMINAR\n");
        scanf ("%3s",idMateria);


        for (int i=0;i<nMaterias;i++){

            if (strcmp(materias[i].idMateria,idMateria)==0){
                m=i;
            }
        }
        nMaterias--;
        for (int i=m;i<nMaterias;i++){
            strcpy(materias[i].abrMateria,materias[i+1].abrMateria);
            strcpy(materias[i].idMateria,materias[i+1].idMateria);
            strcpy(materias[i].nomMateria,materias[i+1].nomMateria);
        }
        EscribirMaterias();
        free(materias);
    }

}

int CuentaMaterias(){
    int cont=0;
    char temp[100];
    FILE *f;
    f = fopen("materias.txt","r");
    if(f == NULL){
        printf("Error al abrir el fichero.\n");
    }

    while(!feof(f)){
        fgets(temp,100,f);
        cont++;
    }
    fclose(f);
    return(cont);

void ModificarMaterias(){

     Materia *materias;
    int nMaterias = CargarMaterias(&materias);

	int i, j;
	char c, [31];
	char idMateria[5];
	char nomMateria[51];
	char abrMateria[4];
	for(i = 0; i < l; i++){
        printf("(%i)%s\n",i+1,materias[i].nomMateria);
	}
	printf("�Que materia desea modificar?\n");
	scanf("%i", &i);
	fflush(stdin);
	i--;
			do{
				printf("�Que dato desea modificar?\n");
				printf("(1)id\n");
				printf("(2)nombre\n");
				printf("(3)abreviatura\n");
				scanf("%i", &j);
				fflush(stdin);
				switch(j){
					case 1:
                        do{
                            printf("Introduce la nueva id: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(materias[i].idMateria, idMateria);
                        }while(strlen(materias[i].idMateria) > 5);
                        break;

					case 2:
					    do{
                            printf("Introduce el nuevo nombre: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(materias[i].nomMateria, dat);
                        }while(strlen(materias[i].NomMateria) > 51);
                        break;
					case 3:
					    do{
                            printf("Introduce la nueva abreviatura: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(alun[i].abrMaterias, abrMateria);
					    }while(strlen(materias[i].abrMateria) > 4);
					break;
				}
				printf("�Desea hacer otra modificacion? y/n\n");
				c = getc(stdin);
				fflush(stdin);
			}while(c != 'n');
}
