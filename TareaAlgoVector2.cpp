#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main () {
	
	int n;
	
cout << "Ingrese el tamaño del vector: "; 	
cin >> n;
	
int arr[n];	
	
srand(time(0));	
	
cout << "Vector generado aleatoriamente: ";	
for (int i = 0; i < n; i++) {
	arr[i] = rand() % 100 + 1;
	cout << arr[i] << " ";
}	
	
	cout << endl;
	
return 0;
	
}
