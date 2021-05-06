/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc Problema5.c && ./a.out
Fecha: Wed May  5 13:00:14 CST 2021
Librerias: math.h
Resumen: Función factorial con recursividad
Entrada: número entero
Salida: factorial del número ingresado
*/

//Librerias
#include <stdio.h>
#include <math.h>
//se define la función factorial que será utilizada recursivamente
int fact(int n){
    if (n==0 || n==1)
    {   
        //se calcula el caso base, cuando n=1 o cuando n=0 cuyos factoriales son 1
        return 1;
    }else{
        //se utiliza la propiedad n!=n*(n-1)!
        return n*fact(n-1);
    }
}
void main(void){
    //se le pide al usuario que ingrese el número entero a calcularle su factorial
    printf("Escriba el numero a calcularle el factorial\n");
    int n;
    scanf("%d",&n);
    //se muestra el resultado
    printf("el factorial es %d\n",fact(n));
}
