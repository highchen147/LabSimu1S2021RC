#!/bin/bash
rm leer
clima=$(curl wttr.in/Guatemala | head -7)
touch leer
echo $clima >> leer
cat leer
rm leer