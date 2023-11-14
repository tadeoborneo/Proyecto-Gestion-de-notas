#include <stdio.h>
#include <stdlib.h>
#include "string.h"
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

void cargaArchivo (char[]);
stRegistro cargaRegistro();


int main()
{

    Celda comisiones[3];
    int validos=0;
    validos=copiarRegistro(comisiones,3);
    ///cargar datos al archivo o cargar archivo existente///
            int b=0;
            int c=1;
            while (c==1)
            {
            printf("Ingresar como Profesor o como alumno?\n");
            printf("1-Profesor\n");
            printf("2-Alumno\n");
            scanf("%i",&b);
            switch (b)
            {
            case 1:
                {
                    int i=0;
                    int d=0;
                    printf("Ha ingresado como profesor\n");
                    for (i;i<3;i++)
                    {
                        printf("Ingrese la contraseña para entrar al sistema\n");
                        scanf("%i",&d);
                        if(d==1234)
                        {
                            int e=0;
                            printf("Bienvenido\n");
                            printf("Que desea hacer?\n");
                            printf("1-Ver informacion sobre comisiones y notas de alumnos\n");
                            printf("2-Modificar notas de alumnos\n");
                            printf("3-Elimnar alumno de base de datos\n");
                            printf("4-Cargar archivo\n");
                            scanf("%i",&e);
                            switch(e)
                            {
                            case 1:
                                {

                                    ///funcion que muestra por comision,materia y alumno
                                    break;
                                }
                            case 2:
                                {
                                    ///busca alumno y materia y modifica una nota
                                    break;
                                }
                            case 3:
                                {
                                    ///elimina a un alumno de la base de datos
                                    break;
                                }
                            case 4:
                                {
                                    cargaArchivo(nombreArch);

                                }
                            }
                        }else
                        {
                                printf("Contraseña erronea intente nuevamente \n");

                        }
                    }
                    printf("Cantidad de intentos excedido\n");
                    break;

                }
            case 2:
                {
                    int f=1;
                    int idMateria=0;
                    int legajo=0;
                    while (f==1)
                    {
                    printf("Ingrese su numero de legajo \n");
                    scanf("%i",&legajo);
                    ///funcion mostrar materias y sus respectivos id
                    printf("Ingrese el id de la materia \n");
                    scanf("%i",&idMateria);
                    ///FUNCION BUSCADORA DE NOTAS Y ALUMNOS
                    printf("Desea seguir buscando sus notas? \n");
                    printf("1-Seguir buscando\n");
                    printf("2-Salir\n");
                    scanf("%i",&f);

                    }

                break;
                }
            }
                printf("Desea seguir en el programa o finalizar las consultas?\n");
                printf("1-Seguir en el programa\n");
                printf("2-Salir del programa\n");
                scanf("%i",&c);
            }




///nueva carga///sstruct
    return 0;
}



void cargaArchivo (char nombreArchivo[30])
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

        }

        fclose(fp);
    }


}

stRegistro cargaRegistro()
{
    stRegistro nuevo;
    printf("Ingrese comision :\n");
    scanf("%i",&nuevo.comision);
    printf("Ingrese nombre de la materia\n");
    fflush(stdin);
    gets(nuevo.nombreMateria);
    printf("Ingrese ID de la materia \n");
     scanf("%i",&nuevo.idMateria);
    printf("Ingrese nombre y apellido del alumno\n");
    fflush(stdin);
    gets(nuevo.nombreAlumno);
    printf("Ingrese el legajo del alumno\n");
     scanf("%i",&nuevo.legajoAlumno);
    printf("Ingrese la nota del alumno\n");
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
        printf("No hay datos en el archivo\n");
    }
}

