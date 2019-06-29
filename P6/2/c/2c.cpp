#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	ofstream data;
	double x, r;
	data.open("dados.dat");
	srand(42);

	for(int i=0; i <= pow(10, 6); ++i){
		r = double(rand() % int(pow(10, 5)))/pow(10, 5);
		x = - log(double(1) - r);
		data << x << "\n";
	}

	cout << "\nCarregando gráfico..." << endl;

	data.close();
	system("python3 graph.py");
	return 0;
}