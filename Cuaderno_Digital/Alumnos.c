#include "alumnos.h"
#include "funciones_clave.c"

//Cabecera: void carga_alumnos();
//Precondicion:
//Postcondicion: El programa carga todos los datos almacenados en el txt correspondientes a los alumnos en una estructura;
void carga_alumnos(){

char p[100], *token;
const char s[2] = "-";
int i, j, cont, semaforo;
FILE *f;
setlocale(LC_CTYPE, "Spanish");

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
	j = 1;
	while(token != NULL){
		switch(j){
        	case 1: strcpy(alun[i].id_alum, token);
        	break;
            case 2: strcpy(alun[i].nombre_alum, token);
            break;
            case 3: strcpy(alun[i].direc_alum, token);
            break;
            case 4: strcpy(alun[i].local_alum, token);
            break;
            case 5: strcpy(alun[i].curso, token);
            break;
            case 6: strcpy(alun[i].grupo, token);
            break;
        }
		token = strtok(NULL, s);
		j++;
	}
}
fclose(f);
}

//Cabecera: void addalum();
//Precondicion:
//Postcondicion: Se añade un alumno nuevo a la estructura;
void addalum(){
    int i;
	char c;
	do{
    l++;
	alun = (Alumnos*)realloc(alun, l);
	i = l-1;

	if(alun == NULL){
		printf("ERROR");
	}
	do{
		printf("Introduce el id del nuevo alumno.\n");
		gets(alun[i].id_alum);
		fflush(stdin);
	}while(strlen(alun[i].id_alum) > 7);
	do{
		printf("Introduce el nombre del nuevo alumno.\n");
		gets(alun[i].nombre_alum);
		fflush(stdin);
	}while(strlen(alun[i].nombre_alum) > 21);
	do{
		printf("Introduce la direccion del nuevo alumno.\n");
		gets(alun[i].direc_alum);
		fflush(stdin);
	}while(strlen(alun[i].direc_alum) > 31);
	do{
		printf("Introduce la localidad del nuevo alumno.\n");
		gets(alun[i].local_alum);
		fflush(stdin);
	}while(strlen(alun[i].local_alum) > 31);
	do{
		printf("Introduce el curso del nuevo alumno.\n");
		gets(alun[i].curso);
		fflush(stdin);
	}while(strlen(alun[i].curso) > 31);
	do{
		printf("Introduce el grupo del nuevo alumno.\n");
		gets(alun[i].grupo);
		fflush(stdin);
	}while(strlen(alun[i].grupo) > 11);
	printf("¿Quieres introducir otro alumno? s/n \n");
	c = getc(stdin);
	}while(c == 's');
}

//Cabecera: void listalum();
//Precondicion:
//Postcondicion: El modulo muestra el nombre de cada alumno y deja seleccionar uno para mostrar todos los datos correspondientes a ese alumno;
void listalum(){
	int i, n;
	n = 0;

	for(i = 0; i < l; i++){
        printf("(%i)%s\n",i+1,alun[i].nombre_alum);
	}

	printf("Selecciona un nombre: \n");
	scanf("%i", &n);
	fflush(stdin);
    n--;
    printf("%s\n", alun[n].id_alum);
    printf("%s\n", alun[n].nombre_alum);
    printf("%s\n", alun[n].direc_alum);
    printf("%s\n", alun[n].local_alum);
    printf("%s\n", alun[n].curso);
    printf("%s\n", alun[n].grupo);
}

//Cabecera: void delalum();
//Precondicion:
//Postcondicion: Elimina un alumno a eleccion del usuario.
void delalum(){
	int i, j;
	char nom[20];
	for(i = 0; i < l; i++){
        printf("(%i)%s\n",i+1,alun[i].nombre_alum);
	}
	printf("¿Que alumno desea eliminar?\n");
	scanf("%i", &j);
	j--;

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

//Cabecera: void modalum();
//Precondicion:
//Postcondicion: modifica un dato de un alumno a eleccion del usuario.
void modalum(){
	int i, j;
	char c, dat[31];
	for(i = 0; i < l; i++){
        printf("(%i)%s\n",i+1,alun[i].nombre_alum);
	}
	printf("¿Que alumno desea modificar?\n");
	scanf("%i", &i);
	fflush(stdin);
	i--;
			do{
				printf("¿Que dato desea modificar?\n");
				printf("(1)Nombre\n");
				printf("(2)Direccion\n");
				printf("(3)Localidad\n");
				printf("(4)Curso\n");
				printf("(5)Grupo\n");
				scanf("%i", &j);
				fflush(stdin);
				switch(j){
					case 1:
                        do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(alun[i].nombre_alum, dat);
                        }while(strlen(alun[i].nombre_alum) > 21);
					break;
					case 2:
					    do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(alun[i].direc_alum, dat);
                        }while(strlen(alun[i].direc_alum) > 31);
					break;
					case 3:
					    do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(alun[i].local_alum, dat);
					    }while(strlen(alun[i].local_alum) > 31);
					break;
					case 4:
					    do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(alun[i].curso, dat);
					    }while(strlen(alun[i].curso) > 31);
					break;
					case 5:
					    do{
                            printf("Introduce el nuevo dato: \n");
                            gets(dat);
                            fflush(stdin);
                            strcpy(alun[i].grupo, dat);
					    }while(strlen(alun[i].grupo) > 11);
					break;
					default: printf("Numero incorrecto.\n");
					break;
				}
				printf("¿Desea hacer otra modificacion? y/n\n");
				c = getc(stdin);
				fflush(stdin);
			}while(c != 'n');
}

//Cabecera: void endalum();
//Precondicion:
//Postcondicion: Vacia el txt y vuelca los datos de la estructura.
void endalum(){
	FILE *f;
	int i;
	f = fopen("alumnos.txt", "w");
	if(f == NULL){
		printf("ERROR\n");
	}
	fflush(f);

	for(i = 0; i < l; i++){
		fprintf(f, "%s-", alun[i].id_alum);
		fprintf(f, "%s-", alun[i].nombre_alum);
		fprintf(f, "%s-", alun[i].direc_alum);
		fprintf(f, "%s-", alun[i].local_alum);
		fprintf(f, "%s-", alun[i].curso);
		fprintf(f, "%s", alun[i].grupo);
	}
	fclose(f);
}


