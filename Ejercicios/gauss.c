#include <stdio.h>
void main(void){
    FILE *gnuplot = popen("gnuplot -persist","w");
    fprintf(gnuplot,"unset label\n");
    fprintf(gnuplot,"set terminal 'epslatex'\n");
    fprintf(gnuplot,"set output 'graficazoom.tex'\n");
    fprintf(gnuplot,"set xrange [0:2]\n");
    fprintf(gnuplot,"set yrange [-0.5:0.5]\n");
    fprintf(gnuplot,"set title 'Gráfica de la función'\n");
    fprintf(gnuplot,"set xlabel 'x'\n");
    fprintf(gnuplot,"set ylabel 'f(x)'\n");
    fprintf(gnuplot,"set grid\n");
    fprintf(gnuplot,"unset key\n");
    fprintf(gnuplot,"f(x)=exp(-0.5*x**2)-0.5\n");
    fprintf(gnuplot,"unset key\n");
    fprintf(gnuplot,"plot f(x)\n");
    fprintf(gnuplot, "set  output\n");
    pclose(gnuplot);
}