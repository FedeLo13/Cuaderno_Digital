#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void list();
void vaciar(char *s, int n){
    int i;
    for(i=0;i<n;i++){
        s[i]= '\0';
    }
}
void carga_alumnos();
void modalum();
void addalum();
void delalum();

typedef struct{
    char id_alum[6];
    char nombre_alum[20];
    char direc_alum[30];
    char local_alum[30];
    char curso[30];
    char grupo[10];
}Alumnos;

Alumnos *alun;
int l;

int main(){
	setlocale(LC_CTYPE, "Spanish");
    carga_alumnos();
    printf("%s\n", alun[0].id_alum);
	printf("%s\n", alun[0].nombre_alum);
	printf("%s\n", alun[0].direc_alum);
	printf("%s\n", alun[0].local_alum);
	printf("%s\n", alun[0].curso);
	printf("%s\n", alun[0].grupo);
    return 0;
}

void carga_alumnos(){

char p[100], *token;
const char s[2] = "-";
int i, j, cont;
FILE *f; 

f = fopen("alumnos.txt", "r");

if(f == NULL){
    printf("No se ha podido abrir el fichero.");
}
               
cont = 0;

while(!feof(f)){
    fgets(p, 100, f);
    cont++;
}

l = cont;

alun = (Alumnos*)malloc(l*sizeof(Alumnos));

if(alun == NULL){
    printf("Error al reservar memoria.");
}

rewind(f);

for(i = 0; i < l; i++){
	vaciar(p, 100);
	fgets(p, 100, f);
	token = strtok(p, s);
	j = 0;
	while(token != NULL){
		switch(j){
        	case 0: strcpy(alun[i].id_alum, token);
        	break;
            case 1: strcpy(alun[i].nombre_alum, token);
            break;
            case 2: strcpy(alun[i].direc_alum, token);
            break;
            case 3: strcpy(alun[i].local_alum, token);
            break;
            case 4: strcpy(alun[i].curso, token);
            break;
            case 5: strcpy(alun[i].grupo, token);
            break;
        }
		token = strtok(NULL, s);
		j++;
	}
}
fclose(f);
}

void addalum(){
	int i;
	char c;
	i = 0;
	do{
	alun = (Alumnos*)realloc(alun, l+1);
	l = l+1;
	printf("Introduce el id del nuevo alumno.\n");
	scanf("%i", alun[l].id_alum);
	printf("Introduce el nombre del nuevo alumno.\n");
	fgets(alun[l].nombre_alum, 20, stdin);
	printf("Introduce la direccion del nuevo alumno.\n");
	fgets(alun[l].direc_alum, 30, stdin);
	printf("Introduce la localidad del nuevo alumno.\n");
	fgets(alun[l].local_alum, 30, stdin);
	printf("Introduce el curso del nuevo alumno.\n");
	fgets(alun[l].curso, 30, stdin);
	printf("Introduce el grupo del nuevo alumno.\n");
	fgets(alun[l].grupo, 10, stdin);
	printf("¿Quieres introducir otro alumno? s/n \n");
	scanf("%c", c);
	if(c == 'n'){
		i = 1;
	}
	}while(i == 0);
}

void list(){
	int i; 
	char id[6];
	
	for(i = 0; i < l; i++){
        printf("%s - ", alun[i].id_alum);
        printf("%s\n", alun[i].nombre_alum);
	}
	
	printf("Selecciona un id: \n");
	fgets(id, 6, stdin);
	
	for(i = 0; i <= l; i++){
		if(strcoll(id, alun[i].id_alum) == 0){
			printf("%s\n", alun[i].id_alum);
			printf("%s\n", alun[i].nombre_alum);
			printf("%s\n", alun[i].direc_alum);
			printf("%s\n", alun[i].local_alum);
			printf("%s\n", alun[i].curso);
			printf("%s\n", alun[i].grupo);
			i = l+1;
		}
	}
}

void delalum(){
	int i, j;
	char nom[20];
	printf("¿Que alumno desea eliminar?\n");
	fgets(nom, 20, stdin);
	for(i = 0; i < l; i++){
		if(strcmp(nom, alun[i].nombre_alum)){
			j = i;
			i = l+1;
		}
	}
	for(j; j < l; j++){
	strcpy(alun[j].id_alum, alun[j+1].id_alum);
	strcpy(alun[j].nombre_alum, alun[j+1].nombre_alum);
	strcpy(alun[j].direc_alum, alun[j+1].direc_alum);
	strcpy(alun[j].local_alum, alun[j+1].local_alum);
	strcpy(alun[j].curso, alun[j+1].curso);
	strcpy(alun[j].grupo, alun[j+1].grupo);
	}
	l = l-1;
	alun = (Alumnos*)realloc(alun, l);
}

void modalum(){
	int i, j;
	char c, nom[20], dat[30];
	printf("¿Que alumno desea modificar?\n");
	fgets(nom, 20, stdin);
	for(i = 0; i < l; i++){
		if(strcmp(nom, alun[i].nombre_alum)){
			do{
				printf("¿Que dato desea modificar?\n");
				printf("(1)Nombre\n");
				printf("(2)Direccion\n");
				printf("(3)Localidad\n");
				printf("(4)Curso\n");
				printf("(5)Grupo\n");
				scanf("%i", j);
				switch(j){
					case 1: printf("Introduce el nuevo dato: \n");
						fgets(dat, 20, stdin);
						strcpy(alun[i].nombre_alum, dat);	
					break;
					case 2: printf("Introduce el nuevo dato: \n");
						fgets(dat, 30, stdin);
						strcpy(alun[i].direc_alum, dat);	
					break;
					case 3: printf("Introduce el nuevo dato: \n");
						fgets(dat, 30, stdin);
						strcpy(alun[i].local_alum, dat);	
					break;
					case 4: printf("Introduce el nuevo dato: \n");
						fgets(dat, 30, stdin);
						strcpy(alun[i].curso, dat);	
					break;
					case 5: printf("Introduce el nuevo dato: \n");
						fgets(dat, 10, stdin);
						strcpy(alun[i].grupo, dat);	
					break;
					default: printf("Numero incorrecto.\n");
					break;
				}
				printf("¿Desea hacer otra modificacion? y/n\n");
				scanf("%c", c);
			}while(c != 'n');
			i = l+1;
		}
	}
	
}

void end(){
	FILE *f;
	int i;
	f = fopen("alumnos.txt", "w");
	if(f == NULL){
		printf("ERROR\n");
	}
	
	for(i = 0; i<l; i++){
		fprintf(f, "$s-", alun[i].id_alum);
		fprintf(f, "$s-", alun[i].nombre_alum);
		fprintf(f, "$s-", alun[i].direc_alum);
		fprintf(f, "$s-", alun[i].local_alum);
		fprintf(f, "$s-", alun[i].curso);
		fprintf(f, "$s", alun[i].grupo);
		fprintf(f, "\n");
	}
	fclose(f);
}


