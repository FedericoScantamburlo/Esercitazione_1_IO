#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double mappatura(double x) {
	return (3.0/4.0) * x - (7.0/4.0);
}

double media(double numeri[], int i) {
	double somma = 0;
	for (int j = 0; j<i; j++) {
		somma += numeri[j];
	}
	return somma/i;
}


int main()
{
	ifstream inputFile("data.txt");
	if (!inputFile) {
		cerr << "Errore: impossibile aprire il file" << endl;
		return 1;
	}
	ofstream outputFile("result.txt");
	outputFile << "# N Mean" << endl;
	
	const int lunghezza_max = 2000;
	double numeri[lunghezza_max];
	int k = 0;
	double numero;
	outputFile << fixed << scientific << setprecision(16);
	
	while (inputFile >> numero) {
		if (numero <1 || numero >5) {
			cerr << "Errore: il numero non appartiene a [1, 5]" << endl;
			continue;
		}
		double numero_mappato = mappatura(numero);
		numeri[k] = numero_mappato;
		k++;
		outputFile << k << " " << media(numeri, k) << endl;
		if (k >= lunghezza_max) {
			cerr << "Errore: la quantità di numeri nel file supera la quantità massima leggibile" << endl;
			break;
		}
	}
	
	inputFile.close();
	outputFile.close();
	
    return 0;
}
