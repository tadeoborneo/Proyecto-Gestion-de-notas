#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArregloDeListasDeArbol.h"
const char nombreArch [35]="alumnado";

typedef struct
{
    int comision;
    char nombreMateria[30];
    int idMateria;
    char nombreAlumno[30];
    int legajoAlumno;
    int nota;
    int nroExamen;
}stRegistro ;

///PROTOTIPADO

void cargaArchivo ();
stRegistro cargaRegistro();
stMateria llenarMateria (char nombre[], int id);
stAlumno llenarAlumno(char nombre[], int legajo);
stNota llenarNota (int nota, int examen);
int  copiarRegistro (Celda comisiones[], int dimension);
void actualizarArchivo (Celda comisiones[],int validos);
void guardarRegistro (FILE* buff,arbolNotas* arbol,stRegistro rg);




/// MAIN
int main()
{
    FILE* fp = fopen(nombreArch,"rb");
    Celda comisiones[3];
    int validos=0;

    int comision;
    int idMateria;
    int legajo;
    int posCom;
    nodoMateria* subLista;

    if(fp)
            validos = copiarRegistro(comisiones,3);
            int b=0;
            int c=1;

            printf("Ingresar como Profesor o como alumno?\n");
            printf("1-Profesor\n");
            printf("2-Alumno\n");
            scanf("%i",&b);
            system("cls");
            while (c==1)
            {
            switch (b)
            {
            case 1:///INGRESO COMO DOCENTE
                {
                    int i=0;
                    int d=0;
                    printf("Ha ingresado como profesor\n");
                    for(i ; i<3 ; i++)
                    {
                        printf("Ingrese la contraseña para entrar al sistema\n");
                        scanf("%i",&d);
                        if(d==1234)
                        {
                            i = 4;
                            if(fp!=NULL)
                            {
                            int e=0;
                            system("cls");
                            printf("Bienvenido\n");
                            printf("Que desea hacer?\n");
                            printf("1-Ver informacion sobre comisiones y notas de alumnos\n");
                            printf("2-Modificar notas de alumnos\n");
                            printf("3-Elimnar alumno de base de datos\n");
                            printf("4-Cargar archivo\n");
                            scanf("%i",&e);
                            system("cls");
                            switch(e)
                            {
                            case 1:
                                {


                                    printf("\nSeleccione una comision: ");
                                    mostrarComisiones(comisiones,validos);
                                    scanf("%d",&comision);
                                    comision = buscarPosComision(comisiones,comision,validos);
                                    mostrarListaMateria(comisiones[comision].listaMateria);
                                    printf("\nIngrese el ID de la materia para ver sus notas: ");
                                    scanf("%d",&idMateria);
                                    subLista = buscarPosMateria(comisiones[comision].listaMateria,idMateria);
                                    inorderNotas(subLista->arbolNota);
                                    break;
                                }
                            case 2:
                                {
                                    int numeroExamen;
                                    int nuevaNota;
                                    printf("SELECCIONE COMISION\n");
                                    mostrarComisiones(comisiones,validos);
                                    scanf("%d",&comision);
                                    posCom = buscarPosComision(comisiones,comision,validos);
                                    system("cls");
                                    printf("SELECCIONE MATERIA POR ID\n");
                                    mostrarListaMateria(comisiones[posCom].listaMateria);
                                    scanf("%d",&idMateria);
                                    subLista = buscarPosMateria(comisiones[posCom].listaMateria,idMateria);
                                    printf("Ingrese el legajo del alumno para modificar una nota: ");
                                    scanf("%d",&legajo);
                                    printf("Ingrese el numero del examen que quiere modificar: ");
                                    scanf("%d",&numeroExamen);
                                    printf("Ingrese la nueva nota: ");
                                    scanf("%d",&nuevaNota);
                                    subLista->arbolNota = modificarNota(subLista->arbolNota,numeroExamen,legajo,nuevaNota);

                                    break;
                                }
                            case 3:
                                {
                                    ///elimina a un alumno de la base de datos
                                    break;
                                }
                            case 4:
                                {

                                    cargaArchivo();
                                    validos = copiarRegistro(comisiones,3);
                                }
                            }
                            }else
                            {
                                system("cls");
                                int control=0;
                                printf("No hay datos en el archivo\n");
                                printf("Quiere ingresar informacion del alumnado?\n");
                                printf("1-Si\n");
                                printf("2-No\n");
                                scanf("%i",&control);

                                if(control==1)
                                {
                                    system("cls");
                                    cargaArchivo();
                                }else
                                {
                                    printf("Gracias por su visita\n");
                                }
                            }


                        }else
                        {
                                printf("Contraseña erronea intente nuevamente \n");
                        }
                    }
                    if(i==3)
                    {
                        printf("Cantidad de intentos excedido\n");
                    }
                    break;
                }

            case 2:///INGRESO COMO ALUMNO
                {
                    int f=1;
                    arbolNotas* nuevo;
                if(fp)
                {
                    while (f==1)
                    {
                    printf("Ingrese la comision a la que pertenece \n");
                    scanf("%i",&comision);
                    printf("Ingrese su numero de legajo \n");
                    scanf("%i",&legajo);
                    posCom = buscarPosComision(comisiones,comision,validos);
                    mostrarListaMateria(comisiones[posCom].listaMateria);
                    printf("\nIngrese el id de la materia para ver sus notas \n");
                    scanf("%i",&idMateria);
                    system("cls");
                    nuevo = buscar(comisiones,validos,comision,idMateria);
                    mostrarNotaXlegajo(nuevo,legajo);
                    system("pause");
                    system("cls");
                    printf("Desea seguir buscando sus notas? \n");
                    printf("1-Seguir buscando\n");
                    printf("2-Salir\n");
                    scanf("%i",&f);
                    system("cls");
                    }
                }else
                {
                    printf("Todavia no se ha cargado informacion al sistema\n");
                    printf("Vuelva a intentar mas tarde\n");
                }

                break;
                }
            }

                system("pause");
                system("cls");
                printf("Desea seguir en el programa o finalizar las consultas?\n");
                printf("1-Seguir en el programa\n");
                printf("2-Salir del programa\n");
                scanf("%i",&c);
                system("cls");
            }
    fclose(fp);
    //actualizarArchivo(comisiones,validos);
    return 0;
}




