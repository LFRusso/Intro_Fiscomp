#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#define k 100
using namespace std;

int main(){
   int S_in{0};
   srand(42);
   double x, y, med;
   double E{1};
   int count{0};
   vector<double> Pi_Values;
   Pi_Values.reserve(100);

      while(E >= pow(10, -4)){ // condição de parada: erro menor que 10E-4
         ++count;
         med = 0;
         E = 1;
         for(int i = 0; i<= 100; ++i){ // loop gerando 100 conjuntos de vetores
            S_in = 0;
            for(int j = 0; j <= pow(2, count); j++){ // loop gerando um número variável de vetores
               x = 2*double(rand() % int(pow(10, 5)))/pow(10, 5) - 1;
               y = 2*double(rand() % int(pow(10, 5)))/pow(10, 5) - 1;
               if(pow(x, 2) + pow(y, 2) <= 1){ // condição para estar dentro
                  S_in++;
               }
            }
            Pi_Values[i] = 4*double(S_in)/pow(2, count); // lista com os "valores de pi" encontrados
         }

         for(int i =0; i <= 100; i++){ // cálculo da média
            med += Pi_Values[i];
         }
         med /= 100;
         for(int i; i <= 100; i++){ // cálculo do desvio padrão/erro da medida
            E +=pow(Pi_Values[i] - med, 2);
         }
         E = sqrt(E/100);
         cout << "números: 2^" << count << endl; // para acompanhamento da operação
      }
   cout << "Valor final:" << "\n" << "n = 2^" << count << "\n" << "pi = " << med << "+/-" << E << endl;
   return 0;
}
