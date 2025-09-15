a#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>

using namespace std;

void sumaMatrices();
void transpuestaMatriz();
void multiplicacionMatrices();
void buscarNumeroMatriz();
void contarPalabras();
void ordenarLetras();
void detectarSubcadena();
void verificarPalindromo();
vector<vector<int> > crearMatriz(int filas, int columnas);
void imprimirMatriz(const vector<vector<int> >& mat);

int main() {
    srand(time(0));
    int opcion;

    do {
        cout << "\n------- Menú Principal ------\n";
        cout << "1. Suma de dos matrices\n";
        cout << "2. Transpuesta de una Matriz\n";
        cout << "3. Multiplicación de Matrices\n";
        cout << "4. Buscar un número en una matriz\n";
        cout << "5. Contar palabras en una cadena\n";
        cout << "6. Ordenar las letras de una cadena\n";
        cout << "7. Detectar subcadena\n";
        cout << "8. Verificar palíndromo\n";
        cout << "9. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: sumaMatrices(); break;
            case 2: transpuestaMatriz(); break;
            case 3: multiplicacionMatrices(); break;
            case 4: buscarNumeroMatriz(); break;
            case 5: contarPalabras(); break;
            case 6: ordenarLetras(); break;
            case 7: detectarSubcadena(); break;
            case 8: verificarPalindromo(); break;
            case 9: cout << "Saliendo...\n"; break;
            default: cout << "Opción invalida\n";
        }
    } while(opcion != 9);

    return 0;
}

vector<vector<int> > crearMatriz(int filas, int columnas) {
    vector<vector<int> > mat;
    char opcion;
    cout << "Llenar manual (m) o aleatorio (a)? ";
    cin >> opcion;

    for(int i = 0; i < filas; i++){
        vector<int> fila;
        for(int j = 0; j < columnas; j++){
            int val;
            if(opcion == 'm') {
                cout << "Elemento [" << i << "][" << j << "]: ";
                cin >> val;
            } else {
                val = rand() % 100;
            }
            fila.push_back(val);
        }
        mat.push_back(fila);
    }
    return mat;
}

void imprimirMatriz(const vector<vector<int> >& mat) {
    for(size_t i = 0; i < mat.size(); i++) {
        for(size_t j = 0; j < mat[i].size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void sumaMatrices() {
    int f, c;
    cout << "Filas y columnas: ";
    cin >> f >> c;

    cout << "Matriz A\n";
    vector<vector<int> > A = crearMatriz(f, c);
    cout << "Matriz B\n";
    vector<vector<int> > B = crearMatriz(f, c);

    vector<vector<int> > C(f, vector<int>(c));
    for(int i = 0; i < f; i++)
        for(int j = 0; j < c; j++)
            C[i][j] = A[i][j] + B[i][j];

    cout << "Resultado:\n";
    imprimirMatriz(C);
}

void transpuestaMatriz() {
    int f, c;
    cout << "Filas y columnas de la matriz: ";
    cin >> f >> c;

    cout << "Matriz A\n";
    vector<vector<int> > A = crearMatriz(f, c);

    vector<vector<int> > T(c, vector<int>(f));
    for(int i = 0; i < f; i++)
        for(int j = 0; j < c; j++)
            T[j][i] = A[i][j];

    cout << "Transpuesta:\n";
    imprimirMatriz(T);
}

void multiplicacionMatrices() {
    int fA, cA, fB, cB;
    cout << "Filas y columnas de la matriz A: ";
    cin >> fA >> cA;
    cout << "Filas y columnas de la matriz B: ";
    cin >> fB >> cB;

    if(cA != fB) {
        cout << "Error: las matrices no se pueden multiplicar\n";
        return;
    }

    cout << "Matriz A\n";
    vector<vector<int> > A = crearMatriz(fA, cA);
    cout << "Matriz B\n";
    vector<vector<int> > B = crearMatriz(fB, cB);

    vector<vector<int> > C(fA, vector<int>(cB, 0));
    for(int i = 0; i < fA; i++)
        for(int j = 0; j < cB; j++)
            for(int k = 0; k < cA; k++)
                C[i][j] += A[i][k] * B[k][j];

    cout << "Resultado:\n";
    imprimirMatriz(C);
}

void buscarNumeroMatriz() {
    int f, c, num;
    cout << "Número de filas de la matriz: ";
    cin >> f;
    cout << "Número de columnas de la matriz: ";
    cin >> c;

    vector<vector<int> > mat = crearMatriz(f, c);

    cout << "Número a buscar: ";
    cin >> num;

    bool encontrado = false;
    for(int i = 0; i < f && !encontrado; i++)
        for(int j = 0; j < c; j++)
            if(mat[i][j] == num){
                encontrado = true;
                cout << "Número encontrado en la posición [" << i << "][" << j << "]\n";
                break;
            }

    if(!encontrado)
        cout << "Número no encontrado\n";
}

void contarPalabras() {
    string frase;
    cout << "Ingresa una frase: ";
    cin.ignore();
    getline(cin, frase);

    int palabras = 0;
    bool espacio = true;
    for(size_t i = 0; i < frase.size(); i++){
        if(isspace(frase[i]))
            espacio = true;
        else {
            if(espacio) palabras++;
            espacio = false;
        }
    }
    cout << "Número de palabras: " << palabras << endl;
}

void ordenarLetras() {
    string cadena, ordenada;
    cout << "Ingresa una cadena: ";
    cin.ignore();
    getline(cin, cadena);

    for(size_t i = 0; i < cadena.size(); i++)
        if(isalpha(cadena[i]))
            ordenada += cadena[i];

    for(size_t i = 0; i < ordenada.size() - 1; i++)
        for(size_t j = i + 1; j < ordenada.size(); j++)
            if(ordenada[i] > ordenada[j])
                swap(ordenada[i], ordenada[j]);

    cout << "Cadena ordenada: " << ordenada << endl;
}

void detectarSubcadena() {
    string texto, subcadena;
    cout << "Ingresa el texto: ";
    cin.ignore();
    getline(cin, texto);
    cout << "Ingresa la subcadena a buscar: ";
    getline(cin, subcadena);

    bool encontrada = false;
    for(size_t i = 0; i <= texto.size() - subcadena.size(); i++){
        bool match = true;
        for(size_t j = 0; j < subcadena.size(); j++)
            if(texto[i+j] != subcadena[j]){
                match = false;
                break;
            }
        if(match){
            encontrada = true;
            break;
        }
    }

    if(encontrada)
        cout << "La subcadena se encuentra en el texto.\n";
    else
        cout << "La subcadena NO se encuentra en el texto.\n";
}

void verificarPalindromo() {
    string frase, filtrada;
    cout << "Ingresa una frase: ";
    cin.ignore();
    getline(cin, frase);

    
    for(size_t i = 0; i < frase.size(); i++) {
        char c = frase[i];
        if(isalpha(c)) {
            filtrada += tolower(c);
        }
    }

    
    bool esPalindromo = true;
    int n = filtrada.size();
    for(int i = 0; i < n / 2; i++) {
        if(filtrada[i] != filtrada[n - i - 1]) {
            esPalindromo = false;
            break;
        }
    }

    if(esPalindromo)
        cout << "La frase es un palíndromo\n";
    else
        cout << "La frase No es un palíndromo\n";
}


