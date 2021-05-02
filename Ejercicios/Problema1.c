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
//pasos del pseudocódigo

void main(void){
    while (1){
        char x;
        int a[10]={2,4,6,8,10,12,14,16,18,20};
        printf("Ingrese a si desea ver el vector en forma ascendente y d en forma descendente. Presione cualquier otro caracter para salir. \n");
        scanf("%s",&x);
        switch (x)
        {
        case 'a':
            for (int i = 0; i < 10; i++)
            {
                printf("%d \n",a[i]);
            }
            break;
        case 'd':
            for (int i = 9; i >= 0; i--)
            {
                printf("%d \n",a[i]);
            }
            break;
        default:
            return;
            break;
        }
    }
}