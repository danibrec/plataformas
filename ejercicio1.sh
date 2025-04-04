#!/bin/bash
if [ "$UID" -ne 0 ]; then
    echo "Error: Este script debe ser ejecutado como root."
    exit 1
fi
Usuario="$1"
Grupo="$2"
archivo="$3"
if [ ! -f "$archivo" ]; then
    echo "Error: El archivo '$archivo' no existe."
    exit 1
fi
if ! getent group "$Grupo" > /dev/null; then
    echo "El grupo '$Grupo' no existe, procederemos a crearlo."
    sudo addgroup "$Grupo" || { echo "Error al crear el grupo."; exit 1; }
else
    echo "El grupo '$Grupo' ya existe."
fi
if ! id "$Usuario" > /dev/null 2>&1; then
    echo "El usuario '$Usuario' no existe, vamos a crearlo e ingresarlo al grupo."
    sudo useradd -m -g "$Grupo" "$Usuario" || { echo "Error al crear el usuario."; exit 1; }
else
    echo "El usuario '$Usuario' ya existe, lo ingresaremos al grupo."
    sudo usermod -aG "$Grupo" "$Usuario" || { echo "Error al agregar el usuario al grupo."; exit 1; }
fi
echo "Cambiando la propiedad del archivo '$archivo' al usuario '$Usuario' y grupo '$Grupo'."
sudo chown "$Usuario:$Grupo" "$archivo" || { echo "Error al cambiar la propiedad del archivo."; exit 1; }
chmod 777 "$archivo" || { echo "Error al modificar los permisos del archivo."; exit 1; }
echo "Operaciones completadas exitosamente."

chmod 750 "$archivo"

echo "Se modificaron los permisos del archivo"


