#include <iostream>
#include <cmath>
#define n 10000 // número de iterações
using namespace std;

double derG(double x, double r){
	return r*(1-2*x); // derivada de G(x)
}

double G(double x, double r){
	return r*x*(1-x); // função G(x)
}

int main(){
	double r;
	double x;
	double L;

	r = 2.5; // Valor de r
	for (int j = 1; j <= 5; j++){ // Loop variando x0
		x = double(j)*0.1;
		x = G(x, r);
		L = log(abs(derG(x, r))); // Primeiro valor da somatória
		for (int i = 0; i <= n-1; i++){
			x = G(x, r); // Itera x
			L += log(abs(derG(x, r)));	// Soma valor de log da derivada
		}
		L = L/n; // Divide pelo número de iterações
		cout << "X0 = " << double(j)*0.1 << " Lyapunov = " << L << endl; 
	}
}