///FUNCIONES

void cargaArchivo ()
{
    FILE*fp=fopen(nombreArch,"ab");
    stRegistro nuevo;
    int i=1;

    if(fp!=NULL)
    {
        while (i==1)
        {
            nuevo=cargaRegistro();
            fwrite(&nuevo,sizeof(stRegistro),1,fp);
            printf("Desea seguir cargando alumnos\n");
            printf("1-si\n");
            printf("2-no\n");
            scanf("%i",&i);
            system("cls");

        }

        fclose(fp);
    }


}

stRegistro cargaRegistro()
{
    stRegistro nuevo;
    printf("Ingrese comision :\n");
    scanf("%i",&nuevo.comision);
    printf("Ingrese nombre de la materia :\n");
    fflush(stdin);
    gets(nuevo.nombreMateria);
    printf("Ingrese ID de la materia :\n");
     scanf("%i",&nuevo.idMateria);
    printf("Ingrese nombre y apellido del alumno :\n");
    fflush(stdin);
    gets(nuevo.nombreAlumno);
    printf("Ingrese el legajo del alumno :\n");
     scanf("%i",&nuevo.legajoAlumno);
    printf("Ingrese la nota del alumno :\n");
     scanf("%i",&nuevo.nota);
    printf("Ingrese numero de examen :\n");
     scanf("%i",&nuevo.nroExamen);
    system("cls");
    return nuevo;
}

stMateria llenarMateria (char nombre[], int id)
{
    stMateria nuevo;
    strcpy(nuevo.nombreMateria,nombre);
    nuevo.idMateria=id;
    return nuevo;

    }
stAlumno llenarAlumno(char nombre[], int legajo)
{
    stAlumno nuevo;
    strcpy(nuevo.nombreAlumno,nombre);
    nuevo.legajo=legajo;
    return nuevo;

    }
stNota llenarNota (int nota, int examen)
{
    stNota nuevo;
    nuevo.nota=nota;
    nuevo.numExamen=examen;
    return nuevo;

    }

int  copiarRegistro (Celda comisiones[], int dimension)
{
    FILE*fp;
    fp=fopen(nombreArch,"rb");
    int validos = 0;
    stMateria m;
    stAlumno a;
    stNota n;
    stRegistro nuevo;
    if (fp!=NULL)
    {
        while(fread(&nuevo,sizeof(stRegistro),1,fp)>0)
        {
            m=llenarMateria(nuevo.nombreMateria,nuevo.idMateria);
            a=llenarAlumno(nuevo.nombreAlumno,nuevo.legajoAlumno);
            n=llenarNota (nuevo.nota,nuevo.nroExamen);
            validos = altaArreglo(comisiones,m,nuevo.comision,n,a,validos);

        }

        fclose(fp);
    }else
    {
        printf("Ha sucedido un error en la apertura del archivo\n");
        printf("O\n");
        printf("No hay datos en el archivo\n\n");
    }
    return validos;
}

void actualizarArchivo (Celda comisiones[],int validos)
{
    FILE* buff = fopen(nombreArch,"wb");
    int i = 0;
    stRegistro rg;

    if(buff)
    {
        while(i < validos)
        {

            nodoMateria* seg = comisiones[i].listaMateria;

            while(seg)
            {
                arbolNotas* arbol = seg->arbolNota;
                rg.comision = comisiones[i].comision;
                rg.idMateria = seg->dato.idMateria;
                strcpy(rg.nombreMateria,seg->dato.nombreMateria);

                guardarRegistro(buff,arbol,rg);

                seg = seg->siguiente;
            }
            i++;
        }
        fclose(buff);
    }else
        printf("Archivo no abierto correctamente\n");

}

void guardarRegistro (FILE* buff,arbolNotas* arbol,stRegistro rg)
{
    if(arbol)
    {
        rg.legajoAlumno = arbol->alumno.legajo;
        strcpy(rg.nombreAlumno,arbol->alumno.nombreAlumno);
        rg.nota = arbol->nota.nota;
        rg.nroExamen = arbol->nota.numExamen;
        fwrite(&rg,sizeof(stRegistro),1,buff);

        guardarRegistro(buff,arbol->der,rg);
        guardarRegistro(buff,arbol->izq,rg);
    }
}


