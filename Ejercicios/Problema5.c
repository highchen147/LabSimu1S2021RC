/*
Autor: Rodrigo Castillo
Compilador: 
Compilado: 
Fecha: Wed May  5 13:00:14 CST 2021
Librerias: math.h
Resumen: Función factorial con recursividad
Entrada: número entero
Salida: factorial del número ingresado
*/

//Librerias
#include <stdio.h>
#include <math.h>
//pasos del pseudocódigo

int fact(int n){
    if (n==0 || n==1)
    {
        return 1;
    }else{
        return n*fact(n-1);
    }
}
void main(void){
    printf("Escriba el numero a calcularle el factorial\n");
    int n;
    scanf("%d",&n);
    printf("el factorial es %d\n",fact(n));
}
