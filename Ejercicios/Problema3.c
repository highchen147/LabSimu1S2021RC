/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc Problema3.c -lm -o Problema3_cmd && ./Problema3_cmd
Fecha: Tue Apr 20 03:21:53 UTC 2021
Librerias: math.h
Resumen: Varios calculos con un par de vectores
Entrada: dos vectores en R3
Salida: varias salidas
*/

//Librerias
#include <stdio.h>
#include <math.h>
//se define una función que sume dos vectores
void suma(float a[], float b[]){
    //se define el vector resultante de la suma
    double c[3];
    //con un ciclo for se suma componente por componente y se almacena en la componente correspondiente de c
    for (int i = 0; i < 3; i++)
    {
        c[i]=a[i]+b[i];
        //se imprime cada componente del vector
        printf("%f, ",c[i]);
    }
    printf("\n");
}
//se define una función que devuelve el producto escalar entre dos vectores
float escalar(float a[], float b[]){
    double c=0;
    for (int i = 0; i < 3; i++)
    {
        //se aplica la multiplicación de componente por componente y se suma
        c+=a[i]*b[i];
    }
    //retorna el resultado de la sumatoria
    return c;
}
//se define el producto cruz entre dos vectores
void cruz(float a[], float b[]){
    //se declara el vector resultante 
    double c[3];
    //se aplica la fórmua del producto cruz en las componentes del vector c
    c[0]=a[1]*b[2]-a[2]*b[1];
    c[1]=a[2]*b[0]-a[0]*b[2];
    c[2]=a[0]*b[1]-a[1]*b[0];
    printf("%f, %f, %f \n",c[0],c[1],c[2]);
}
void main(void){
    //se declaran los vectores a ser operados
    float a[3],b[3];
    //se le pide al usuario ingresar ambos vectores
    printf("ingrese las componentes del vector a, separadas por un ENTER o por espacio \n");
    scanf("%f %f %f",&a[0],&a[1],&a[2]);
    printf("ingrese las componentes del vector b, separadas por un ENTER o por espacio \n");
    scanf("%f %f %f",&b[0],&b[1],&b[2]);
    //se imprime la magnitud del vector a, que es la raíz cuadrada del producto escalar a.a
    printf("la magnitud de a es: \n");
    printf("%f \n",sqrt(escalar(a,a)));
    //se imprime la magnitud del vector b, que es la raíz cuadrada del producto escalar b.b
    printf("la magnitud de b es: \n");
    printf("%f \n",sqrt(escalar(a,a)));
    //se imprime la suma vectorial a + b
    printf("la suma vectorial de a + b es: \n");
    suma(a,b);
    //se imprime el producto escalar a.b
    printf("el producto escalar a.b es: \n %f \n",escalar(a,b));
    //se imprime el producto vectoria a x b
    printf("el producto vectorial es: \n");
    cruz(a,b);
}