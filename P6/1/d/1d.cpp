#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;


double F2(double x, double a, double b){ // segunda função dada
	x = (b-a)*x + a;
	return double(1)/x;
}

double F1(double x, double a, double b){ // primeira função dada
	x = (b-a)*x + a;
	return double(4)/(pow(x, 2)+1);
}


int main(){
	int n, k;
	double E, x, med, integral, a, b;
	std::vector<double> V;
	ofstream data1, data2;
	data1.open("data1.dat");
	data2.open("data2.dat");
	V.reserve(10001);


	// operação para integral 1
	k = 0;
	E = 1;
	a = 0;
	b = 1;
	for(int k = 1; k<=15; k++){ // variando o expoente de n
		n = pow(2, k);
		E = 0;

		for(int j=0; j<= 10000; j++){ // loop criando um 10000 conjuntos de valores
			med = 0;
			for(int i = 0; i <= n; i++){ // loop realizando a operação para um número variável n de vezes
				x = double(rand() % int(pow(10, 5)))/pow(10, 5);
				med += F1(x, a, b);
			}
			med = med/n; // média dos resultados
			V[j] = med;
		}

		med = 0;
		for(int i=0; i <= 10000; i++){ // cálculo da "média das médias"
			med += V[i];
		}
		med = med/double(10000);

		for(int i=0; i<=10000; i++){ // calculo do desvio padrão/erro
			E += pow(V[i] - med, 2)/n;
		}

		E = sqrt(E);

		cout <<(b-a)*med << " +/- "<< E << endl; // acompanhamento da convergência do resultado
		data1 << n << "\t" << med << "\t" << E << "\n"; // salvando no arquivo para representação gráfica
	}
	cout << "\n Terminada intergral 1 \n" << endl;


	// mesma operação para integral 2
	E = 1;
	a = 1;
	b = 10;
	for(int k=1; k <=15; k++){
		n = pow(2, k);
		E = 0;

		for(int j=0; j<= 10000; j++){
			med = 0;
			for(int i = 0; i <= n; i++){ // tamanho da amostra
				x = double(rand() % int(pow(10, 5)))/pow(10, 5);
				med += F2(x, a, b);
			}
			med = med/n;
			V[j] = med;
		}

		med = 0;
		for(int i=0; i <= 10000; i++){
			med += V[i];
		}
		med = med/double(10000);

		for(int i=0; i<=10000; i++){
			E += pow(V[i] - med, 2)/n;
		}
		E = sqrt(E);

		cout <<(b-a)*med << " +/- "<< E << endl;
		data2 << n << "\t" << (b-a)*med << "\t" << E << "\n";
	}
	cout << "\n Terminada intergral 2 \n" << endl;

	data1.close();
	data2.close();
	system("python3 graph.py"); // graficando resultados
	return 0;
}