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
	data1.open("data1.dat"); // arquivo correspondendo a r = 1.5
	data2.open("data2.dat"); // arquivo correspondendo a r = 2.5
	data3.open("data3.dat"); // arquivo correspondendo a r = 2.7
	float r;
	float x;
	float E = 0.01; // epsilon
	float d;
	float x_;

	r = 1.5; // caso r = 1.5
	for (int j = 1; j <= 5; j++){ // Loop variando x0
		x = float(j)/6;
		x_ = x+E; //valor de x0 + epsilon
		for (int i = 1; i <= 20; i++){
			x = G(x, r);
			x_ = G(x_, r);
			d = abs(x_ - x); // Cálculo da distância d
			data1 << i << "\t" << d << "\n";		
		}
	}

	r = 2.5; // caso r = 2.5
	for (int j = 1; j <= 5; j++){ // Loop variando x0
		x = float(j)/6;
		x_ = x+E; //valor de x0 + epsilon
		for (int i = 1; i <= 20; i++){
			x = G(x, r);
			x_ = G(x_, r);
			d = abs(x_ - x); // Cálculo da distância d
			data2 << i << "\t" << d << "\n";		
		}
	}

	r = 2.7; // caso r = 2.7
	for (int j = 1; j <= 5; j++){ // Loop variando x0
		x = float(j)/6;
		x_ = x+E; //valor de x0 + epsilon
		for (int i = 1; i <= 20; i++){
			x = G(x, r);
			x_ = G(x_, r);
			d = abs(x_ - x); // Cálculo da distância d
			data3 << i << "\t" << d << "\n";		
		}
	}

	data1.close();
	data2.close();
	data3.close();

	system("python3 logistic.py"); // Script para plot
	return 0;
}
