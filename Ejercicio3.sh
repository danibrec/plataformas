#!/bin/bash
directorio="/mnt/c/Users/dbren/Downloads"
log="/mnt/c/Users/dbren/Downloads/Recuento.txt"

echo "Monitoreando el directorio: $directorio"
while true; do
    Monitoreo=$(inotifywait -e create -e modify -e delete --format '%w%f %e' "$directorio")
    Fecha_de_cambio=$(date '+%Y-%m-%d %H:%M:%S')
    echo "$Fecha_de_cambio - $Monitoreo" >> "$log"
done
