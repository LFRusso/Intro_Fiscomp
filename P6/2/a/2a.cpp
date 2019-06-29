#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	double dt{0.005};
	double r, m, number;
	ofstream data;
	int N0{1000}, N, u;
	int k{1000};
	int t{10};
	int iterations;
	iterations = t/dt + 1;
	data.open("dados.dat");
	srand(42);

	for(int i=0; i<=k; i++){
		N = N0;
		for(int j=0; j<=iterations; j++){
			u = N;
			for(int w=0; w<=u; w++){
				number = double(rand() % int(pow(10, 5)))/pow(10, 5);
				if(number < dt && N > 0){
					--N;
				}
			}
			data << double(j)*dt << "\t" << N << "\t" << iterations << "\t" << k << "\n";
		}
		cout << "Simulações concluídas: " << i << endl;
	}
	data.close();

	cout << "Conlcuído\n\ncarregando gráfico..." << endl;
	system("python3 graph.py");

	return 0;
}