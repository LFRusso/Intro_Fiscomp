// programa para o cálculo e plot dos histogramas para diferentes valores de t

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
   double P;
   double number;
   int t;

   ofstream data1, data2, data3;
   data1.open("dados1.dat");
   data2.open("dados2.dat");
   data3.open("dados3.dat");

   // caso t = 50
   t = 50;
   for (int k = 0; k <= 10000; k++){ // criação das amostras
      P = 0;
      for (int j = 0; j <= t; j++){ // loop relacionado ao deslocamento de cada amostra
         number = (2*double(rand() % int(pow(10, 5)))/pow(10, 5)) - 1;
         P += number;
      }
      data1 << P << "\n";
   }

   // caso t = 100
   t = 100;
   for (int k = 0; k <= 10000; k++){ // criação das amostras
      P = 0;
      for (int j = 0; j <= t; j++){ // loop relacionado ao deslocamento de cada amostra
         number = (2*double(rand() % int(pow(10, 5)))/pow(10, 5)) - 1;
         P += number;
      }
      data2 << P << "\n";
   }

   // caso t = 200
   t = 200;
   for (int k = 0; k <= 10000; k++){ // criação das amostras
      P = 0;
      for (int j = 0; j <= t; j++){ // loop relacionado ao deslocamento de cada amostra
         number = (2*double(rand() % int(pow(10, 5)))/pow(10, 5)) - 1;
         P += number;
      }
      data3 << P << "\n";
   }


   cout << "\nCarregando gráfico..." << endl;
   data1.close();
   data2.close();
   data3.close();
   system("python3 graph.py"); // gráfico dos resultados

   return 0;
}
