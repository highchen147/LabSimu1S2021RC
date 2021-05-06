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
//se define la función de multiplicación de matrices por constante
void multC(float c,float a[3][3]){
    //con un for anidado se recorre la matriz y se multiplica cada entrada por la constante
    for (int i = 0; i < 3; i++)
    { 
        for (int j = 0; j < 3; j++)
        {
            //se imprime la multiplicación
            printf("%f, ", c*a[i][j]);
        }
        printf("\n");
    }
    
}
//se define la función de suma de matrices
void suma(float a[3][3],float b[3][3]){
    //con un dos ciclos for anidados se recorren ambas matrices y se suma cada componente
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //se imprime la suma de cada pard e componentes
            printf("%f, ",a[i][j]+b[i][j]);
        }
        printf("\n");
    }
}
//se define función de la resta de matrices
void resta(float a[3][3], float b[3][3]){
    //con un dos ciclos for anidados se recorren ambas matrices y se calcula cada componente
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //se imprime la resta de cada par de componentes
            printf("%f, ",a[i][j]-b[i][j]);
        }
        printf("\n");
    }
}
//se define la función de multiplicación de matrices
void mult(float a[3][3], float b[3][3]){
    //se define una matriz auxiliar c que será la matriz resultante de la multiplicación
    float c[3][3];
    //con dos ciclos for anidados recorremos la matriz resultante
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j]=0;
            //se realiza la operación para cada componente de c, usando la fórmula para la multiplicación clásica de matrices
            for (int k = 0; k < 3; k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
            //se imprime cada entrada de la matriz c
            printf("%f, ",c[i][j]);
        }
        printf("\n");
    }
}
/*se define una función para encontrar la matriz inversa, esta función necesita como argumento el determinante
 de la matriz que se le ingresa*/
void inv(float a[3][3], float det){
    //se define el vector auxiliar c que almacenará las entradas de los cofactores
    float c[3];
    //la matriz b será la matriz inversa
    float b[3][3];
    //el contador m llevará la cuenta de la posición para las entradas de los cofactores
    int m;
    //los ciclos con i y j se usan para encontrar el cofactor de cada elemento de la matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {   
            /*los ciclos con k y l buscan los elementos para calcular los cofactores,
            el vector que almacena los cofactores se reutiliza cada vez que se repite el ciclo
            entonces debe de tener un punto de referencia, para eso se usa la variable m, que al
            comenzar el ciclo debe ser cero.*/
            m=0;
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    /*los cofactores de cada elemento de la matriz a se encuentran en las entradas de a cuya posición 
                    sea distinta a la del elemento en cuestión, para eso se usa el siguiente if*/
                    if ((k != j) && (l != i))
                    {
                        /*se almacena los elementos para calcular el cofactor en c*/
                        c[m]=a[k][l];
                        m += 1;
                    }
                }
            }
            /*se calcula el cofactor y se almacena en b, además se debe de dividir dentro del determinante para
            encontrar la inversa */
            b[i][j]=pow(-1,i+j)*(c[0]*c[3]-c[2]*c[1])/det;
            //se imprime cada componente de la matriz
            printf("%0.001f ",b[i][j]);
        }
        printf("\n");
    }
}
//se define una función que calcula el determinante
float det(float a[3][3]){
    float d;
    //se aplica la fórmula para el determinante de a
    d = a[0][0]*a[1][1]*a[2][2] + a[1][0]*a[2][1]*a[0][2] + a[2][0]*a[0][1]*a[1][2] - a[1][0]*a[0][1]*a[2][2] - a[0][0]*a[2][1]*a[1][2] - a[2][0]*a[1][1]*a[0][2];
    return d;
}
//se define una función que muestra la transpuesta de una matriz
void trans(float a[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //se muestra la componente de la transpuesta
            printf("%f, ",a[j][i]);
        }
        printf("\n");
    }    
}

void main(void){
    //se definen las matrices que almacenarán las proporcionadas por el usuario
    float matA[3][3], matB[3][3];
    //se define una constante escalar
    float c;
    //se le pide al usuario ingresar la matriz A
    printf("Escriba cada entrada de la matriz seguido de ENTER, por favor\n");
    printf("Escriba la primera fila de la matriz A\n");
    scanf("%f %f %f",&matA[0][0],&matA[0][1],&matA[0][2]);
    printf("\nEscriba la segunda fila de la matriz A\n");
    scanf("%f %f %f",&matA[1][0],&matA[1][1],&matA[1][2]);
    printf("\nEscriba la tercera fila de la matriz A\n");
    scanf("%f %f %f",&matA[2][0],&matA[2][1],&matA[2][2]);
    //se le pide al usuario ingresar la matriz B
    printf("\nEscriba la primera fila de la matriz B\n");
    scanf("%f %f %f",&matB[0][0],&matB[0][1],&matB[0][2]);
    printf("\nEscriba la segunda fila de la matriz B\n");
    scanf("%f %f %f",&matB[1][0],&matB[1][1],&matB[1][2]);
    printf("\nEscriba la tercera fila de la matriz B\n");
    scanf("%f %f %f",&matB[2][0],&matB[2][1],&matB[2][2]);
    //se le pide al usuario ingresar la constante
    printf("\nEscriba la constante que multiplica a A\n");
    scanf("%f",&c);
    //se muestran los resultados
    printf("\nEl resultado de multiplicar c por A es:\n");
    multC(c,matA);
    printf("\nEl resultado de A + B es:\n");
    suma(matA,matB);
    printf("\nEl resultado de A - B es:\n");
    resta(matA,matB);
    printf("\nEl resultado de A.B es:\n");
    mult(matA,matB);
    printf("\nEl determinante de A es:\n");
    printf("%f\n",det(matA));
    printf("\nLa transpuesta de B es:\n");
    trans(matB);
    //se valida si el determinante de A no es cero para mostrar su inversa
    if (det(matA)!= 0)
    {
        printf("\nLa inversa de A es:\n");
        inv(matA,det(matA));
    }else{
        printf("\nA no tiene inversa\n");
    }

}