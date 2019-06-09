#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
using namespace std;

double G(double x,double r){
   return r*x*(1 - x); // Função G(x, r)
}

int main(){
  double r;
  double x, x_, d;
  double E = pow(10, -10); // valor de epsilon

  for (int k=1; k<= 5; k++){
    r = 3.569946 + (3.569946 - 4.0)*double(k)/5; //variação do valor de r
    ofstream *data = new ofstream; // ponteiro para ofstream , onde salvo o próximo valor de r
    data -> open("dados.dat"); // abro um novo arquivo para salvar os dados
    for (int i=1; i <= 5; i++){
      x = 0.1*i; // iterando valor de x0
      x_ = x + E; // calcula x0 + epsilon
      for (int j = 0; j <= 100; j++){
        d = abs(x - x_); // calcula d
        x = G(x,r);
        x_ = G(x_, r); // itarando valores

        *data << 0.1*i << "\t" << r << "\t" << x_ << "\t" << d << "\t" << j << endl;
      }
		}
    system("python3 graph.py"); // script para plot
    system("rm dados.dat"); // limpo o arquivo para a próxima iteração
	}
   return 0;
}
