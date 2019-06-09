#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
using namespace std;

float G(float x, float r){
	return r*x*(1-x); // Função G deginida
}


int main(){
	ofstream data1, data2, data3;
	data1.open("logistic1.dat"); // arquivo correspondendo a r = 1.0
	data2.open("logistic2.dat"); // arquivo correspondendo a r = 2.0
	data3.open("logistic3.dat"); // arquivo correspondendo a r = 2.5
	float r;
	float x;

	r = 1; // caso r = 1
	for (int j = 1; j <= 5; j++){ // Loop variando x0
		x = float(j)/6;
		for (int i = 1; i <= 20; i++){
			x = G(x, r); // Calculando iteração de G(x, r)
			data1 << i << "\t" << x << "\n";		
		}
	}

	r = 2; // caso r = 2
	for (int j = 1; j <= 5; j++){ // Loop variando x0
		x = float(j)/6;
		for (int i = 1; i <= 20; i++){
			x = G(x, r); // Calculando iteração de G(x, r)
			data2 << i << "\t" << x << "\n";		
		}
	}

	r = 2.5; // caso r = 2.5
	for (int j = 1; j <= 5; j++){ // Loop variando x0
		x = float(j)/6;
		for (int i = 1; i <= 20; i++){
			x = G(x, r); // Calculando iteração de G(x, r)
			data3 << i << "\t" << x << "\n";		
		}
	}

	data1.close();
	data2.close();
	data3.close();

	system("python3 logistic.py"); // Script para plot
	return 0;
}
