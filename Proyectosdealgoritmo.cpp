#include <iostream>
using namespace std;

int main() {
    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Factorial de un numero\n";
        cout << "2. Determinar subsidio de familia\n";
        cout << "3. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                int n;
                long long factorial = 1;
                cout << "Ingrese un numero entero positivo: ";
                cin >> n;
                for (int i = 1; i <= n; i++) {
                    factorial *= i;
                }
                cout << "El factorial de " << n << " es: " << factorial << endl;
                break;
            }
            case 2: {
                int hijos, edad;
                double subsidio = 0, extra = 0;
                cout << "Ingrese el numero de hijos: ";
                cin >> hijos;

                if (hijos == 3) subsidio = 300;
                else if (hijos >= 4 && hijos <= 5) subsidio = 350;
                else if (hijos > 5) subsidio = 400;

                for (int i = 1; i <= hijos; i++) {
                    cout << "Ingrese la edad del hijo " << i << ": ";
                    cin >> edad;
                    if (edad >= 7 && edad <= 18) {
                        extra += subsidio * 0.06;
                    }
                }

                cout << "El subsidio total es: Q. " << subsidio + extra << endl;
                break;
            }
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
        }
    } while(opcion != 3);

    return 0;
}
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

