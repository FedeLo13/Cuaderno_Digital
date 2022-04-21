#ifndef CALIFICACIONES
#define CALIFICACIONES

typedef struct{
    char fecha[11];
    char descripcion[31];
    char idMateria[5];
    char idAlumno[7];
    char nota[3];
}Calificacion;

Calificacion *calificaciones;

void CargarCalificaciones();
void ListarCalificaciones();
void EscribirCalificaciones();
void CrearCalificacion();
void EliminarCalificacion();
int CuentaCalificaciones();
#endif
