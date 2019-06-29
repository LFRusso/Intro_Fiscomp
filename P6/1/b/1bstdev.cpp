// programa para calcular o desvio padrão em função de N

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
   double number, med, total_med,stdev;
   int k{1000};
   srand(4);
   ofstream data, data2;
   data2.open("desvio.dat");
   vector<double> V;
   vector<double> medias;
   V.reserve(pow(3, 9)+1);
   medias.reserve(k+1);

   for(int m = 1; m<=9; ++m){
      stdev = 0;
      total_med = 0;
      for(int i=0; i<=k; ++i){
         med = 0;
         for(int j=0; j<=pow(3, m); ++j){
            number = double(rand() % int(pow(10, 5)))/pow(10, 5);
            V[j] = number;
            med += number;
         }
         med = med/double(pow(3, m));
         medias[i] = med;
         total_med += med;
      }
      total_med = total_med/double(k);
      for(int i=0; i<=k; ++i){
         stdev += pow(total_med - medias[i], 2);
      }
      stdev = sqrt(stdev/double(k));
      data2 << pow(3, m) << "\t" << stdev << endl;
   }

   data2.close();
   system("python3 graph2.py");
   return 0;
}
