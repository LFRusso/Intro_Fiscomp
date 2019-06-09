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
	ofstream data;
	data.open("GX.dat");
	float r = 0.5; // Valor inicial de r
	for (int j = 0; j < 3; j++){
		for (int x =1; x <= 100; x++){
			data << x << "\t" << G(x, r) << "\t" << r << "\n"; // Calculo x e G(x, r) e salvo um arquivo
		}
		r *= 2; // Próximo valor de r
	}
	data.close();
	system("python3 GX.py"); // Script para plot
	return 0;
}
