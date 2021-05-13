/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc final.c -lm
Fecha: Thur May 13 10:06:52 CST 2021
Librerias: stdio.h math.h
Resumen: Final
Entrada: 
Salida: 
*/
//Librerias
#include <stdio.h>
#include <math.h>
//definir constantes globales
#define G (6.693*pow(10,-11))
#define Rt 6.378*pow(10,6)
#define Mt 5.9736*pow(10,24)
#define R 287.06
#define L (6.5*pow(10,-3))
#define go 9.81
#define To 288.15
#define Po 101325
//declarar funciones principales dependientes del tiempo
float mf(float t, float TSFC, float Eo, float mfo);
float mc(float mo, float mf);
float E(float mf, float Eo);
//declarar funciones que dependen de la altura y
float g(float y);
float rho(float y);
float Fa(float rho, float CD, float A, float dy);

void main(void){
    //cohete ah mun
    float Eo=3*pow(10,7);
    float TSFC=3.248*pow(10,-4);
    float CD=61.27;
    float A=201.06;
    float mo=1.1*pow(10,5);
    float mfo=1.5*pow(10,6);
    //velocidad inicial = 0
    float dy=0;
    //posición inicial = 66 cm = 0.66 m
    float y=66*pow(10,-2);
    //tiempo inicial = 0
    float t=0;
    //aceleración
    float a;
    //utilizaremos la variable banAlt como bandera para indicar que se encontró la altura máxima
    int banAlt=0;
    float amax;
    //la variable banCom es la bandera que indica que se encontró el tiempo en el cual se acabó el combustible
    int banCom=0;
    //Comienza el cálculo de Ah mun
    printf("Cohete Ah Mun\n");
    printf("Empuje E0: %.2f E %d\n",3.0,7);
    printf("Consumo específico TSFC: %.2f E %d\n",3.248,-4);
    printf("Coeficiente de forma CD: %.2f\n",61.27);
    printf("Sección transversal del cohete: %.2f\n",201.6);
    printf("Masa del propulsor: %.2f E %d\n",1.1,5);
    printf("Masa inicial del combustible: %.2f E %d\n",1.5,6);
    //abrimos el archivo donde irán los datos
    FILE *pf =fopen("datos","wt");
    //creamos el ciclo while
    while ((round(y)!=0))
    {   
        //ingresamos los datos en el orden: tiempo  altura  velocidad
        fprintf(pf,"%.2f\t%.2f\t%.2f\n",t,y,dy);
        //se calcula la aceleración
        a=(E(mf(t,TSFC,Eo,mfo),Eo)-Fa(rho(y),CD,A,dy))/mc(mo,mf(t,TSFC,Eo,mfo))-g(y);
        //se calcula la velocidad según v=v0+aceleración*delta(t), con delta(t)=0.1
        dy+=a*0.1;
        //se calcula la altura según y=y0+velocidad*delta(t)
        y+=dy*0.1;
        t+=0.1;
        if (y>0 && round(dy)==0 && banAlt==0)
        {
            amax=y;
            printf("La altura máxima es: %0.2f metros\n",amax);
            //cambiamos la bandera
            banAlt = 1;
        }
        if (mf(t,TSFC,Eo,mfo) == 0 && banCom==0)
        {
            printf("El combustible se acabó a los %0.2f segundos\n", t);
            //cambiamos la bandera
            banCom = 1;
        }
    }
    fprintf(pf,"%.2f\t%.2f\t%.2f\n",t,y,dy);
    //cerramos el archivo
    fclose(pf);
    //convertimos a minutos
    int min=t/60;
    printf("El impacto se dio a los %0.2f minutos\n*\n*\n", (float)min + (t/60-(float)min)*60/100);
    //creamos la gráfica tiempo - altura con gnuplot en un png
    FILE *gnuplot = popen("gnuplot -persist","w");
    fprintf(gnuplot,"unset label\n");
    fprintf(gnuplot,"set term png\n");
    fprintf(gnuplot,"set output 'AhMunTiempoAltura.png'\n");
    fprintf(gnuplot,"set xrange [0:%f]\n",t);
    fprintf(gnuplot,"set yrange [0:%f]\n",amax);
    fprintf(gnuplot,"set title 'Tiempo - altura de Ah Mun'\n");
    fprintf(gnuplot,"set xlabel 't'\n");
    fprintf(gnuplot,"set ylabel 'y(t)'\n");
    fprintf(gnuplot,"set grid\n");
    fprintf(gnuplot,"unset key\n");
    //graficamos la primera columna de los datos (el tiempo) y la segunda columna (la altura)
    fprintf(gnuplot,"plot 'datos' using 1:2 pt 0.1\n");
    fprintf(gnuplot,"set output\n");
    //graficamos con gnuplot la gráfica velocidad -
    fprintf(gnuplot,"unset label\n");
    fprintf(gnuplot,"set term png\n");
    fprintf(gnuplot,"set output 'AhMunTiempoVelocidad.png'\n");
    fprintf(gnuplot,"set xrange [0:%f]\n",t);
    fprintf(gnuplot,"set yrange [-30:140]\n");
    fprintf(gnuplot,"set title 'Tiempo - Velocidad de Ah Mun'\n");
    fprintf(gnuplot,"set xlabel 't'\n");
    fprintf(gnuplot,"set ylabel 'v(t)'\n");
    fprintf(gnuplot,"set grid\n");
    fprintf(gnuplot,"unset key\n");
    //graficamos la primera columna de los datos (el tiempo) y la tercera columna (la velocidad)
    fprintf(gnuplot,"plot 'datos' using 1:3 pt 0.1\n");
    fprintf(gnuplot,"set output\n");
    //graficamos velocidad vs altura de Ah Mun
    fprintf(gnuplot,"unset label\n");
    fprintf(gnuplot,"set term png\n");
    fprintf(gnuplot,"set output 'AhMunVelocidadAltura.png'\n");
    fprintf(gnuplot,"set xrange [-30:140]\n");
    fprintf(gnuplot,"set yrange [0:%f]\n",amax);
    fprintf(gnuplot,"set title 'Velocidad - Altura de Ah Mun'\n");
    fprintf(gnuplot,"set xlabel 'v'\n");
    fprintf(gnuplot,"set ylabel 'y'\n");
    fprintf(gnuplot,"set grid\n");
    fprintf(gnuplot,"unset key\n");
    //graficamos la primera columna de los datos (el tiempo) y la tercera columna (la velocidad)
    fprintf(gnuplot,"plot 'datos' using 3:2 pt 0.1\n");
    fprintf(gnuplot,"set output\n");
    pclose(gnuplot);
    //
    //Termina el cálculo de Ah mun
    //
    //Comienza el cálculo de Ahau Kin
    Eo=2.7*pow(10,7);
    TSFC=2.248*pow(10,-4);
    CD=61.27;
    A=201.06;
    mo=1.1*pow(10,5);
    mfo=1.5*pow(10,6);
    //velocidad inicial = 0
    dy=0;
    //posición inicial = 66 cm = 0.66 m
    y=66*pow(10,-2);
    //tiempo inicial = 0
    t=0;
    //aceleración
    a;
    //utilizaremos la variable banAlt como bandera para indicar que se encontró la altura máxima
    banAlt=0;
    amax;
    //la variable banCom es la bandera que indica que se encontró el tiempo en el cual se acabó el combustible
    banCom=0;
    //Comienza el cálculo de Ahau Kin
    printf("Cohete Ahau Kin\n");
    printf("Empuje E0: %.2f E %d\n",2.7,7);
    printf("Consumo específico TSFC: %.2f E %d\n",2.248,-4);
    printf("Coeficiente de forma CD: %.2f\n",61.27);
    printf("Sección transversal del cohete: %.2f\n",201.6);
    printf("Masa del propulsor: %.2f E %d\n",1.1,5);
    printf("Masa inicial del combustible: %.2f E %d\n",1.5,6);
    //abrimos el archivo donde irán los datos
    FILE *pf2 =fopen("datos2","wt");
    //creamos el ciclo while
    while ((round(y)!=0))
    {   
        //ingresamos los datos en el orden: tiempo  altura  velocidad
        fprintf(pf2,"%.2f\t%.2f\t%.2f\n",t,y,dy);
        //se calcula la aceleración
        a=(E(mf(t,TSFC,Eo,mfo),Eo)-Fa(rho(y),CD,A,dy))/mc(mo,mf(t,TSFC,Eo,mfo))-g(y);
        //se calcula la velocidad según v=v0+aceleración*delta(t), con delta(t)=0.1
        dy+=a*0.1;
        //se calcula la altura según y=y0+velocidad*delta(t)
        y+=dy*0.1;
        t+=0.1;
        if (y>0 && round(dy)==0 && banAlt==0)
        {
            amax=y;
            printf("La altura máxima es: %0.2f metros\n",amax);
            //cambiamos la bandera
            banAlt = 1;
        }
        if (mf(t,TSFC,Eo,mfo) == 0 && banCom==0)
        {
            printf("El combustible se acabó a los %0.2f segundos\n", t);
            //cambiamos la bandera
            banCom = 1;
        }
    }
    fprintf(pf2,"%.2f\t%.2f\t%.2f\n",t,y,dy);
    //cerramos el archivo
    fclose(pf2);
    min=t/60;
    printf("El impacto se dio a los %0.2f minutos\n*\n*\n", (float)min + (t/60-(float)min)*60/100);
    FILE *g2 = popen("gnuplot -persist","w");
    fprintf(g2,"unset label\n");
    fprintf(g2,"set term png\n");
    fprintf(g2,"set output 'AhauKinTiempoAltura.png'\n");
    fprintf(g2,"set xrange [0:%f]\n",t);
    fprintf(g2,"set yrange [0:%f]\n",amax);
    fprintf(g2,"set title 'Tiempo - altura de Ahau kin'\n");
    fprintf(g2,"set xlabel 't'\n");
    fprintf(g2,"set ylabel 'y(t)'\n");
    fprintf(g2,"set grid\n");
    fprintf(g2,"unset key\n");
    //graficamos la primera columna de los datos (el tiempo) y la segunda columna (la altura)
    fprintf(g2,"plot 'datos2' using 1:2 pt 0.1\n");
    fprintf(g2,"set output\n");
    //graficamos con gnuplot la gráfica velocidad - tiempo
    fprintf(g2,"unset label\n");
    fprintf(g2,"set term png\n");
    fprintf(g2,"set output 'AhauKinTiempoVelocidad.png'\n");
    fprintf(g2,"set xrange [0:%f]\n",t);
    fprintf(g2,"set yrange [-160:510]\n");
    fprintf(g2,"set title 'Tiempo - Velocidad de Ah Mun'\n");
    fprintf(g2,"set xlabel 't'\n");
    fprintf(g2,"set ylabel 'v(t)'\n");
    fprintf(g2,"set grid\n");
    fprintf(g2,"unset key\n");
    //graficamos la primera columna de los datos (el tiempo) y la tercera columna (la velocidad)
    fprintf(g2,"plot 'datos2' using 1:3 pt 0.1\n");
    fprintf(g2,"set output\n");
    //graficamos velocidad vs altura de Ahau Kin
    fprintf(g2,"unset label\n");
    fprintf(g2,"set term png\n");
    fprintf(g2,"set output 'AhauKinVelocidadAltura.png'\n");
    fprintf(g2,"set xrange [-160:510]\n");
    fprintf(g2,"set yrange [0:%f]\n",amax);
    fprintf(g2,"set title 'Velocidad - Altura de Ah Mun'\n");
    fprintf(g2,"set xlabel 'v'\n");
    fprintf(g2,"set ylabel 'y'\n");
    fprintf(g2,"set grid\n");
    fprintf(g2,"unset key\n");
    //graficamos la tercera columna de los datos (la velocidad) y la tercera columna (la altura)
    fprintf(g2,"plot 'datos2' using 3:2 pt 0.1\n");
    fprintf(g2,"set output\n");
    pclose(g2);
    //
    //Termina el cálculo de Ahau Kin
    //
    //Comienza el cálculo de Chac
    Eo=2.5*pow(10,7);
    TSFC=2.248*pow(10,-4);
    CD=70.25;
    A=215.00;
    mo=1.8*pow(10,5);
    mfo=2.1*pow(10,6);
    //velocidad inicial = 0
    dy=0;
    //posición inicial = 66 cm = 0.66 m
    y=66*pow(10,-2);
    //tiempo inicial = 0
    t=0;
    //aceleración
    a;
    //utilizaremos la variable banAlt como bandera para indicar que se encontró la altura máxima
    banAlt=0;
    amax;
    //la variable banCom es la bandera que indica que se encontró el tiempo en el cual se acabó el combustible
    banCom=0;
    //Comienza el cálculo de Chac
    printf("Cohete Chac\n");
    printf("Empuje E0: %.2f E %d\n",2.5,7);
    printf("Consumo específico TSFC: %.2f E %d\n",2.248,-4);
    printf("Coeficiente de forma CD: %.2f\n",70.25);
    printf("Sección transversal del cohete: %.2f\n",215.00);
    printf("Masa del propulsor: %.2f E %d\n",1.8,5);
    printf("Masa inicial del combustible: %.2f E %d\n",2.1,6);
    //abrimos el archivo donde irán los datos
    FILE *pf3 =fopen("datos3","wt");
    //creamos el ciclo while
        while ((round(y)!=0))
    {   
        //ingresamos los datos en el orden: tiempo  altura  velocidad
        fprintf(pf3,"%.2f\t%.2f\t%.2f\n",t,y,dy);
        //se calcula la aceleración
        a=(E(mf(t,TSFC,Eo,mfo),Eo)-Fa(rho(y),CD,A,dy))/mc(mo,mf(t,TSFC,Eo,mfo))-g(y);
        //se calcula la velocidad según v=v0+aceleración*delta(t), con delta(t)=0.1
        dy+=a*0.1;
        //se calcula la altura según y=y0+velocidad*delta(t)
        y+=dy*0.1;
        t+=0.1;
        if (y>1 && round(dy)==0 && banAlt==0)
        {
            amax=y;
            printf("La altura máxima es: %0.2f metros\n",amax);
            //cambiamos la bandera
            banAlt = 1;
        }
        if (mf(t,TSFC,Eo,mfo) == 0 && banCom==0)
        {
            printf("El combustible se acabó a los %0.2f segundos\n", t);
            //cambiamos la bandera
            banCom = 1;
        }
    }
    fprintf(pf3,"%.2f\t%.2f\t%.2f\n",t,y,dy);
    //cerramos el archivo
    fclose(pf3);
    min=t/60;
    printf("El impacto se dio a los %0.2f minutos\n*\n*\n", (float)min + (t/60-(float)min)*60/100);
    FILE *g3 = popen("gnuplot -persist","w");
    //graficamos con gnuplot altura tiempo
    fprintf(g3,"unset label\n");
    fprintf(g3,"set term png\n");
    fprintf(g3,"set output 'ChacTiempoAltura.png'\n");
    fprintf(g3,"set xrange [0:%f]\n",t);
    fprintf(g3,"set yrange [0:%f]\n",amax);
    fprintf(g3,"set title 'Tiempo - altura de Chac'\n");
    fprintf(g3,"set xlabel 't'\n");
    fprintf(g3,"set ylabel 'y(t)'\n");
    fprintf(g3,"set grid\n");
    fprintf(g3,"unset key\n");
    //graficamos la primera columna de los datos (el tiempo) y la segunda columna (la altura)
    fprintf(g3,"plot 'datos3' using 1:2 pt 0.1\n");
    fprintf(g3,"set output\n");
    //graficamos con gnuplot la gráfica velocidad - tiempo
    fprintf(g3,"unset label\n");
    fprintf(g3,"set term png\n");
    fprintf(g3,"set output 'ChacTiempoVelocidad.png'\n");
    fprintf(g3,"set xrange [0:%f]\n",t);
    fprintf(g3,"set yrange [-2500:2400]\n");
    fprintf(g3,"set title 'Tiempo - Velocidad de Chac'\n");
    fprintf(g3,"set xlabel 't'\n");
    fprintf(g3,"set ylabel 'v(t)'\n");
    fprintf(g3,"set grid\n");
    fprintf(g3,"unset key\n");
    //graficamos la primera columna de los datos (el tiempo) y la tercera columna (la velocidad)
    fprintf(g3,"plot 'datos3' using 1:3 pt 0.1\n");
    fprintf(g3,"set output\n");
    //graficamos velocidad altura
    fprintf(g3,"unset label\n");
    fprintf(g3,"set term png\n");
    fprintf(g3,"set output 'ChacVelocidadAltura.png'\n");
    fprintf(g3,"set xrange [-2500:2400]\n");
    fprintf(g3,"set yrange [0:%f]\n",amax);
    fprintf(g3,"set title 'Velocidad - Altura de Chac'\n");
    fprintf(g3,"set xlabel 'v'\n");
    fprintf(g3,"set ylabel 'y'\n");
    fprintf(g3,"set grid\n");
    fprintf(g3,"unset key\n");
    //graficamos la tercera columna de los datos (la velocidad) y la tercera columna (la altura)
    fprintf(g3,"plot 'datos3' using 3:2 pt 0.1\n");
    fprintf(g3,"set output\n");
    pclose(g3);
}


