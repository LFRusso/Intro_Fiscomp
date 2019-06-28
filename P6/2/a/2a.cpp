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
	int N0{10000}, N, u;
	int k{10};
	int t{7};
	int iterations;
	iterations = t/dt + 1;
	double P[k+1][iterations+1];

	for(int i=0; i<=k; i++){
		data.open("dados");
		N = N0;
		for(int j=0; j<=iterations; j++){
			u = N;
			for(int w=0; w<=u; w++){
				number = double(rand() % int(pow(10, 5)))/pow(10, 5);
				if(number < dt){
					--N;
				}
			}
			//P[j][i] = N;
			data << double(j)*dt << "\t" << N << "\n";
		}
		data.close();
		system("python3 graph.py");
		system("rm data");
	}


	return 0;
}