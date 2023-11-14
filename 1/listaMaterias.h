#ifndef LISTAMATERIAS_H_INCLUDED
#define LISTAMATERIAS_H_INCLUDED
#include "arbolNotas.h"

typedef struct{
    int idMateria;
    char nombreMateria[30];
}stMateria;

typedef struct nodoMateria{
    stMateria dato;
    arbolNotas* arbolNota;
    struct nodoMateria* siguiente;
}nodoMateria;

stMateria cargarMateria();
void mostrarMateria (stMateria A);
nodoMateria* inicListaMateria();
nodoMateria* crearNodoMateria(stMateria dato);
nodoMateria* agregarPpioMateria(nodoMateria* lista,nodoMateria* nuevoNodo);
void mostrarNodoMateria (nodoMateria* A);
void mostrarListaMateria (nodoMateria* lista);
nodoMateria* buscarUltimoListaMaterias(nodoMateria* lista);
nodoMateria* agregarFinalMateria(nodoMateria* lista, nodoMateria *nuevoNodo);
nodoMateria* agregarOrdenadoXidMateria (nodoMateria* lista,nodoMateria* nuevoNodo);
int buscarEnListaMaterias (nodoMateria* lista,stMateria buscado);
nodoMateria* borrarNodoMateria (nodoMateria* lista, stMateria dato);
nodoMateria* borrarTodaLaListaMaterias (nodoMateria* lista);
nodoMateria* borrarPrimerNodo (nodoMateria* lista);
stMateria retornarPrimerDato (nodoMateria* lista);



#endif // LISTAMATERIAS_H_INCLUDED
