/*
Autor: 
Compilador: 
Compilado: 
Fecha: Wed May 12 22:06:52 CST 2021
Librerias: 
Resumen: 
Entrada: 
Salida: 
*/

//Librerias
#include <stdio.h>
#include <math.h>
#define pi 3.141592

float f(float t);
float df(float t);
float poli(float t, float h);
void main(void){
    float a=0,b=pi,y=1,h,t=a;
    int n;
    printf("Escriba el número de iteraciones");
    scanf("%d",&n);
    h=(b-a)/n;
    FILE *pf =fopen("coseno","wt");
    for (int i = 0; i < n; i++)
    {
        fprintf(pf,"%f\t%f\n",t,y);
        y+=h*poli(t,h);
        t+=h;
    }
    fclose(pf);

    FILE *gnuplot = popen("gnuplot -persist","w");
    fprintf(gnuplot,"unset label\n");
    fprintf(gnuplot,"set term png\n");
    fprintf(gnuplot,"set output 'coseno.png'\n");
    fprintf(gnuplot,"set xrange [0:3.15]\n");
    fprintf(gnuplot,"set yrange [-1:1]\n");
    fprintf(gnuplot,"set title 'Coseno'\n");
    fprintf(gnuplot,"set xlabel 't'\n");
    fprintf(gnuplot,"set ylabel 'y(t)'\n");
    fprintf(gnuplot,"set grid\n");
    fprintf(gnuplot,"unset key\n");
    fprintf(gnuplot,"plot 'coseno' using 1:2 pt 0.5\n");
    fprintf(gnuplot,"set output\n");
    pclose(gnuplot);
    
}

float f(float t){
    return -sin(t);
}

float df(float t){
    return -cos(t);
}
float poli(float t, float h){
    float res;
    res=f(t)+0.5*h*df(t);
    return res;
}