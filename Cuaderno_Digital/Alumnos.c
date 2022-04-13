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
void addalum();

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

char p[126], *token;
int i, j, cont;
FILE *f; 

f = fopen("alumnos.txt", "r");

if(f == NULL){
    printf("No se ha podido abrir el fichero.");
}
               
cont = 0;

while(!feof(f)){
    fgets(p, 126, f);
    cont++;
}

l = cont;

alun = (Alumnos*)malloc(l*sizeof(Alumnos));

if(alun == NULL){
    printf("Error al reservar memoria.");
}

rewind(f);

i = 0;

while(i < l){
	vaciar(p, 126);
	fgets(p, 126, f);
	token = strtok(p, "-");
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
            default: printf("Algo va mal");
            break;
        }
		token = strtok(NULL, "-");
		j++;
	}
	i++;
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
        printf("%s", alun[i].id_alum);
        //printf("%s\n", alun[i].nombre_alum);
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
