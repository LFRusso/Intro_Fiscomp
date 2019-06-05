#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
using namespace std;

float G(float x, float r){
	return r*x*(1-x);
}


int main(){
	ofstream data1, data2, data3;
	data1.open("exp1.dat");
	data2.open("exp2.dat");
	data3.open("exp3.dat");
	float r;
	float x;
	float E = 0.01;
	float d;
	float x_;


	r = 1.5;
	x = float(1.0/6.0);
	x_ = x+E;
	for (int i = 1; i <= 20; i++){
		x = G(x, r);
		x_ = G(x_, r);
		d = abs(x_ - x);
		data1 << i << "\t" << d << "\n";		
	}

	r = 2.5;
	x = float(1.0/6.0);
	x_ = x+E;
	for (int i = 1; i <= 20; i++){
		x = G(x, r);
		x_ = G(x_, r);
		d = abs(x_ - x);
		data2 << i << "\t" << d << "\n";		
	}

	r = 2.7;
	x = float(1.0/6.0);
	x_ = x+E;
	for (int i = 1; i <= 20; i++){
		x = G(x, r);
		x_ = G(x_, r);
		d = abs(x_ - x);
		data3 << i << "\t" << d << "\n";		
	}

	data1.close();
	data2.close();
	data3.close();

	system("python3 fitexp.py");
	return 0;
}
