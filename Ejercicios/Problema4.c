/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc Problema4.c -lm -o Problema4_cmd && ./Problema4_cmd
Fecha: Fri Apr 23 01:34:52 UTC 2021
Librerias: 
Resumen: Operaciones con dos matrices 3x3
Entrada: Dos matrices 3x3
Salida: Varios resultados
*/

//Librerias
#include <stdio.h>
#include <math.h>
//multiplicación de matrices
void multC(float c,float a[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f, ", c*a[i][j]);
        }
        printf("\n");
    }
    
}
//suma de matrices
void suma(float a[3][3],float b[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f, ",a[i][j]+b[i][j]);
        }
        printf("\n");
    }
}
//resta de matrices
void resta(float a[3][3], float b[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%f, ",a[i][j]-b[i][j]);
        }
        printf("\n");
    }
}
//multiplicación de matrices
void mult(float a[3][3], float b[3][3]){
    float c[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j]=0;
            for (int k = 0; k < 3; k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
            printf("%f, ",c[i][j]);
        }
        printf("\n");
    }
}
//matriz inversa
void inv(float a[3][3], float det){
    float c[3];
    float b[3][3];
    int m;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m=0;
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    if ((k != j) && (l != i))
                    {
                        c[m]=a[k][l];
                        m += 1;
                    }
                }
            }
            b[i][j]=pow(-1,i+j)*(c[0]*c[3]-c[2]*c[1])/det;
            printf("%0.001f ",b[i][j]);
        }
        printf("\n");
    }
}
float det(float a[3][3]){
    float d;
    d = a[0][0]*a[1][1]*a[2][2] + a[1][0]*a[2][1]*a[0][2] + a[2][0]*a[0][1]*a[1][2] - a[1][0]*a[0][1]*a[2][2] - a[0][0]*a[2][1]*a[1][2] - a[2][0]*a[1][1]*a[0][2];
    return d;
}

void main(void){
    float a[3][3]={{1,1,0},{1,0,0},{1,0,1}};
    float b[3][3]={{0,1,0},{1,-1,0},{0,-1,1}};
    mult(a,b);
    //printf("\n");
    // printf("%f \n",det(a));
    inv(a,det(a));
}