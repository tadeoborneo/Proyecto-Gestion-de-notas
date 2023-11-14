#include <stdio.h>
#include <stdlib.h>
#include "arbolNotas.h"

arbolNotas* inicArbolNotas()
{
    return NULL;
}
stNota cargarNota()
{
    stNota A;

    printf("Ingrese numero de examen: ");
    scanf("%d",A.numExamen);
    printf("Ingrese la nota: ");
    scanf("%d",A.nota);

    return A;
}

void mostrarNota(stNota A)
{
    printf("\nExamen N° %d  Nota: %d\n ",A.numExamen,A.nota);
}

stAlumno cargarAlumno()
{
    stAlumno A;
    printf("Ingrese nombre y apellido del alumno: ");
    fflush(stdin);
    gets(A.nombreAlumno);
    printf("Ingrese el legajo: ");
    scanf("%d",&A.legajo);
    return A;
}

void mostrarAlumno(stAlumno A)
{
    printf("Nombre: %s\n",A.nombreAlumno);
    printf("Legajo: %d\n",A.legajo);
}

void mostrarNodoNotas(arbolNotas* A)
{
    printf("\n---------------------------------------------------------\n");
    mostrarAlumno(A->alumno);
    mostrarNota(A->nota);
    printf("\n---------------------------------------------------------\n");
}

arbolNotas* crearArbolNotas(stNota datoNota, stAlumno datoAlumno)
{
    arbolNotas* aux = (arbolNotas*) malloc(sizeof(arbolNotas));

    aux->alumno = datoAlumno;
    aux->nota = datoNota;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

arbolNotas* insertarNotas(arbolNotas* arbol, stAlumno datoAlumno,stNota datoNota)
{
    if(arbol == NULL)
    {
        arbol = crearArbolNotas(datoNota,datoAlumno);
    }else
    {
        if(datoNota.nota > arbol->nota.nota)
            arbol->der = insertarNotas(arbol->der,datoAlumno,datoNota);
        else
            arbol->izq = insertarNotas(arbol->izq,datoAlumno,datoNota);
    }
    return arbol;
}

arbolNotas* buscarNota(arbolNotas* arbol,stNota nota,int legajo)
{
    arbolNotas* rta = NULL;
    if(arbol != NULL)
    {
        if(nota.numExamen == arbol->nota.numExamen  &&  legajo == arbol->alumno.legajo)
            rta = arbol;
        else
        {
            if(nota.nota > arbol->nota.nota)
                rta =  buscarNota(arbol->der,nota,legajo);
            else
                rta = buscarNota(arbol->izq,nota,legajo);
        }
    }

    return rta;
}

void preorderNotas(arbolNotas* arbol)
{
    if(arbol != NULL)
    {
        mostrarNodoNotas(arbol);
        preorderNotas(arbol->izq);
        preorderNotas(arbol->der);
    }
}

void inorderNotas(arbolNotas* arbol)
{
    if(arbol != NULL)
    {
        inorderNotas(arbol->izq);
        mostrarNodoNotas(arbol);
        inorderNotas(arbol->der);

    }

}

void postorderNotas(arbolNotas* arbol)
{
    if(arbol != NULL)
    {
        postorderNotas(arbol->izq);
        postorderNotas(arbol->der);
        mostrarNodoNotas(arbol);
    }
}


arbolNotas* borrarNota(arbolNotas* arbol,stNota datoNota,int legajo)
{
    if(arbol != NULL)
    {
        if(arbol->nota.numExamen == datoNota.numExamen  &&  legajo == arbol->alumno.legajo)
        {
            if(arbol->izq != NULL)
            {
                arbolNotas* masDer = NMD(arbol->izq);
                arbol->alumno = masDer->alumno;
                arbol->nota = masDer->nota;
                arbol->izq = borrarNota(arbol->izq,masDer->nota,masDer->alumno.legajo);
            }else if(arbol->der != NULL)
            {
                arbolNotas* masIzq = NMI(arbol->der);
                arbol->nota = masIzq->nota;
                arbol->alumno = masIzq->alumno;
                arbol->der = borrarNota(arbol->der,masIzq->nota,masIzq->alumno.legajo);
            }else
            {
                free(arbol);
                arbol = NULL;
            }
        }else
        {
            if(datoNota.nota > arbol->nota.nota)
                arbol->der = borrarNota(arbol->der,datoNota,legajo);
            else
                arbol->izq = borrarNota(arbol->izq,datoNota,legajo);
        }
    }

    return arbol;
}

arbolNotas* NMD (arbolNotas* arbol)
{
    if( arbol !=NULL)
    {
        while(arbol->der != NULL)
        {
            arbol = arbol->der;
        }
    }

    return arbol;
}

arbolNotas* NMI (arbolNotas* arbol)
{
    if(arbol != NULL)
    {
        while(arbol->izq != NULL)
        {
            arbol = arbol->izq;
        }
    }

    return arbol;
}



int existeNota(arbolNotas* arbol ,int legajo,stNota datoNota)
{
    int rta = 0;
    if(arbol != NULL)
    {
        if(legajo == arbol->alumno.legajo  &&  datoNota.numExamen == arbol->nota.numExamen)
            rta = 1;
        else{
            if(datoNota.nota > arbol->nota.nota)
                rta = existeNota(arbol->der,legajo,datoNota);
            else
                rta = existeNota(arbol->izq,legajo,datoNota);
        }
    }
    return rta;
}
