#include "funciones_clave.h"

void vaciar(char *s, int n){
    int i;
    for(i=0;i<n;i++){
        s[i]= '\0';
    }
}
void termina_cadenas(char *s){
    int i,semaforo=0;
    while(semaforo==0){
        i++;
        if(s[i]== '\n'){
            s[i]= '\0';
            semaforo=1;
        }
    }
}

