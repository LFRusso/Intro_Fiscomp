#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#define n 200
using namespace std;

double G(double x, double r){
	return r*x*(1-x);
}

double derG(double x, double r){
	return r*(1-2*x);
}

int main(){
	double r;
	double x;
	double E = 0.05;

	ofstream data, histo;
	data.open("iderivative.dat");
	histo.open("histogram.dat");

	r = 2.9;
	x = 0.1;
	for (int i = 1; i <= n; i++){
		x = G(x, r);
		data << i << "\t" << log(abs(derG(x, r))) << endl;
		if (i > 100)
		{
			histo.precision(9);
			histo << log(abs(derG(x, r))) << endl;
		}
	}
	system("python3 graph.py");
}
