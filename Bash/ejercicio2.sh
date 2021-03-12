#!/bin/bash
echo "escriba el nombre del archivo"
read nombre
if [[ -z "$nombre" ]]; then
    echo "No ingresó un nombre"
elif [[ -n "$nombre" ]]; then
    touch $nombre.c
    chmod +x $nombre.c
    echo "/*" >> $nombre.c
    echo "escriba el nombre del autor"
    read autor
    echo "Autor: $autor" >> $nombre.c
    echo "escriba el compilador"
    read compilador
    echo "Compilador: $compilador" >> $nombre.c
    echo "escriba como se debe compilar"
    read compilar
    echo "Compilado: $compilar" >> $nombre.c
    fecha=$(date)
    echo "Fecha: $fecha" >> $nombre.c
    echo "ingrese las librerias necesarias"
    read librerias
    echo "Librerias: $librerias" >> $nombre.c
    echo "ingrese el resumen del programa"
    read resumen
    echo "Resumen: $resumen" >> $nombre.c
    echo "ingrese la entrada"
    read entrada
    echo "Entrada: $entrada" >> $nombre.c
    echo "ingrese la salida"
    read salida
    echo "Salida: $salida" >> $nombre.c
    echo "*/" >> $nombre.c
    echo "" >> $nombre.c
    echo "//Librerias" >> $nombre.c
    echo "#include <stdio.h>" >> $nombre.c
    echo "//pasos del pseudocódigo" >> $nombre.c
fi