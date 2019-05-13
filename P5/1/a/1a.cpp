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
	ofstream data;
	data.open("GX.dat");
	float r = 0.5;
	for (int j = 0; j < 3; j++){
		for (int x =1; x <= 100; x++){
			data << x << "\t" << G(x, r) << "\t" << r << "\n";
		}
		r *= 2;
	}
	data.close();
	system("python3 GX.py");
	return 0;
}
