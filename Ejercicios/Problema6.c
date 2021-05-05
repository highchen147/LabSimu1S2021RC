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
//pasos del pseudocódigo
float sumaA(int n){
    float r=0;
    for (int k = 1; k <= n; k++)
    {
        r+=k*k*(k-3);
    }
    return r;
}

float sumaB(int n){
    float r=0;
    for (int k = 2; k <= n; k++)
    {
        r += 3/((float)k-1);
    }
    return r;
}

float sumaC(int n){
    float r=0;
    float a=(1+sqrt(5))/2;
    float b=(1-sqrt(5))/2;
    for (int k = 1; k <= n; k++)
    {
        r+=(1/sqrt(5))*(pow(a,k)-pow(b,k));
    }
    
}

void main(void){
    printf("%f\n",sumaA(3));
    printf("%f\n",sumaB(3));
    printf("%f\n",sumaC(10));


}