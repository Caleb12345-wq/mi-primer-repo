import random

def crear_matriz(filas, columnas):
    matriz = []
    opcion = input("Llenar manual (m) o aleatorio (a)? ").lower()

    for i in range(filas):
        fila = []
        for j in range(columnas):
            if opcion == 'm':
                valor = int(input(f"Elemento [{i}][{j}]: "))
            else:
                valor = random.randint(0,99)
            fila.append(valor)
        matriz.append(fila)
    return matriz

def imprimir_matriz(matriz):
    for fila in matriz:
        print(" ".join(map(str, fila)))


def suma_matrices():
    filas = int(input("Número de Filas: "))
    columnas = int(input("Número de columnas: "))

    print("Matriz A")
    A = crear_matriz(filas, columnas)
    print("Matriz B")
    B = crear_matriz(filas, columnas)

    C = [[A[i][j] + B[i][j] for j in range(columnas)] for i in range(filas)]

    print("Resultado de la suma: ")
    imprimir_matriz(C)

def transpuesta_matriz():
    filas = int(input("Número de Filas: "))
    columnas = int(input("Número de columnas: "))

    print("Matriz A")
    A = crear_matriz(filas, columnas)

    T = [[A[j][i] for j in range(filas)] for i in range(columnas)]

    print("Resultado de Transpuesta de la Matriz es: ")
    imprimir_matriz(T)

def multiplicacion_matriz():
    fA = int(input("Número de Filas de la Matriz A: "))
    cA = int(input("Número de columnas de la Matriz A: "))
    fB = int(input("Número de Filas de la Matriz B: "))
    cB = int(input("Número de columnas de la Matriz B: "))

    if cA != fB:
        print("Error: las matrices no se puede multiplicar (columnas A != filas B).")
        return

    print("Matriz A")
    A = crear_matriz(fA, cA)
    print("Matriz B")
    B = crear_matriz(fB, cB)

    C = [[0 for _ in range(cB)] for _ in range(fA)]
    
    for i in range(fA):
        for j in range(cB):
            for k in range(cA):
                C[i][j] += A[i][k] * B[k][j]

    print("Resultado de la Multiplicación:")
    imprimir_matriz(C)

def buscar_numero_matriz():
    filas = int(input("Número de filas de la Matriz: "))
    columnas = int(input("Número de columnas de la Matriz"))

    print("Matriz")
    matriz = crear_matriz(filas, columnas)

    numero = int(input("Numero a buscar" ))
    encontrado = False

    for i in range(filas):
        for j in range(columnas):
            if matriz[i][j] == numero:
                print(f"Número encontrado en la posición [{i}][{j}]")
                encontrado = True

        if not encontrado:
            print("Número no encontrado en la matriz.")

def contar_palabras():
    frase = input("Escribe una Frase: ")
    palabras = frase.split()
    print("Número de palabras:", len(palabras))

def ordenar_letras():
    cadena = input("Ingresa una cadena: ")
    letras = [c for c in cadena if c.isalpha()]
    letras.sort()
    print("Cadena ordenada:", " ".join(letras))

def detectar_subcadena():
    texto = input("Ingresa el texto: ")
    subcadena = input("Ingresa la subcadena a buscar: ")

    if subcadena in texto:
        print("La subcadena se encuentra en el texto.")
    else:
        print("La subcadena No ha sido encontrada en el texto.")

def verificar_palindromo():
    cadena = input("Ingresa una cadena: ")

    cadena_limpia = ''.join(c.lower() for c in cadena if c.isalnum())

    if cadena_limpia == cadena_limpia[::-1]:
        print("La cadena es un palindromo.")
    else:
        print("La cadena No es un Palindromo.")
    
def main():
    while True:
        print("\n------- Menú Principal ------")
        print("1. Suma de dos Matrices")
        print("2. Transpuesta de una Matriz")
        print("3. Multiplicación de Matrices")
        print("4. Buscar Número en una Matriz")
        print("5. Contar palabras en Cadena")
        print("6. Ordenar Letras")
        print("7. Detectar Subcadena")
        print("8. Verificar Palindromo")
        print("9. Salir")
        opcion = input("Elige una Opción: ")

        if opcion == "1":
                suma_matrices()
        elif opcion == "2":
                transpuesta_matriz()
        elif opcion == "3":
                multiplicacion_matriz()
        elif opcion == "4":
                buscar_numero_matriz()
        elif opcion == "5":
                contar_palabras()
        elif opcion == "6":
                ordenar_letras()
        elif opcion == "7":
                detectar_subcadena()
        elif opcion == "8":
                verificar_palindromo()

        elif opcion == "9":
                print("Saliendo del programa....")
                break
        else:
                print("opción invalida")
            
if __name__ == "__main__":
    main()

    
        
