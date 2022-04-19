#ifndef CALIFICACIONES
#define CALIFICACIONES

typedef struct{
    char fecha[11];
    char descripcion[31];
    char idMateria[5];
    char idAlumno[7];
    char nota[3];
}Calificacion;

#endif