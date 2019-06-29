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

	for(int i=0; i<=k; i++){ // loop fazendo a simulação para k amostras
		N = N0; // resetando número de núcleos
		for(int j=0; j<=iterations; j++){ // loop simulando o período definido de tempo
			u = N;
			for(int w=0; w<=u; w++){ // loop percorrendo os núcleos
				number = double(rand() % int(pow(10, 5)))/pow(10, 5);
				if(number < dt && N > 0){ // condição de decaimento
					--N;
				}
			}
			data << double(j)*dt << "\t" << N << "\t" << iterations << "\t" << k << "\n"; // salvando estado autal em um arquivo
		}
		cout << "Simulações concluídas: " << i << endl; // acompanhamento do processo
	}
	data.close();

	cout << "Conlcuído\n\ncarregando gráfico..." << endl;
	system("python3 graph.py"); // graficagem e cálculos da média e desvio padrão dos resultados

	return 0;
}