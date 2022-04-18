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
void carga_matriculas();
int i, j, cont;

typedef struct{
  char id_alum[6];
  char id_materia[4];

}Matriculas;

Matriculas *matr;
int l;

int main(){
  carga_matriculas();
  printf("%s\n", matr[0].id_alum);
  printf("%s\n", matr[0].id_materia);
  return 0;
}
void carga_matriculas(){
char p[100], *token;
const char s[2] = "-";
   FILE*f;
   f = fopen("materia.txt","r");

 if(f == NULL){
    printf("no se ha podido abrir el fichero. \n");
    exit(1);
   }

while(!feof(f)){
    fgets(p, 100, f);
    cont++;
}

l = cont;

matr = (Matriculas*)malloc(l*sizeof(Matriculas));


if(matr == NULL) {
    printf("Error al reservar memoria.");
}

rewind(f);

for(i == 0; i < l; i++){
	vaciar(p, 100);
	fgets(p, 100, f);
	token = strtok(p, s);
	j = 0;

while(token != NULL){
		switch(j){
        	case 0: strcpy(matr[i].id_alum, token);
        	break;
            case 1: strcpy(matr[i].id_materia, token);
            break;
    }
		token = strtok(NULL, s);
		j++;
  }
}
fclose(f);

void list(){
	int i;
	char id[6];

	for(i = 0; i < l; i++){
        printf("%s - ", matr[i].id_alum);
        printf("%s\n", matr[i].id_materia);
	}

	printf("Selecciona un id: \n");
	fgets(id, 6, stdin);

	for(i = 0; i <= l; i++){
		if(strcoll(id, matr[i].id_alum) == 0){
			printf("%s\n", matr[i].id_alum);
			printf("%s\n", matr[i].id_materia);
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
	    fprintf(f, "$s-", matr[i].id_alum);
        fprintf(f, "$s-", matr[i].id_materia);

 }
	fclose(f);
}
