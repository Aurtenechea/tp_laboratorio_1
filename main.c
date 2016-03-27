#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    float operando1=0, operando2=0,sumaResult,restaResult, divResult, multResult, factResult;
    char seguir='s';
    int opcion=0, operando1Entero;

    do
    {
        printf("1- Ingresar 1er operando (A=%f)\n",operando1);
        printf("2- Ingresar 2do operando (B=%f)\n",operando2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);
        system("cls");

        if (opcion < 1 || opcion > 9)
        {
            printf("El valor ingresado es incorrecto.\n");
        }

        else if ((opcion==5 || opcion==8) && operando2 == 0)
        {
            printf("No se puede realizar una division por cero.\n");
        }

        else
        {
            /*en las opciones que usan la funcion factorial() (opciones 7 u 8) redondea y
            castea el valor a un entero del operando1 para usarlo como parametro de la funcion factorial()*/
            if (opcion==7 || opcion ==8)
            {
                operando1Entero  = (int)(operando1+0.5);
            }
            switch(opcion)
            {
                case 1:
                    printf("Ingrese el primer operando...\n");
                    scanf("%f", &operando1);
                    fflush(stdin);
                    system("cls");
                    break;
                case 2:
                    printf("Ingrese el segundo operando...\n");
                    scanf("%f", &operando2);
                    fflush(stdin);
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    printf("El resultado de %f + %f es: %f.\n", operando1, operando2, suma(operando1, operando2));
                    break;
                case 4:
                    system("cls");
                    printf("El resultado de %f - %f es: %f.\n", operando1, operando2, resta(operando1, operando2));
                    break;
                case 5:
                    system("cls");
                    printf("El resultado de %f / %f es: %f.\n", operando1, operando2, division(operando1, operando2));
                    break;
                case 6:
                    system("cls");
                    printf("El resultado de %f * %f es: %f.\n", operando1, operando2, multiplicacion(operando1, operando2));
                    break;
                case 7:
                    system("cls");
                    printf("El resultado de %d! es: %d.\n", operando1Entero, factorial(operando1Entero));
                    break;
                case 8:
                    system("cls");
                    printf("El resultado de %f + %f es: %f.\n", operando1, operando2, suma(operando1, operando2));
                    printf("El resultado de %f - %f es: %f.\n", operando1, operando2, resta(operando1, operando2));
                    printf("El resultado de %f / %f es: %f.\n", operando1, operando2, division(operando1, operando2));
                    printf("El resultado de %f * %f es: %f.\n", operando1, operando2, multiplicacion(operando1, operando2));
                    printf("El resultado de %d! es: %d.\n", operando1Entero, factorial(operando1Entero));
                    break;
                case 9:
                    system("cls");
                    printf("Bye bye..");
                    seguir = 'n';
                    break;

            }
        }
    }while(seguir=='s');

    return 0;
}
