#include <iostream>
#include <cmath>
#define n 10000
using namespace std;

double derG(double x, double r){
	return r*(1-2*x);
}

double G(double x, double r){
	return r*x*(1-x);
}

int main(){
	double r;
	double x;
	double L;

	r = 2.5;
	for (int j = 1; j <= 5; j++){
		x = double(j)*0.1;
		x = G(x, r);
		L = log(abs(derG(x, r)));
		for (int i = 0; i <= n-1; i++){
			x = G(x, r);
			L += log(abs(derG(x, r)));	
		}
		L = L/n;
		cout << "X0 = " << double(j)*0.1 << " Lyapunov = " << L << endl; 
	}
}
