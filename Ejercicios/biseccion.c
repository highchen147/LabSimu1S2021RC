/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc biseccion.c -lm -o biseccion_cmd && ./biseccion_cmd
Fecha: Fri Apr 23 01:34:52 UTC 2021
Librerias: math.h
Resumen: Encontrar la raíz de una función gaussiana con el método de bisección
Entrada: 
Salida: Raíz de f(x)
*/

#include <stdio.h>
#include <math.h>

//Se define la función f(x)=e^(-x^2)-0.5
float f(float x){
    return exp(-0.5*(x*x))-0.5;
}

void main(void){
    float x0,xf;
    //se define el intervalo en donde se buscará la raíz
    x0 = 1;
    xf = 1.4;
    //se define xp y a xp1 como el punto medio de la interación anterior
    float xp = 0.5*(x0+xf),xp1;
    //Se define el error máximo como 100
    float error=100;
    //comienza el ciclo que deberá concluir cuando el error sea menor a 1%
    while (error > 0.1)
    {
        //se le asigna al valor final xf el valor medio xp si (f(x0)*f(xp)) < 0
        if ((f(x0)*f(xp)) < 0)
        {
            xf = xp;
        }
        //se le asigna al valor inicial x0 el valor medio xp si (f(x0)*f(xp)) > 0
        else if ((f(x0)*f(xp)) > 0)
        {
            x0 = xp;
        }else{
            break;
        }
        //se le asigna el valor anterior del valor medio a xp1
        xp1 = xp;
        //se calcula el nuevo valor medio
        xp = 0.5*(x0+xf);
        //se calcula el error relativo
        error = 100*fabs(xp-xp1)/xp;
    }
    //se imprime la raíz encontrada
    printf("\nLa raíz es %f\n", xp);
    /* con la función popen se abre un ejecutable llamado gnuplot para ejecutar los comandos en Gnuplot
    que nos servirá para graficar y generar el .tex
    */
    FILE *gnuplot = popen("gnuplot -persist","w");
    fprintf(gnuplot,"unset label\n");
    fprintf(gnuplot,"set terminal 'epslatex'\n");
    //se nomrba al archivo objetivo como grafica.tex
    fprintf(gnuplot,"set output 'grafica.tex'\n");
    fprintf(gnuplot,"set xrange [-3:3]\n");
    fprintf(gnuplot,"set yrange [-4:4]\n");
    fprintf(gnuplot,"set title 'Gráfica de la función'\n");
    fprintf(gnuplot,"set xlabel 'x'\n");
    fprintf(gnuplot,"set ylabel 'f(x)'\n");
    fprintf(gnuplot,"set grid\n");
    fprintf(gnuplot,"unset key\n");
    //se grafica la función
    fprintf(gnuplot,"f(x)=exp(-0.5*x**2)-0.5\n");
    fprintf(gnuplot,"unset key\n");
    fprintf(gnuplot,"plot f(x)\n");
    fprintf(gnuplot, "set  output\n");
    pclose(gnuplot);
    //creamos un archivo de texto que almacene el punto estimado de la raíz
    FILE *punto=fopen("punto.txt","w");
    fprintf(punto,"%f %f",xp,0.0);
    //se crea una nueva gráfica con acercamiento a la raíz estimada
    FILE *gnuzoom = popen("gnuplot -persist","w");
    fprintf(gnuzoom,"unset label\n");
    fprintf(gnuzoom,"set terminal 'epslatex'\n");
    fprintf(gnuzoom,"set output 'grafzoom.tex'\n");
    fprintf(gnuzoom,"set xrange [1.1765:1.1775]\n");
    fprintf(gnuzoom,"set yrange [-0.0005:0.0005]\n");
    fprintf(gnuzoom,"set title 'Raíz'\n");
    fprintf(gnuzoom,"set xlabel 'x'\n");
    fprintf(gnuzoom,"set ylabel 'f(x)'\n");
    fprintf(gnuzoom,"set grid\n");
    fprintf(gnuzoom,"unset key\n");
    fprintf(gnuzoom,"f(x)=exp(-0.5*x**2)-0.5\n");
    fprintf(gnuzoom,"unset key\n");
    fprintf(gnuzoom,"plot f(x), 'punto.txt' using 1:2\n");
    fprintf(gnuzoom, "set  output\n");
    fclose(punto);
    pclose(gnuzoom);
    
}