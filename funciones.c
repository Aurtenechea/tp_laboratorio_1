float suma(float x,float y)
{
    float resultado;
    resultado=x+y;

    return resultado;
}


float resta(float x,float y)
{
    float resultado;
    resultado=x-y;

    return resultado;
}


float division(float x,float y)
{
    float resultado;
    resultado=x/y;

    return resultado;
}

float multiplicacion(float x,float y)
{
    float resultado;
    resultado=x*y;

    return resultado;
}

int factorial (int x)
{
    int rta;


    if (x==0)
    {
        rta=1;

    }
    else
    {
        rta = x * factorial(x-1);
    }

    return rta;
}
