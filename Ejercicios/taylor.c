/*
Autor:    Maynor Ballina
Fecha:  Fri May 7 12:27:54 CST 2021
compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para Compilar: gcc -o metodosnumericoP2 metodosnumericoP2.c
Version: 1.0
librerias: stdio (u otras)
Resumen: Metodo numerico de taylor
*/

//Librerias
#include <stdio.h>
#include <math.h>
//Declaracion e inicializacion de variables globales
float f(float t, float y);
float df(float t, float y);
float politaylor(float t, float y, float h);
float mntaylor(float a, float b, float n);

void main(){
    float a=0, b=20;
    int n;
    puts("ingrese el numero de iteraciones");
    scanf("%d",&n);
    printf("El valor es: %f\n",mntaylor(a,b,n));

    FILE *gnuplot = popen("gnuplot -persist","w");
    fprintf(gnuplot,"unset label\n");
    fprintf(gnuplot,"set term png\n");
    fprintf(gnuplot,"set output 'taylor.png'\n");
    fprintf(gnuplot,"set xrange [%f:%f]\n",a,b);
    fprintf(gnuplot,"set yrange [%f:0.5] \n",mntaylor(a,b,n));
    fprintf(gnuplot,"set title 'Taylor'\n");
    fprintf(gnuplot,"set xlabel 't'\n");
    fprintf(gnuplot,"set ylabel 'y(t)'\n");
    fprintf(gnuplot,"set grid\n");
    fprintf(gnuplot,"unset key\n");
    fprintf(gnuplot,"plot 'taylor.txt' using 1:2 pt 1\n");
    fprintf(gnuplot,"set output\n");
    pclose(gnuplot);
}


float f(float t, float y){
    float res=0;
    res = y-pow(t,2)+1;
    return res;
}
float df(float t, float y){
    float res=0;
    res = f(t,y)-2*t;
    return res;
}

float politaylor(float t, float y, float h){
    float res=0;
    res = f(t,y)+h/2*df(t,y);
    return res;
}
float mntaylor(float a, float b, float n){
    float h,t,y;
    h=(b-a)/n;
    t=a;
    y=0.5;
    FILE *pf=fopen("taylor.txt","wt");
    for (int i = 0; i < n; i++)
    {
        fprintf(pf,"%.2f\t%.2f\n",t,y);
        y+=h*politaylor(t,y,h);
        t+=h;
    }
    fclose(pf);
    return y;
}