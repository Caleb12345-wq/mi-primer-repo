# Documentación del Proyecto

Este proyecto trata sobre crear tres opciones, de las cuales el usuario debera de elegir cualquiera de las opciones que se le mostrarán.
Las opciones que se le enseña al usuario son las siguientes:

* Menú: Esta no es una opción esto es un mensaje que se le enseñara al usuario donde le aparecera las siguientes opciones:

* Opción 1: Está opción muestra al usuario el factorial de un número positivo y le dará un resultado, no importando que número ingrese el usuario
  este calculará el resultado correspondiente.

* Opción 2: Esta opción muestra al usuario el subsidio de familia, pide la cantidad de hijos/as base según la cantidad, pero requiere un rango de edad entre 7 y 18 años.

* Opción 3: Por último esta opción solo es la salida del programa, el usuario tiene que elegir esta opción para dar salida del programa.

# Explicación de Algoritmos "Factorial" y "Subsidio de Familia".

## Algoritmos Factorial.

/ La opción factorial funciona de la siguiente manera:

* El programa pide al usuario que ingrese un número positivo.
* Inicializa una variable de ´factorial ´ en 1.
* Recorre todos los números desde 1 hasta el numero ingresado, multiplicando cada uno por ´Factorial´.
* Al finalizar. muestra el resultado del factorial al usuario.

  ** Pseudocódigo **
  Inicio
Pedir número entero positivo
factorial <- 1
Para i desde 1 hasta número
factorial <- factorial * i
Fin Para
Mostrar factorial
Fin.

## Algoritmo de "Subsidio de Familia".

/ La opción de Subsidio de familia funciona de la siguiente manera:

* El programa pide al usuario la cantidad de hijos/as que tenga.
* Determina el Subsidio base según la cantidad:
* 3 hijos/as -> Q.300.
* 4 a 5 hijos/as -> Q.400.
* Pide al Usuario hijos/as están entre 7 y 18 años.
* Calcula un extra el 6% del subsidio por cada hijo/a en ese rango.
* Muestra el total del subsidio incluyendo el extra.

  ** Pseudocódigo **
  Inicio
Pedir cantidad de hijos/as
Si hijos = 3 entonces
subsidio <- 300
Sino si hijos = 4 o hijos = 5 entonces
subsidio <- 350
Sino si hijos > 5 entonces
subsidio <- 400
Fin Si
Pedir cuántos hijos/as están entre 7 y 18 años
extra <- subsidio * 0.06 * cantidad_hijos_en_rango
total <- subsidio + extra
Mostrar total
Fin.

Gracias.
