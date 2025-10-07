 #include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> 

using namespace std;

struct Producto {
    string nombre;
    string codigo;
    float precio;
    string proveedor;
    int existencia;
    char estado;
    float descuento;
};

void agregarProducto(vector<Producto>& productos) {
    Producto nuevo;
    cout << "\nIngrese el código: ";
    cin >> nuevo.codigo;

    
    for (size_t i = 0; i < productos.size(); i++) {
        if (productos[i].codigo == nuevo.codigo) {
            cout << "Error. el código ya existe.\n";
            return;
        }
    }

    cin.ignore(); // limpiar buffer
    cout << "Ingrese el nombre: ";
    getline(cin, nuevo.nombre);

    cout << "Ingrese el proveedor: ";
    getline(cin, nuevo.proveedor);

    cout << "Ingrese el precio: ";
    cin >> nuevo.precio;

    cout << "Ingrese la existencia: ";
    cin >> nuevo.existencia;

    cout << "Ingrese el estado (A=aprobado, N=no aprobado): ";
    cin >> nuevo.estado;

    cout << "Ingrese el descuento (ej: 0.10 para 10%): ";
    cin >> nuevo.descuento;

    productos.push_back(nuevo);

    ofstream archivo("productos.txt", ios::app);
    if (!archivo) {
        cout << "Error al abrir el archivo.\n";
        return;
    }

    
    archivo << nuevo.codigo << ";"
            << nuevo.nombre << ";"
            << nuevo.proveedor << ";"
            << nuevo.precio << ";"
            << nuevo.existencia << ";"
            << nuevo.estado << ";"
            << nuevo.descuento << "\n";

    archivo.close();
    cout << "Producto agregado exitosamente.\n";
}


void cargarProductos(vector<Producto>& productos) {
    ifstream archivo("productos.txt");
    if (!archivo) return;

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Producto temp;
        string precio_str, existencia_str, descuento_str;
        string estado_str;

        getline(ss, temp.codigo, ';');
        getline(ss, temp.nombre, ';');
        getline(ss, temp.proveedor, ';');
        getline(ss, precio_str, ';');
        getline(ss, existencia_str, ';');
        getline(ss, estado_str, ';');
        getline(ss, descuento_str, '\n');

        
        stringstream(precio_str) >> temp.precio;
        stringstream(existencia_str) >> temp.existencia;
        if (!estado_str.empty())
            temp.estado = estado_str[0];
        stringstream(descuento_str) >> temp.descuento;

        productos.push_back(temp);
    }

    archivo.close();
}


bool contiene(const string& str, const string& substr) {
    return str.find(substr) != string::npos;
}


void buscarProducto(vector<Producto>& productos) {
    int opcion;
    cout << "\nBuscar por: 1. Código  2. Nombre\nSeleccione: ";
    cin >> opcion;
    cin.ignore();

    if (opcion == 1) {
        string cod;
        cout << "Ingrese el código: ";
        getline(cin, cod);

        for (size_t i = 0; i < productos.size(); i++) {
            if (productos[i].codigo == cod) {
                cout << "Producto encontrado: " << productos[i].nombre << endl;
                return;
            }
        }
        cout << "No se encontró el producto con ese código.\n";

    } else if (opcion == 2) {
        string palabra;
        cout << "Ingrese palabra a buscar: ";
        getline(cin, palabra);
        bool encontrado = false;

        for (size_t i = 0; i < productos.size(); i++) {
            if (contiene(productos[i].nombre, palabra)) {
                cout << "Producto encontrado: " << productos[i].nombre
                     << " - Código: " << productos[i].codigo << endl;
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "No se encontraron productos que contengan esa palabra.\n";
        }

    } else {
        cout << "Opción inválida.\n";
    }
}

void modificarProducto(vector<Producto>& productos) {
	string cod;
	cout << "Ingrese el codigo del producto a modificar: ";
	cin >> cod;
	cin.ignore();
	
	bool encontrado = false;
	for(size_t i = 0; i < productos.size(); i++) {
		if (productos[i].codigo == cod) {
			encontrado = true;
			
			cout << "Nombre actual: " << productos[i].nombre << "\nNuevo nombre: ";
			getline(cin, productos[i].nombre);
			
			cout << "Proveedor actual: " << productos[i].precio << "\nNuevo proveedor: ";
			getline(cin, productos[i].proveedor);
			
			cout << "Precio actual: " << productos[i].precio << "\nNuevo precio: ";
			cin >> productos[i].precio;
			
			cout << "Estado actual: " << productos[i].estado << "\nNuevo estado (A/N): ";
			cin >> productos[i].estado;
			
			cout << "Descuento actual: " << productos[i].descuento << "\nNuevo descuento: ";
			cin >> productos[i].descuento;
			
			ofstream archivo("productos.txt");
			for(size_t j = 0; j < productos.size(); j++) {
		 
		 archivo << productos[j].codigo << ";"
            << productos[j].nombre << ";"
            << productos[j].proveedor << ";"
            << productos[j].precio << ";"
            << productos[j].existencia << ";"
            << productos[j].estado << ";"
            << productos[j].descuento << "\n";

         }
			archivo.close();
			
			cout << "Producto modificado exitosamente\n";
			return;
		}
	}
	 if (!encontrado)
	  cout << "Producto no encontrado.\n";
}
     void eliminarProducto(vector<Producto>& productos) {
     	string cod;
     	cout << "Ingrese el codigo del producto a eliminar: ";
     	cin >> cod;
     	cin.ignore();
     	
     	bool encontrado = false;
     	
     	for(size_t i = 0; i < productos.size(); i++) {
     		if (productos[i].codigo == cod) {
     			encontrado = true;
     			
     		cout << "Producto encontrado: " << productos[i].nombre << endl;
     		cout << "¿Desea eliminarlo? (S/N): ";
     		char confirmar;
     		cin >> confirmar;
     	if (toupper(confirmar) == 'S') {
     		productos.erase(productos.begin() + i);
     		
     		ofstream archivo("productos.txt");
			 for(size_t j = 0; j < productos.size(); j++) {
		 
		 archivo << productos[j].codigo << ";"
            << productos[j].nombre << ";"
            << productos[j].proveedor << ";"
            << productos[j].precio << ";"
            << productos[j].existencia << ";"
            << productos[j].estado << ";"
            << productos[j].descuento << "\n";
 
			 }
		 archivo.close();
		 
		  cout << "Producto eliminado exitosamente.\n";
	}else {
		cout << "Eliminacion cancelada.\n";
	}
		return;	 
			 }
		 }	
	        if(!encontrado)
	         cout << "Producto no encontrado.\n";
 
}	 
void menu() {
    vector<Producto> productos;
    cargarProductos(productos);

    int opcion;
    do {
        cout << "\n1. Agregar Producto\n";
        cout << "2. Buscar Producto\n";
        cout << "3. Modificar Producto\n";
        cout << "4. Eliminar Producto\n";
		cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                agregarProducto(productos);
                break;
            case 2:
                buscarProducto(productos);
                break;
            case 3:
               modificarProducto(productos);
               break;
            case 4:
                eliminarProducto(productos);
                break;
            case 5:
                cout << "Saliendo del programa\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }

    } while (opcion != 4);
}


int main() {
    menu();
    return 0;
}

