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
//se define el número de datos
int n=6;
//se define la función que suma todos los números de un arreglo
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
//se define la función que suma la multiplicación de dos elementos de un arreglo diferente cada uno
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
    //se definen dos listas, una para la velocidad (v) y otra para el tiempo (t)
    //se define sv para la incerteza de cada valor de v, st para la incerteza de los valores t
    float v[6]={1,3,8,11,14,18};
    float sv[6];
    float t[6]={2.1,3.0,5.2,7.1,9.2,10.1};
    float st[6]={0.1,0.1,0.1,0.1,0.1,0.1};
    //se define m para la pendiente y b para el intercepto en y
    //se define sm para la incerteza de m, sb para la incerteza de b
    //se define r para el coeficiente de correlación
    float m,b,sm,sb,r;
    //se calcula la pendiente
    m = (n*sum2(v,t)-sum1(v)*sum1(t))/(n*sum2(t,t)-(sum1(t)*sum1(t)));
    //se calcula el intercepto en y
    b = (sum1(v)-m*sum1(t))/(n);
    //se calcula la incerteza en la pendiente
    sm = 0.1*sqrt(n)/sqrt(n*sum2(t,t)-sum1(t)*sum1(t));
    //se calcula la incerteza en el intercepto en y
    sb = 0.1/sqrt(n);
    //se calcula el coeficiente de correlación
    r = (n*sum2(v,t)-sum1(v)*sum1(t))/sqrt((n*sum2(t,t)-sum1(t)*sum1(t))*(n*sum2(v,v)-sum1(v)*sum1(v)));
    //se imprimen los resultados
    printf("La aceleración es %f +/- %f\n",m,sm);
    printf("La velocidad a los 15 segundos es %f +/- %f m/s\n",m*15+b,m*0.1);
    printf("El coeficiente de correlación es %f\n",r);
    /*
    Ahora que ya se tiene la pendiente, se calculan las incertezas en los valores de la velocidad, 
    multiplicando 0.1 por la pendiente encontrada.
    */
    for (int i = 0; i < 6; i++)
    {
        sv[i]=m*0.1;
    }
    //se abre un archivo en donde se almacenarán los valores v,t y sus incertezas
    FILE *datosplot = fopen("data.txt", "w");
    //se escriben los valores en el documento txt para luego ser graficados
    for (int i = 0; i < 6; i++)
    {
        fprintf(datosplot,"%f %f %f %f\n",t[i],st[i],v[i],sv[i]);
    }
    /* con la función popen se abre un ejecutable llamado gnuplot para ejecutar los comandos en Gnuplot
    que nos servirá para graficar y generar el .tex
    */
    FILE *gnuplot = popen("gnuplot -persist","w");
    fprintf(gnuplot,"unset label\n");
    fprintf(gnuplot,"set terminal 'epslatex'\n");
    //se nomrba al archivo objetivo como graf.tex
    fprintf(gnuplot,"set output 'graf.tex'\n");
    //establecemos un rango adecuado a los datos proporcionados
    fprintf(gnuplot,"set xrange [0:12]\n");
    fprintf(gnuplot,"set yrange [0:20]\n");
    fprintf(gnuplot,"set title 'Velocidad - Tiempo'\n");
    fprintf(gnuplot,"set xlabel 't'\n");
    fprintf(gnuplot,"set ylabel 'v(t)'\n");
    fprintf(gnuplot,"set grid\n");
    fprintf(gnuplot,"unset key\n");
    fprintf(gnuplot,"m=%f\n",m);
    fprintf(gnuplot,"b=%f\n",b);
    fprintf(gnuplot,"f(x)=m*x+b\n");
    fprintf(gnuplot,"unset key\n");
    //se grafica la función lineal con los valores encontrados para m y b, así como la tabla de datos con incertezas
    fprintf(gnuplot,"plot f(x), 'data.txt' using 1:3:2:4 with xyerrorbars pt 3\n");
    fprintf(gnuplot, "set  output\n");
    //se cierran los archivos, el ejecutable y el de texto
    fclose(datosplot);
    pclose(gnuplot);
}