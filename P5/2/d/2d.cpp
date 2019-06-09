#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
using namespace std;

double G(double x,double r){
   return r*x*(1 - x);
}

int main(){
  double r;
  double x, x_, d;
  double E = pow(10, -10);

  for (int k=1; k<= 5; k++){
    r = 3.569946 + (3.569946 - 4.0)*double(k)/5;
    ofstream *data = new ofstream;
    data -> open("dados.dat");
    for (int i=1; i <= 5; i++){
      x = 0.1*i;
      x_ = x + E;
      for (int j = 0; j <= 100; j++){
        d = abs(x - x_);
        x = G(x,r);
        x_ = G(x_, r);

        *data << 0.1*i << "\t" << r << "\t" << x_ << "\t" << d << "\t" << j << endl;
      }
		}
    system("python3 graph.py");
    system("rm dados.dat");
	}
   return 0;
}
