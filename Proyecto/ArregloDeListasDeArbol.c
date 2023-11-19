#include <stdlib.h>
#include <stdio.h>
#include "ArregloDeListasDeArbol.h"

nodoMateria* altaMaterias(nodoMateria* lista,arbolNotas* nuevo,stMateria dato)
{
    nodoMateria* pos = buscarPosMateria(lista,dato.idMateria);

    if(pos == NULL)
    {
        nodoMateria* nuevaMateria = crearNodoMateria(dato);
        lista = agregarPpioMateria(lista,nuevaMateria);
        pos = lista;
    }
    pos->arbolNota = insertarNotas(pos->arbolNota,nuevo->alumno,nuevo->nota);

    return lista;
}

nodoMateria* buscarPosMateria(nodoMateria* lista,int idMateria)
{
    nodoMateria* seg = lista;
    nodoMateria* rta = inicListaMateria();

    while(seg && rta == NULL)
    {
        if(seg->dato.idMateria == idMateria)
            rta = seg;
        seg = seg->siguiente;
    }
    return rta;
}



void mostrarComisiones (Celda comisiones[],int validos)
{
    for(int i=0 ; i<validos ; i++)
    {
        printf("\nComision %d\n",comisiones[i].comision);
    }
}



int altaArreglo (Celda A[],stMateria m,int comision,stNota n,stAlumno a,int validos)
{

    int pos = buscarPosComision(A,comision,validos);

    if(pos == -1)
    {
        validos = agregarComision(A,comision,validos);
        pos = validos - 1;
    }
    arbolNotas* arbolito = crearArbolNotas(n,a);
    A[pos].listaMateria = altaMaterias(A[pos].listaMateria,arbolito,m);

    return validos;
}

int agregarComision(Celda A[],int comision,int validos)
{
    A[validos].comision = comision;
    A[validos].listaMateria = inicListaMateria();
    validos++;
    return validos;
}


int buscarPosComision (Celda A[],int comision,int validos)
{
    int rta = -1;
    int i = 0;
    while(i<validos  &&  rta == -1)
    {
        if(comision == A[i].comision)
            rta = i;

        i++;
    }

    return rta;
}

arbolNotas* buscar (Celda comisiones [],int validos ,int comision,int idMateria)
{
    nodoMateria* subLista;
    arbolNotas* rta = inicArbolNotas();
    for (int i=0;i<validos;i++)
    {
        if(comisiones[i].comision == comision)
        {
            subLista = buscarPosMateria(comisiones[i].listaMateria,idMateria);
            rta = subLista->arbolNota;
        }
    }

    return rta;
}

void mostrarNotaXlegajo (arbolNotas* arbol, int legajo)
{
    if(arbol != NULL)
    {
        if(arbol->alumno.legajo == legajo)
            printf("Examen: %d  Nota: %d\n",arbol->nota.numExamen,arbol->nota.nota);
        mostrarNotaXlegajo(arbol->izq, legajo);
        mostrarNotaXlegajo(arbol->der, legajo);
    }
}

