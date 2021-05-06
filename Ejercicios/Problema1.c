/*
Autor: Rodrigo Castillo
Compilador: gcc
Compilado: gcc
Fecha: Mon Apr 19 22:45:10 UTC 2021
Librerias: 
Resumen: Mostrar vector de n10 números pares ascendente y descendentemente
Entrada: Modo de mostrar el vector
Salida: Vector ordenado
*/

//Librerias
#include <stdio.h>

void main(void){
    //usamos un while para que el programa sea utilizado las veces que el usuario lo desee
    while (1){
        //definimos a x como la variable que almacena el modo de desplegar los vectores
        char x;
        //definimos el vector a mostrar
        int a[10]={2,4,6,8,10,12,14,16,18,20};
        //pedimos que el usuario ingrese el modo de desplegue
        printf("Ingrese a si desea ver el vector en forma ascendente y d en forma descendente. Presione cualquier otro caracter para salir. \n");
        scanf("%s",&x);
        //utilizamos un switch para que alterne entre el estado ascendente, a, y el descendente, d.
        switch (x)
        {
        case 'a':
            for (int i = 0; i < 10; i++)
            {
                //desplegamos el vector ascendentemente con un for que va de 0 a 9
                printf("%d \n",a[i]);
            }
            break;
        case 'd':
            for (int i = 9; i >= 0; i--)
            {
                //desplegamos el vector descendentemente con un for en forma regresiva, de 9 a 0
                printf("%d \n",a[i]);
            }
            break;
        default:
            //en caso el usuario no ingrese 'a' ni 'd', el programa termina
            return;
            break;
        }
    }
}