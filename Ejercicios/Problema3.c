/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc Problema3.c -lm -o Problema3_cmd && ./Problema3_cmd
Fecha: Tue Apr 20 03:21:53 UTC 2021
Librerias: 
Resumen: Varios calculos con un par de vectores
Entrada: dos vectores en R3
Salida: varias salidas
*/

//Librerias
#include <stdio.h>
#include <math.h>
//pasos del pseudocódigo
float norma(float a[]){
    double n=0,r;
    for (int i = 0; i < 3; i++)
    {
        n+=a[i]*a[i];
    }
    n=sqrt(n);
    return n;
}

void suma(float a[], float b[]){
    double c[3];
    for (int i = 0; i < 3; i++)
    {
        c[i]=a[i]+b[i];
        printf("%f, ",c[i]);
    }
    printf("\n");
}

float escalar(float a[], float b[]){
    double c=0;
    for (int i = 0; i < 3; i++)
    {
        c+=a[i]*b[i];
    }
    return c;
}

void cruz(float a[], float b[]){
    double c[3];
    c[0]=a[1]*b[2]-a[2]*b[1];
    c[1]=a[2]*b[0]-a[0]*b[2];
    c[2]=a[0]*b[1]-a[1]*b[0];
    printf("%f, %f, %f \n",c[0],c[1],c[2]);
}
void main(void){
    float a[3],b[3];
    printf("ingrese las componentes del vector a, separadas por un ENTER o por espacio \n");
    scanf("%f %f %f",&a[0],&a[1],&a[2]);
    printf("ingrese las componentes del vector b, separadas por un ENTER o por espacio \n");
    scanf("%f %f %f",&b[0],&b[1],&b[2]);
    printf("la magnitud de a es: \n");
    printf("%f \n",norma(a));
    printf("la magnitud de b es: \n");
    printf("%f \n",norma(b));
    printf("la suma vectorial de a + b es: \n");
    suma(a,b);
    printf("el producto escalar a.b es: \n %f \n",escalar(a,b));
    printf("el producto vectorial es: \n");
    cruz(a,b);
}