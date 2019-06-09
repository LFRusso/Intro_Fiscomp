#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#define n 200 // número de iterações
using namespace std;

double G(double x, double r){
	return r*x*(1-x); // função G(x)
}

double derG(double x, double r){
	return r*(1-2*x); // derivada de G(x)
}

int main(){
	double r;
	double x;
	double E = 0.05; // epsilon

	ofstream data, histo;
	data.open("iderivative.dat");
	histo.open("histogram.dat");

	r = 2.9; // define r
	x = 0.1; // define x0
	for (int i = 1; i <= n; i++){
		x = G(x, r); // itera x
		data << i << "\t" << log(abs(derG(x, r))) << endl; // salvando no arquivo
		if (i > 100)
		{
			histo.precision(9); // define precisão do número salvo. OBS: isso interfere diretamente no histograma (checar programa .py)
			histo << log(abs(derG(x, r))) << endl;
		}
	}
	system("python3 graph.py"); // plot dos gráficos e manipulação dos dados do histograma
}
