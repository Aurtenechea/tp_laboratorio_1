#include "funciones.h"


/**
    Cree dos tipos de estructura una para trabajar con las eMovies cargadas en memoria. y otra para guardarlas en el fichero binario.
    La idea fue que las cargadas en memoria, ocupen el menor espacio posible por eso todos sus campos de texto se crean dinamicante,
    no asi las que se guardaran en el archivo binario, ya que deben ocupar una cantidad de bytes fija.

    Tambien les agregue un campo Id ya que tiene que haber un campo que las pueda identificar inequivocamente, y el campo titulo no lo hace, ya que
    puede haber (y existen...) varias peliculas con el mismo nombre.

    Del esqueleto cambie muchas cosas, ya que le pregunte a Mauricio si se podia, y me dijo que podia modificar todo lo que quisiera.

    Existe la funcion imprimir (en pantalla) el array de eMovies, aunque no se consume en el main ya que no lo pedia, al igual que una funcion que harcodea 2 eMovies en el array.
    Por ahi sirven para corregir... estan comentadas al comienzo del main. Para usar la funcion "hardcodeada" hay que eliminar los archivos binarios.

    27-5-16 Ignacio Aurtenechea
    ignacio.aurtenechea@gmail.com
*/


int main()
{
    //---------------------
    eMovie* eMoviePtrArray=NULL;
    eMovie eMovieAux;
    int cant=0;
    int cantALeer;
    //---------------------
    char* stringAux[10000];
    int idAux;
    int indiceAux;
    //menu-----------------
    int opcion=0;
    //---------------------


    cantALeer=leerBinCantArrayEMovies("cantEMovies.bin");
    eMoviePtrArray=leerBinArrayEMovies(cantALeer, &cant,"arrayEMovies.bin");

    //eMoviePtrArray=hardcodeada(eMoviePtrArray, &cant);
    do
    {
        //imprimirArrayEMovie (eMoviePtrArray, cant);

        printf("\n");
        printf("1- Agregar pelicula\n");
        printf("2- Modificar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");
        fflush(stdin);
        scanf("%[^\n]",stringAux);
        system("cls");
        while( !esNumerico(stringAux)) //valido si es numerico y no es negativo.
        {
            printf("\nError. Debe ingresar solo numeros.");
            printf("\n");
            printf("1- Agregar pelicula\n");
            printf("2- Modificar pelicula\n");
            printf("3- Borrar pelicula\n");
            printf("4- Generar pagina web\n");
            printf("5- Salir\n");
            fflush(stdin);
            scanf("%[^\n]",stringAux);
            system("cls");
        }
        opcion=atoi(stringAux);
        system("cls");
        switch(opcion)
        {
            case 1:
                printf("\nIngrese Id");
                fflush(stdin);
                scanf("%[^\n]",stringAux);
                system("cls");
                while( !esNumerico(stringAux) || strlen(stringAux) >= 10 || !validarRangoInt(atoi(stringAux), 0, 999999999) ) //valido si es numerico y no es negativo.
                {
                    printf("\nError. Debe ingresar solo numeros, el valor no puede ser negativo y debe estar entre 0 y 999.999.999 .");
                    printf("\nIngrese id: ");
                    fflush(stdin);
                    scanf("%[^\n]",stringAux);
                    system("cls");
                }
                eMovieAux.id=atoi(stringAux);
                if( buscarIdEMovie( eMoviePtrArray, cant, eMovieAux.id) != -1 )
                {
                    printf("\nERROR! Ya existe una pelicula con ese id.");
                    break;
                }
    //pido titulo-------------
                printf("\nIngrese Titulo: ");
                fflush(stdin);
                scanf("%[^\n]",stringAux);
                system("cls");
                while(strlen(stringAux)>1000)
                {
                    printf("\nTexto demasiado largo. Maximo 1000 caracteres. Intente nuevamente. ");
                    fflush(stdin);
                    scanf("%[^\n]",stringAux);
                    system("cls");
                }
                eMovieAux.titulo=(char*) malloc( sizeof(char) * (strlen(stringAux) + 1) );
                if(eMovieAux.titulo == NULL)
                {
                    printf("\nERROR! Error de memoria.");
                    exit(1);
                }
                strcpy(eMovieAux.titulo, stringAux);
        //pido genero-------------
                printf("\nIngrese genero: ");
                fflush(stdin);
                scanf("%[^\n]",stringAux);
                system("cls");
                while(strlen(stringAux)>1000)
                {
                    printf("\nTexto demasiado largo. Maximo 1000 caracteres. Intente nuevamente. ");
                    fflush(stdin);
                    scanf("%[^\n]",stringAux);
                    system("cls");
                }
                eMovieAux.genero=(char*) malloc( sizeof(char) * (strlen(stringAux) + 1) );
                if(eMovieAux.genero == NULL)
                {
                    printf("\nERROR! Error de memoria.");
                    exit(1);
                }
                strcpy(eMovieAux.genero, stringAux);
    //pido descripcion-------------
                printf("\nIngrese descripcion: ");
                fflush(stdin);
                scanf("%[^\n]",stringAux);
                system("cls");
                while(strlen(stringAux)>5000)
                {
                    printf("\nTexto demasiado largo. Maximo 5000 caracteres. Intente nuevamente. ");
                    fflush(stdin);
                    scanf("%[^\n]",stringAux);
                    system("cls");
                }
                eMovieAux.descripcion=(char*) malloc( sizeof(char) * (strlen(stringAux) + 1) );
                if(eMovieAux.descripcion == NULL)
                {
                    printf("\nERROR! Error de memoria.");
                    exit(1);
                }
                strcpy(eMovieAux.descripcion, stringAux);
        //pido link imagen-------------
                printf("\nIngrese link de imagen: ");
                fflush(stdin);
                scanf("%[^\n]",stringAux);
                system("cls");
                while(strlen(stringAux)>1000)
                {
                    printf("\nTexto demasiado largo. Maximo 1000 caracteres. Intente nuevamente. ");
                    fflush(stdin);
                    scanf("%[^\n]",stringAux);
                    system("cls");
                }
                eMovieAux.linkImagen=(char*) malloc( sizeof(char) * (strlen(stringAux) + 1) );
                if(eMovieAux.linkImagen == NULL)
                {
                    printf("\nERROR! Error de memoria.");
                    exit(1);
                }
                strcpy(eMovieAux.linkImagen, stringAux);
//VALIDAAAR!!!//pido duracion-------------
                printf("\nIngrese duracion en minutos: ");
                fflush(stdin);
                scanf("%[^\n]",stringAux);
                system("cls");
                while( !esNumerico(stringAux) || strlen(stringAux) >= 10 || !validarRangoInt(atoi(stringAux), 0, 999999999) ) //valido si es numerico y no es negativo.
                {
                    printf("\nError. Debe ingresar solo numeros, el valor no puede ser negativo y debe estar entre 0 y 999.999.999 .");
                    printf("\nIngrese duracion: ");
                    fflush(stdin);
                    scanf("%[^\n]",stringAux);
                    system("cls");
                }

                eMovieAux.duracion=atoi(stringAux);
//pido puntaje-------------
                printf("\nIngrese puntaje (0-100): ");
                fflush(stdin);
                scanf("%[^\n]",stringAux);
                system("cls");
                while( !esNumerico(stringAux) || strlen(stringAux) >= 10 || !validarRangoInt(atoi(stringAux), 0, 100) ) //valido si es numerico y no es negativo.
                {
                    printf("\nError. Debe ingresar solo numeros, el valor no puede ser negativo y debe estar entre 0 y 100 .");
                    printf("\nIngrese puntaje: ");
                    fflush(stdin);
                    scanf("%[^\n]",stringAux);
                    system("cls");
                }
                eMovieAux.puntaje=atoi(stringAux);
    //cargo una eMovie en el array------------
                eMoviePtrArray=cargarEMovie(eMoviePtrArray, eMovieAux, &cant);
                break;
            case 2:
                if(cant==0)
                {
                    printf("\nEl sistema esta vacio.");
                    break;
                }
                printf("\nIngrese Id");
                fflush(stdin);
                scanf("%[^\n]",stringAux);
                system("cls");
                while( !esNumerico(stringAux) || strlen(stringAux) >= 10 || !validarRangoInt(atoi(stringAux), 0, 999999999) ) //valido si es numerico y no es negativo.
                {
                    printf("\nError. Debe ingresar solo numeros, el valor no puede ser negativo y debe estar entre 0 y 999.999.999 .");
                    printf("\nIngrese id: ");
                    fflush(stdin);
                    scanf("%[^\n]",stringAux);
                    system("cls");
                }
                idAux=atoi(stringAux);
                indiceAux=buscarIdEMovie(eMoviePtrArray, cant, idAux);
                if( indiceAux == -1 )
                {
                    printf("\nNo existe una pelicula con ese id.");
                    break;
                }
                do
                {
                    printf("\n");
                    printf("\nQue desea modificar?");
                    printf("\n1- Titulo");
                    printf("\n2- Genero");
                    printf("\n3- Descripcion");
                    printf("\n4- Link imagen");
                    printf("\n5- Duracion");
                    printf("\n6- Puntaje");
                    printf("\n7- Id");
                    printf("\n8- Cancelar");
                    fflush(stdin);
                    scanf("%[^\n]",stringAux);
                    system("cls");
                    while( !esNumerico(stringAux)) //valido si es numerico y no es negativo.
                    {
                        printf("\nError. Debe ingresar solo numeros.");
                        printf("\n\n");
                        printf("\nQue desea modificar?");
                        printf("\n1- Titulo");
                        printf("\n2- Genero");
                        printf("\n3- Descripcion");
                        printf("\n4- Link imagen");
                        printf("\n5- Duracion");
                        printf("\n6- Puntaje");
                        printf("\n7- Id");
                        printf("\n8- Cancelar");
                        fflush(stdin);
                        scanf("%[^\n]",stringAux);
                        system("cls");
                    }
                    opcion=atoi(stringAux);
                    system("cls");
                    fflush(stdin);
                    switch(opcion)
                    {
                        case 1:
                            printf("\nIngrese el nuevo titulo: ");
                            fflush(stdin);
                            scanf("%[^\n]",stringAux);
                            system("cls");
                            while(strlen(stringAux)>1000)
                            {
                                printf("\nTexto demasiado largo. Maximo 1000 caracteres. Intente nuevamente. ");
                                fflush(stdin);
                                scanf("%[^\n]",stringAux);
                                system("cls");
                            }
                            modificarEMovie(eMoviePtrArray, indiceAux, opcion, stringAux);
                            printf("\nTitulo de la eMovie modificada: %s", (eMoviePtrArray+indiceAux)->titulo);
                            break;
                        case 2:
                            printf("\nIngrese el nuevo genero: ");
                            fflush(stdin);
                            scanf("%[^\n]",stringAux);
                            system("cls");
                            while(strlen(stringAux)>1000)
                            {
                                printf("\nTexto demasiado largo. Maximo 1000 caracteres. Intente nuevamente. ");
                                fflush(stdin);
                                scanf("%[^\n]",stringAux);
                                system("cls");
                            }
                            modificarEMovie(eMoviePtrArray, indiceAux, opcion, stringAux);
                            break;
                        case 3:
                            printf("\nIngrese la nueva descripcion: ");
                            fflush(stdin);
                            scanf("%[^\n]",stringAux);
                            system("cls");
                            while(strlen(stringAux)>5000)
                            {
                                printf("\nTexto demasiado largo. Maximo 5000 caracteres. Intente nuevamente. ");
                                fflush(stdin);
                                scanf("%[^\n]",stringAux);
                                system("cls");
                            }
                            modificarEMovie(eMoviePtrArray, indiceAux, opcion, stringAux);
                            break;
                        case 4:
                            printf("\nIngrese el nuevo link de imagen: ");
                            fflush(stdin);
                            scanf("%[^\n]",stringAux);
                            system("cls");
                            while(strlen(stringAux)>1000)
                            {
                                printf("\nTexto demasiado largo. Maximo 1000 caracteres. Intente nuevamente. ");
                                fflush(stdin);
                                scanf("%[^\n]",stringAux);
                                system("cls");
                            }
                            modificarEMovie(eMoviePtrArray, indiceAux, opcion, stringAux);
                            break;
                        case 5:
                            printf("\nIngrese la nueva duracion: ");
                            fflush(stdin);
                            scanf("%[^\n]",stringAux);
                            system("cls");
                            while( !esNumerico(stringAux) || strlen(stringAux) >= 10 || !validarRangoInt(atoi(stringAux), 0, 999999999) ) //valido si es numerico y no es negativo.
                            {
                                printf("\nError. Debe ingresar solo numeros, el valor no puede ser negativo y debe estar entre 0 y 999.999.999 .");
                                printf("\nIngrese la nueva duracion: ");
                                fflush(stdin);
                                scanf("%[^\n]",stringAux);
                                system("cls");
                            }
                            modificarEMovie(eMoviePtrArray, indiceAux, opcion, stringAux);
                            break;
                        case 6:
                            printf("\nIngrese el nuevo puntaje (0-100): ");
                            fflush(stdin);
                            scanf("%[^\n]",stringAux);
                            system("cls");
                            while( !esNumerico(stringAux) || strlen(stringAux) >= 10 || !validarRangoInt(atoi(stringAux), 0, 100) ) //valido si es numerico y no es negativo.
                            {
                                printf("\nError. Debe ingresar solo numeros, el valor no puede ser negativo y debe estar entre 0 y 100 .");
                                printf("\nIngrese el nuevo puntaje (0-100): ");
                                fflush(stdin);
                                scanf("%[^\n]",stringAux);
                                system("cls");
                            }
                            modificarEMovie(eMoviePtrArray, indiceAux, opcion, stringAux);
                            break;
                        case 7:
                            printf("\nIngrese el nuevo id: ");
                            fflush(stdin);
                            scanf("%[^\n]",stringAux);
                            system("cls");
                            while( !esNumerico(stringAux) || strlen(stringAux) >= 10 || !validarRangoInt(atoi(stringAux), 0, 999999999) ) //valido si es numerico y no es negativo.
                            {
                                printf("\nError. Debe ingresar solo numeros, el valor no puede ser negativo y debe estar entre 0 y 999.999.999 .");
                                printf("\nIngrese el nuevo id: ");
                                fflush(stdin);
                                scanf("%[^\n]",stringAux);
                                system("cls");
                            }
                            modificarEMovie(eMoviePtrArray, indiceAux, opcion, stringAux);
                            break;
                        default:
                            printf("\nIngrese una opcion valida.");
                    }
                }while(opcion != 8);
    //Continua el Switch principal--------------------
                break;
            case 3:
                 if(cant==0)
                {
                    printf("\nEl sistema esta vacio.");
                    break;
                }
                printf("\nIngrese id: ");
                scanf("%d", &idAux);
                system("cls");
                if( (indiceAux=buscarIdEMovie(eMoviePtrArray, cant, idAux) ) == -1 )
                {
                    printf("\nNo existe una pelicula con ese id.");
                    break;
                }
                borrarEMovie(eMoviePtrArray, &cant, indiceAux);
                break;
            case 4:
                if(cant==0)
                {
                    printf("\nEl sistema esta vacio.");
                    break;
                }
                printf("\nIngrese el nombre del fichero html (ej: index.html).");
                fflush(stdin);
                scanf("%[^\n]",stringAux);
                system("cls");
                while(strlen(stringAux)>1000 || !esAlfaNumericoPuntoGuion(stringAux))
                {
                    printf("\nTexto invalido. \nPuede ingresar texto alfanumerico, punto y guion bajo o medio. Maximo 1000 caracteres. \nIntente nuevamente. ");
                    fflush(stdin);
                    scanf("%[^\n]",stringAux);
                    system("cls");
                }
                generarHtml(eMoviePtrArray,cant, stringAux);
                break;
            case 5:
                break;
            default:
                printf("\nIngrese una opcion valida.");
        }
    }while(opcion!=5);

    guardarBinArrayEMovies(eMoviePtrArray, cant, "arrayEMovies.bin");
    guardarBinCantArrayEMovies(cant, "cantEMovies.bin");
    return 0;
}
