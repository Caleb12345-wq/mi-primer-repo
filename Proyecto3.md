## Documentación del Proyecto – Sistema de Gestión de Productos

## Descripción general

Este programa permite gestionar productos de una tienda o inventario mediante operaciones básicas como agregar, buscar, modificar y eliminar registros.
Toda la información se guarda en un archivo de texto llamado “productos.txt”, utilizando el formato delimitado por punto y coma (;).

 ## Funciones principales

## agregarProducto()

// Permite ingresar un nuevo producto con los siguientes datos:
código, nombre, proveedor, precio, existencia, estado y descuento.

// Verifica que el código no esté repetido antes de agregarlo.

// Guarda automáticamente el producto en el archivo de texto.

## buscarProducto()

// Permite buscar productos por código exacto o por palabra clave en el nombre.

// Muestra la información completa del producto si lo encuentra.

## modificarProducto()

// Permite actualizar los datos de un producto existente, identificado por su código.

// Una vez modificados los datos, sobrescribe el archivo con la nueva información.

## eliminarProducto()

// Permite eliminar un producto del inventario.

// Pide confirmación antes de borrarlo definitivamente.

// El archivo se actualiza automáticamente después de la eliminación.

## cargarProductos() y guardarProductos()

// Se encargan de leer y escribir los datos en el archivo productos.txt.

// Usan stringstream para convertir los datos entre texto y números.
Lógica general del programa

// Al iniciar, se cargan los productos existentes desde el archivo.

Se muestra un menú con opciones del 1 al 5.

Cada acción actualiza el vector productos y el archivo de texto.

El programa se repite hasta que el usuario seleccione “Salir”.

-- Menú principal --
1. Agregar Producto
2. Buscar Producto
3. Modificar Producto
4. Eliminar Producto
5. Salir

Gracias.



Se encargan de leer y escribir los datos en el archivo productos.txt.

Usan stringstream para convertir los datos entre texto y números.
