#include <iostream>
#include <string>
using namespace std;

int suma(int a, int b)        { return a + b; }
int restar(int a, int b)      { return a - b; }
int multiplicar(int a, int b) { return a * b; }
int dividir(int a, int b)     { return a / b; }

int main() {
    int num1, num2;	
    int opcion;

    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    cout << "\nSeleccione la operacion:\n";
    cout << "1. Sumar\n";
    cout << "2. Restar\n";
    cout << "3. Multiplicar\n";
    cout << "4. Dividir\n";
    cout << "Opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Resultado: " << suma(num1, num2) << endl;
            break;
        case 2:
            cout << "Resultado: " << restar(num1, num2) << endl;
            break;
        case 3:
            cout << "Resultado: " << multiplicar(num1, num2) << endl;
            break;
        case 4:
            if (num2 != 0)
                cout << "Resultado: " << dividir(num1, num2) << endl;
            else
                cout << "Error: division entre cero no permitida.\n";
            break;
        default:
            cout << "Opcion no valida.\n";
    }

    cin.ignore();
    string frase;
    cout << "\nIngrese una frase: ";
    getline(cin, frase);

    cout << "Frase invertida: ";
    for (int i = frase.size() - 1; i >= 0; i--) {
        cout << frase[i];
    }
    cout << endl;

    return 0;
}

