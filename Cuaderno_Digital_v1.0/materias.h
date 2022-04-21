#ifndef MATERIAS
#define MATERIAS

typedef struct{
char idMateria[5];
char nomMateria[51];
char abrMateria[4];
} Materia;
Materia *materias;

void CargarMaterias();
void EscribirMaterias();

void ListarMaterias();
void CrearMateria();
void EliminarMaterias();
int CuentaMaterias();
#endif
