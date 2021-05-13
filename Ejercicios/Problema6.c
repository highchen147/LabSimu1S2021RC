/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc Problema6.c -lm -o Problema6_cmd && ./Problema6_cmd
Fecha: Wed May  5 13:27:58 CST 2021
Librerias: math.h
Resumen: Varias sumatorias
Entrada: valor final de las sumatorias
Salida: resultado de todas las sumatorias
*/

//Librerias
#include <stdio.h>
#include <math.h>
//se define la función que realiza la suma del inciso a)
float sumaA(int n){
    //se define la variable r que almacena la sumatoria
    float r=0;
    //se define un for que itere sobre todos los elementos de la sumatoria, de 1 a n
    for (int k = 1; k <= n; k++)
    {
        //se aplica la fórmula k^2*(k-3)
        r+=k*k*(k-3);
    }
    //se devuelve r
    return r;
}
// se define la función que realiza la sumatoria del inciso b)
float sumaB(int n){
    //se define la variable r que almacena la sumatoria
    float r=0;
    //se usa un for que itere sobre todos los elementos de la sumatoria, de 2 a n
    for (int k = 2; k <= n; k++)
    {
        //se aplica la fórmula 3/(k-1)
        r += 3/((float)k-1);
    }
    //se devuelve r
    return r;
}
//se define una función que realiza la sumatoria del inciso c)
float sumaC(int n){
    //se definen constantes para evitar que el código se vea complicado
    float r=0;
    float a=(1+sqrt(5))/2;
    float b=(1-sqrt(5))/2;
    for (int k = 1; k <= n; k++)
    {
        //se aplica la fórmula dada en el enunciado
        r+=(1/sqrt(5))*(pow(a,k)-pow(b,k));
    }
    return r;
}
//se define una función que realiza la sumatoria del inciso d)
float sumaD(int n){
    //se usa r como la variable que almacena la sumas
    float r=0;
    for (int k = 2; k <= n; k++)
    {
        //se aplica la fórmula de la sucesión de Bode
        r += 0.1*(3*pow(2,k-2)+4);
    }
    //devuelve r
    return r;
}

void main(void){
    //se usa una variable entera n para que la ingrese el usuario
    int n;
    printf("Ingrese el valor final n de las sumatorias\n");
    scanf("%d",&n);
    //dado que las sumatorias B y D no están definidas para n=1, las omitimos con un if
    if (n == 1)
    {
        printf("El valor de la sumatoria A es: %f\n",sumaA(n));
        printf("El valor de la sumatoria C es: %f\n",sumaC(n));
        printf("Las sumatorias B y D no están definidas para n=1\n");
    } else if (n > 1){
        printf("El valor de la sumatoria A es: %f\n",sumaA(n));
        printf("El valor de la sumatoria B es: %f\n",sumaB(n));
        printf("El valor de la sumatoria C es: %f\n",sumaC(n));
        printf("El valor de la sumatoria D es: %f\n",sumaD(n));
    } else{
        printf("valor inválido de n\n");
    }
}