while True:  

    print("\n--- Menú ---")                        
    print("1. Factorial de un número")            
    print("2. Determinar subsidio de Familia")    
    print("3. Salir")                             

    try:                                          
        opcion = int(input("Elija una opción (1-3): "))  
    except ValueError:                            
        print("Entrada inválida. Por favor ingrese un número (1-3).")  
        continue                                   

    if opcion == 1:                               
        numero = int(input("Ingrese un número entero positivo: "))  
        factorial = 1

        for i in range(1, numero + 1):
            factorial *= i

        print(f"El factorial de {numero} es {factorial}")
    elif opcion == 2:

        hijos = int(input("Ingrese la cantidad de hijos/as: "))

        total = 0

        if hijos == 3:
            total = 300

        elif 4 <= hijos <= 5:
            total = 350

        elif hijos > 5:
            total = 400

        entre_7y18 = int(input("¿Cuantos hijos/as tiene entre 7 y 18 años?: "))

        total += total * 0.06 * entre_7y18

        print(f"El total del subsidio es: Q. {total}")
    elif opcion == 3:

        print("Saliendo del programa...")

        break
    else:

        print("Opción inválida. Intente de nuevo:")
                
            

