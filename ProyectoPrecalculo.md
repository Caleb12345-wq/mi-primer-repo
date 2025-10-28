## Documentación del Programa: Cifrado César en Python
1. Objetivo del Programa

El programa implementa el Cifrado César, un método de cifrado clásico que consiste en desplazar cada letra del mensaje un número fijo de posiciones en el alfabeto.

Permite:

- Cifrar mensajes en mayúsculas y minúsculas.

- Descifrar mensajes usando la misma clave.

- Mantener espacios, símbolos y números sin modificar.

- Trabajar con mensajes de forma legible y ordenada.

## 2. Descripción del Algoritmo

Entrada del usuario:

- Opción: Cifrar (1) o Descifrar (2).

- Mensaje: texto a cifrar o descifrar.

- Clave: número entero que indica cuántas posiciones se desplaza cada letra.

## Proceso:

- Se recorre cada letra del mensaje.

- Se determina si es mayúscula o minúscula.

- Se calcula su nueva posición usando la fórmula:

- Para cifrar: se suma la clave a la posición original de la letra y se aplica módulo 26.

- Para descifrar: se resta la clave a la posición original de la letra y se aplica módulo 26.

- Si la letra no es del alfabeto, se mantiene igual.

- Se construye el mensaje final agregando cada letra transformada.

## Salida:

Muestra el mensaje cifrado o descifrado según la opción elegida.

3. Estructura del Programa
3.1 Definición de Variables y Listas de Letras

** Se definen tres variables principales **

// letras_mayus: contiene todas las letras del alfabeto en mayúscula.

// letras_minus: contiene todas las letras del alfabeto en minúscula.

// resultado: donde se almacenará el mensaje cifrado o descifrado.

## 3.2 Menú de Opciones

Se muestra un menú en pantalla para que el usuario elija si desea cifrar o descifrar un mensaje.

- Se valida la opción para asegurar que sea válida (1 o 2).

## 3.3 Lectura de Mensaje y Clave

Si la opción es válida, el programa solicita al usuario:

// El mensaje a cifrar o descifrar.

// La clave (entero), que se normaliza usando módulo 26 para que siempre esté dentro del alfabeto.

## 3.4 Proceso de Cifrado/Descifrado

El programa recorre cada letra del mensaje:

// Determina si la letra es mayúscula o minúscula.

// Encuentra la posición de la letra dentro del alfabeto correspondiente.

// Calcula la nueva posición según la opción seleccionada (cifrar o descifrar) aplicando módulo 26.

// Si la letra no pertenece al alfabeto (espacio, número o símbolo), se mantiene igual.

// Agrega la letra transformada al resultado final.

// El proceso respeta la capitalización original y conserva todos los espacios y caracteres especiales.

## 3.5 Resultado Final

- Al terminar de procesar todas las letras:

- Si el usuario eligió cifrar, se muestra el mensaje cifrado.

- Si eligió descifrar, se muestra el mensaje descifrado.
- El resultado se presenta completo y legible, respetando mayúsculas, minúsculas y espacios.

## 4. Ejemplo de Ejecución

Entrada:

Opción: 1 (Cifrar)

Mensaje: “Hola me llamo Marcos”

Clave: 10

Salida:

Mensaje cifrado: “Ryvk wo vvkwy Wkbsyc”

Entrada para Descifrado:

Opción: 2

Mensaje: “Ryvk wo vvkwy Wkbsyc”

Clave: 10

Salida:

Mensaje descifrado: “Hola me llamo Marcos”

## 5. Comentarios Finales

El programa mantiene la legibilidad del mensaje, respetando mayúsculas, minúsculas, espacios y símbolos.

Opción para cifrar o descifrar múltiples mensajes consecutivos.

La implementación en Python permite reutilizar la función de cifrado/descifrado fácilmente en otros proyectos o aplicaciones.
