#ifndef ARREGLODELISTASDEARBOL_H_INCLUDED
#define ARREGLODELISTASDEARBOL_H_INCLUDED
#include "listaMaterias.h"

typedef struct {
    int comision;
    nodoMateria* listaMateria;
}Celda;

int ingresarComision (Celda A[],int dimension)
int altaArreglo (Celda A[],stMateria m,int comision,stNota n,stAlumno a,int validos);
int agregarComision(Celda A[],int comision,int validos);
int buscarPosComision (celda A[],int comision,int validos);
nodoMateria* altaMaterias(nodoMateria* lista,arbolNotas* nuevo,stMateria dato);
nodoMateria* buscarPosMateria(nodoMateria* lista,int idMateria);

#endif // ARREGLODELISTASDEARBOL_H_INCLUDED
