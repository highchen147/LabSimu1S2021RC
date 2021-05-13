/*
Autor:    Maynor Ballina
Fecha:  Fri May 7 11:40:22 CST 2021
compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para Compilar: gcc -o metodoEuler metodoEuler.c
Version: 1.0
librerias: stdio (u otras)
Resumen:
*/

//Librerias
#include <stdio.h>
#include <math.h>
//Declaracion e inicializacion de variables globales
float df(float A, float K, float h);

void main(){
    float Area=1, K=0.1, h=10, t=0, delta=0.1, tm=0, hm=10;
    FILE *pf =fopen("altura","wt");
    while (h>=0)
    {
        //validando el valor de la altura cuando se cumple la condicion de los 3 segundos
        if (round(t)==3.0)
        {
            printf ("\n La altura en %f segundos es de: %f \n",t,h);
        }
        //Ingresando el valor de los datos en mi archivo
        fprintf(pf,"%.2f\t%.2f\n",t,h);
        //ejecutar el metodo numerico
        h+=delta*df(Area,K,h);
        t+=delta;
        hm+=0.5*delta*(df(Area,K,hm)+df(Area,K,hm+df(Area,K,hm)));
        tm+=delta;
    }
    //Ingresando el ultimo valor de los datos en mi archivo
    fprintf(pf,"%.2f\t%.2f\n",t,h);
    //cerrar archivo
    fclose(pf);
    printf ("\n el tiempo cuando h=0 es de: %f \n",t); 
    printf("\nCon euler mejorado, el tiempo cuando h=0 es: %f \n",tm);

    FILE *gnuplot = popen("gnuplot -persist","w");
    fprintf(gnuplot,"unset label\n");
    fprintf(gnuplot,"set term png\n");
    fprintf(gnuplot,"set output 'euler.png'\n");
    fprintf(gnuplot,"set xrange [0:65]\n");
    fprintf(gnuplot,"set yrange [0:10]\n");
    fprintf(gnuplot,"set title 'Euler'\n");
    fprintf(gnuplot,"set xlabel 't'\n");
    fprintf(gnuplot,"set ylabel 'h(t)'\n");
    fprintf(gnuplot,"set grid\n");
    fprintf(gnuplot,"unset key\n");
    fprintf(gnuplot,"plot 'altura' using 1:2 pt 0.5\n");
    fprintf(gnuplot,"set output\n");
    pclose(gnuplot);
}

float df(float A, float K, float h){
    float rep;
    rep = -(K*sqrt(h))/A;
    return rep;
}