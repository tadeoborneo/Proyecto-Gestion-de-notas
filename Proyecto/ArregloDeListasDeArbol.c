#include <stdlib.h>
#include <stdio.h>
#include "ArregloDeListasDeArbol.h"

nodoMateria* altaMaterias(nodoMateria* lista,arbolNotas* nuevo,stMateria dato)
{
    nodoMateria* pos = buscarPosMateria(lista,dato.idMateria);

    if(pos == NULL)
    {
        nodoMateria* nuevo = crearNodoMateria(dato);
        lista = agregarPpioMateria(lista,nuevo);
        pos = lista;
    }
    pos->arbolNota = insertarNotas(pos->arbolNota,nuevo.alumno,nuevo.nota);

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









int ingresarComision (Celda A[],int dimension)
{

    int comision;
    stMateria dato;
    char salir = 's';
    int validos = 0;

    while(salir == 's'  &&  validos < dimension)
    {

        printf("Ingrese la comision: ");
        scanf("%d",&comision);

        dato = cargarMateria();

        validos = alta(A,dato,comision,validos);

        printf("Si desea continuar presione S: ");
        fflush(stdin);
        scanf("%c",&salir);
    }
    return validos;
}

int altaArreglo (Celda A[],stMateria dato,int comision,int validos)
{
    nodoMateria* aux = crearNodoMateria(dato);

    int pos = buscaPosComision(A,comision,validos);

    if(pos == -1)
    {
        validos = agregarComision(A,comision,validos);
        pos = validos - 1;
    }
    A[pos].listaDeNotas = agregarPpio(A[pos].listaDeNotas,aux);
    return validos;
}

int agregarComision(Celda A[],int comision,int validos)
{
    A[validos].comision = comision;
    A[validos].listaMateria = inicListaMateria();
    validos++;
    return validos;
}


int buscarPosComision (celda A[],int comision,int validos)
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