//definir las funciones dependientes del tiempo
//definir la masa variante mf
float mf(float t, float TSFC, float Eo, float mfo){
    /*la masa mf se acaba cuando mfo - TSFC*Eo*t es igual a 0
    por lo tanto cuando esto se cumpla, o sea menor a 0, debe
    retornar 0 dado que la masa se acabó */
    if ((mfo - TSFC*Eo*t) <= 0)
    {
        return 0;
    }else
    {
        return mfo - TSFC*Eo*t;
    }
}
//definir la masa total
float mc(float mo, float mf){
    return mo+mf;
}
//definir el empuje E
float E(float mf, float Eo){
    if (mf == 0)
    {
        return 0;
    }else
    {
        return Eo;
    }
}
//definir funciones dependientes de y
//definir fuerza de gravedad
float g(float y){
    float res =  (G*Mt)/pow(Rt+y,2);
    return res;
}
//definir densidad 
float rho(float y){
    /*Para alturas mayores a To/L, la densidad se vuelve cero*/
    if (y >= (To/L))
    {
        return 0;
    }else
    {
        float res;
        res = (Po/(R*To))*pow((1-(L*y)/To),go/(R*L));
        return res;
    }
}
//definir fricción
float Fa(float rho, float CD, float A, float dy){
    float res;
    res = 0.5*rho*CD*A*dy*fabs(dy);
    return res;
}
