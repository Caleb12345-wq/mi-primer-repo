class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.izquierda = None
        self.derecha = None

class ArbolBinario:
    def __init__(self):
        self.raiz = None

    def insertar(self, dato):
        if self.raiz is None:
            self.raiz = Nodo(dato)

        else:
            self._insertar_recursivo(self.raiz, dato)

    def _insertar_recursivo(self, nodo_actual, dato):
        if dato < nodo_actual.dato:
            if nodo_actual.izquierda is None:
                nodo_actual.izquierda = Nodo(dato)
            else:
                self._insertar_recursivo(nodo_actual.izquierda, dato)
        elif dato > nodo_actual.dato:
            if nodo_actual.derecha is None:
                nodo_actual.derecha = Nodo(dato)
            else:
                self._insertar_recursivo(nodo_actual.derecha, dato)
        else:
            print(f"El valor {dato} ya existe en el árbol.")

    def buscar(self, dato):
        return self._buscar_recursivo(self.raiz, dato)

    def _buscar_recursivo(self, nodo_actual, dato):
        if nodo_actual is None:
            return False
        if dato == nodo_actual.dato:
            return True
        elif dato < nodo_actual.dato:
            return self._buscar_recursivo(nodo_actual.izquierda, dato)
        else:
            return self._buscar_recursivo(nodo_actual.derecha, dato)

    def preorden(self, nodo):
        if nodo is not None:
            print(nodo.dato, end=" ")
            self.preorden(nodo.izquierda)
            self.preorden(nodo.derecha)

    def inorden(self, nodo):
        if nodo is not None:
            self.inorden(nodo.izquierda)
            print(nodo.dato, end=" ")
            self.inorden(nodo.derecha)

    def postorden(self, nodo):
        if nodo is not None:
            self.postorden(nodo.izquierda)
            self.postorden(nodo.derecha)
            print(nodo.dato, end=" ")
            
def menu():
    arbol = ArbolBinario()

    while True:
        print("\n----- Menú Árbol Binario ---")
        print("1. insertar dato")
        print("2. Buscar dato")
        print("3. Buscar recorrido Preorden")
        print("4. Buscar recorrido Inorden")
        print("5. Buscar recorrido Postorden")
        print("Salir del programa")
        opcion = input("Seleccione una Opción: ")

        if opcion == "1":
            valor = int(input("Ingrese el valor a insertar: "))
            arbol.insertar(valor)
            print(f"Valor {valor} insertado correctamente.")

        elif opcion == "2":
            valor = int(input("Ingrese el valor a buscar: "))
            encontrado = arbol.buscar(valor)
            if encontrado:
                print(f" El valor {valor} Sí se encuentra en el árbol.")
            else:
                print(f" El valor {valor} No se encuentra en el árbol.")

        elif opcion == "3":
            print("Recorrido Preorden:")
            arbol.preorden(arbol.raiz)
            print()

        
        elif opcion == "4":
            print("Recorrido Inorden:")
            arbol.inorden(arbol.raiz)
            print()

        
        elif opcion == "5":
            print("Recorrido Postorden:")
            arbol.postorden(arbol.raiz)
            print()

        elif opcion == "6":
            print("Recorrido Postorden:")
            arbol.postorden(arbol.raiz)
            print()

        elif opcion == "7":
            print("Sliendo del programa")
            break

        else:
            print("Opción no válida, intente de nuevo.")

menu()

        
