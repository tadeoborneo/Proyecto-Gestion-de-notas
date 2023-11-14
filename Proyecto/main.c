#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int comision;
   char nombreMateria[30];
   int idMateria;
   char nombreAlumno[30];
   int legajo;
   int nota;
}stRegistro

int main()
{

    ///cargar datos al archivo o cargar archivo existente///
    printf("Cargar un nuevo archivo o leer un archivo existente?\n");
    int a=0;
    printf("1-Cargar nuevo archivo desde 0 \n");
    printf("2-Cargar archivo existente y ver su informacion \n");
    scanf("%i",&a);
    switch (a)
    {
        case 1:
        {
            ///funcion de carga de datos////
            break;
        }
        case  2:
        {
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
                            }
                        }else
                        {
                                printf("Contraseña erronea intente nuevamente \n");

                        }
                    }
                    printf("Cantidad de intentos excedido\n")
                    break;

                }
            case 2:
                {
                    int f=1;
                    char materia[25];
                    char apellido[25];
                    while (f==1)
                    {
                    printf("Ingrese su apellido \n");
                    gets(apellido);
                    fflush(stedin);
                    printf("Ingrese la materia a buscar \n");
                    gets(materia);
                    fflush(stdin);
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

            break;
        }
    }


    return 0;
    
}
