#include <stdio.h>
#include <stdlib.h>
#include "listaMaterias.h"

stMateria cargarMateria()
{
    stMateria A;

    printf("Ingrese ID de la materia: ");
    scanf("%d",&A.idMateria);
    printf("Ingrese el nombre de la materia: ");
    fflush(stdin);
    gets(A.nombreMateria);

    return A;
}

void mostrarMateria (stMateria A)
{
    printf("\nMATERIA:     ID: %d     NOMBRE: %s\n",A.idMateria,A.nombreMateria);
}

nodoMateria* inicListaMateria()
{
    return NULL;
}

nodoMateria* crearNodoMateria(stMateria dato)
{
    nodoMateria* A=(nodoMateria*) malloc(sizeof(nodoMateria));
    A->dato = dato;
    A->arbolNota = inicArbolNotas();
    A->siguiente = NULL;

    return A;
}

nodoMateria* agregarPpioMateria(nodoMateria* lista,nodoMateria* nuevoNodo)
{
    if(lista==NULL)
    {
       lista = nuevoNodo;
    }else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }

    return lista;
}

void mostrarNodoMateria (nodoMateria* A)
{
    mostrarMateria(A->dato);
}

void mostrarListaMateria (nodoMateria* lista)
{
    nodoMateria* seg = lista;

    if(lista==NULL)
    {
        printf("LISTA VACIA\n");
    }else
    {
        while(seg!=NULL)
        {
            mostrarNodoMateria(seg);
            seg = seg->siguiente;
        }
    }
}

nodoMateria* buscarUltimoListaMaterias(nodoMateria* lista)
{
    nodoMateria* seg = lista;

    if(seg!=NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}


nodoMateria* agregarFinalMateria(nodoMateria* lista, nodoMateria *nuevoNodo)
{
    if(lista==NULL)
    {
        lista = nuevoNodo;
    }else
    {
        nodoMateria* ultimo = buscarUltimoListaMaterias(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}

nodoMateria* agregarOrdenadoXidMateria (nodoMateria* lista,nodoMateria* nuevoNodo)
{

    if(lista==NULL)
    {
        lista = nuevoNodo;
    }else
    {
        if(nuevoNodo->dato.idMateria < lista->dato.idMateria)
        {
            lista = agregarPpioMateria(lista,nuevoNodo);
        }else
        {
            nodoMateria* anterior = lista;
            nodoMateria* seg = lista->siguiente;

             while(seg != NULL  &&  seg->dato.idMateria < nuevoNodo->dato.idMateria)
            {
                anterior = seg;
                seg = seg->siguiente;
            }

            anterior->siguiente=nuevoNodo;
            nuevoNodo->siguiente=seg;
        }
    }
    return lista;
}

int buscarEnListaMaterias (nodoMateria* lista,stMateria buscado)
{
    int flag = 0;

    if(lista==NULL)
    {
        flag = 0;
    }else
    {
        nodoMateria* seg = lista;
        while(seg != NULL && flag == 0)
        {

            if(seg->dato.idMateria == buscado.idMateria)
            {
                flag = 1;
            }
            seg = seg->siguiente;

        }
    }

    return flag;
}

nodoMateria* borrarNodoMateria (nodoMateria* lista, stMateria dato)
{
    nodoMateria* ant;
    nodoMateria* seg;

    if(lista != NULL  &&  dato.idMateria == lista->dato.idMateria )
    {
        nodoMateria* aux = lista;
        lista = lista->siguiente;
        free(aux);
    }else
    {
        seg = lista;

        while(seg != NULL  &&  dato.idMateria != seg->dato.idMateria)
        {
            ant = seg;
            seg = seg->siguiente;
        }

        if(seg != NULL)
        {
            ant->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

nodoMateria* borrarTodaLaListaMaterias (nodoMateria* lista)
{
    nodoMateria* proximo;
    nodoMateria* seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}



nodoMateria* borrarPrimerNodo (nodoMateria* lista)
{
    nodoMateria* aux;

    if(lista!= NULL)
    {
        aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    return lista;
}

stMateria retornarPrimerDato (nodoMateria* lista)
{
    stMateria dato;
    dato = lista->dato;

    return dato;
}

