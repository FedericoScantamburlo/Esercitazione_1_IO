#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream inputFile("data.txt");
	if (!inputFile) {
		cerr << "Errore: impossibile aprire il file" << endl;
		return 1;
	}
	
	string primaRiga;
	getline (inputFile, primaRiga);
	
	double numero, somma = 0;
	int ultimoNumero = 0;
	
	while (inputFile >> numero) {
		somma += numero * numero;
		ultimoNumero = numero;
	}
	
	inputFile.close();
	
	long long risultato = (ultimoNumero*(ultimoNumero+1)*(2*ultimoNumero+1))/6;
	
	
	cout << "Somma dei quadrati: " << somma << endl;
	cout << "Risultato formula: " << risultato << endl; 
    return 0;
}
