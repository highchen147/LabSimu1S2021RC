/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc biseccion.c -lm -o biseccion_cmd && ./biseccion_cmd
Fecha: Fri Apr 23 01:34:52 UTC 2021
Librerias: math.h
Resumen: Encontrar la raíz de una función gaussiana con el método de bisección
Entrada: 
Salida: Raíz de f(x)
*/

#include <stdio.h>
#include <math.h>

//Se define la función f(x)=e^(-x^2)-0.5
float f(float x){
    return exp(-0.5*(x*x))-0.5;
}

void main(void){
    float x0,xf;
    //se define el intervalo en donde se buscará la raíz
    x0 = 1;
    xf = 1.4;
    //se define xp y a xp1 como el punto medio de la interación anterior
    float xp = 0.5*(x0+xf),xp1;
    //Se define el error máximo como 100
    float error=100;
    //comienza el ciclo que deberá concluir cuando el error sea menor a 1%
    while (error > 0.1)
    {
        //se le asigna al valor final xf el valor medio xp si (f(x0)*f(xp)) < 0
        if ((f(x0)*f(xp)) < 0)
        {
            xf = xp;
        }
        //se le asigna al valor inicial x0 el valor medio xp si (f(x0)*f(xp)) > 0
        else if ((f(x0)*f(xp)) > 0)
        {
            x0 = xp;
        }
        //se le asigna el valor anterior del valor medio a xp1
        xp1 = xp;
        //se calcula el nuevo valor medio
        xp = 0.5*(x0+xf);
        //se calcula el error relativo
        error = 100*fabs(xp-xp1)/xp;
    }
    //se imprime la raíz encontrada
    printf("\nLa raíz es %f\n", xp);
    
}