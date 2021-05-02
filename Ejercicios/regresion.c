/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc regresion.c -lm -o regresion_cmd && ./regresion_cmd
Fecha: Fri Apr 23 01:34:52 UTC 2021
Librerias: math.h
Resumen: Encontrar la recta que mejor se ajuste a los datos proporcionados
Entrada: 
Salida: Gráfica de la recta
*/

#include <stdio.h>
#include <math.h>
//definimos el número de datos
int n=6;
//definimos la función que suma todos los números de un arreglo
float sum1(float x[n])
{
    //la variable s almacena la suma
    float s=0;
    for (int i = 0; i < n; i++)
    {
        s+=x[i];
    }
    //la función retorna el valor s
    return s;
}
//definimos la función que suma la multiplicación de dos números, cada uno de un arreglo diferente
float sum2(float x[n],float y[n])
{
    float s=0;
    for (int i = 0; i < n; i++)
    {
        s+=x[i]*y[i];
    }
    return s;
}
void main(void){
    //definimos dos listas, una para la velocidad (v) y otra para el tiempo (t)
    float v[6]={1,3,8,11,14,18};
    float sv[6];
    float t[6]={2.1,3.0,5.2,7.1,9.2,10.1};
    float st[6]={0.1,0.1,0.1,0.1,0.1,0.1};
    //definimos m para la pendiente y b para el intercepto en y
    float m,b;
    //calculamos m
    m = (n*sum2(v,t)-sum1(v)*sum1(t))/(n*sum2(t,t)-(sum1(t)*sum1(t)));
    //calculamos b
    b = (sum1(v)-m*sum1(t))/(n);
    printf("%f, %f",m,b);
    char eme[100],be[100];
    sprintf(eme,"%f",m);
    sprintf(be,"%f",b);
    for (int i = 0; i < 6; i++)
    {
        sv[i]=m*0.1;
    }
    printf("\n%f ",sv[0]);

    FILE *datosplot = fopen("data.txt", "w");

    for (int i = 0; i < 6; i++)
    {
        fprintf(datosplot,"%f %f %f %f\n",t[i],st[i],v[i],sv[i]);
    }
    FILE *gnuplot = popen("gnuplot -persist","w");
    fprintf(gnuplot,"unset label\n");
    fprintf(gnuplot,"set terminal 'epslatex'\n");
    fprintf(gnuplot,"set output 'graf.tex'\n");
    fprintf(gnuplot,"set xrange [0:12]\n");
    fprintf(gnuplot,"set yrange [0:12]\n");
    fprintf(gnuplot,"set title 'Velocidad - Tiempo'\n");
    fprintf(gnuplot,"set xlabel 't'\n");
    fprintf(gnuplot,"set ylabel 'v(t)'\n");
    fprintf(gnuplot,"set grid\n");
    fprintf(gnuplot,"unset key\n");
    fprintf(gnuplot,"m=%f\n",m);
    fprintf(gnuplot,"b=%f\n",b);
    fprintf(gnuplot,"f(x)=m*x+b\n");
    fprintf(gnuplot,"unset key\n");
    fprintf(gnuplot,"plot f(x), 'data.txt' using 1:3:2:4 with xyerrorbars pt 3\n");
    fprintf(gnuplot, "set  output\n");
    fclose(datosplot);
    pclose(gnuplot);
}