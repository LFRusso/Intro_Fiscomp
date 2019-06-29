// programa para cálculo do deslocamento médio e quadrático médio ao longo do tempo

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
   double x;
   double x2;
   double stdev_x;
   double stdev_x2;
   double med_x, total_med_x;
   double med_x2, total_med_x2;
   double number;
   vector<double> Meds_X;
   vector<double> Meds_X2;
   vector<double> X;
   vector<double> X2;
   int k{0};
   X.reserve(100000000);
   X2.reserve(100000000);

   ofstream data;
   data.open("dadosK.dat");


   for (int t = 0; t <= 200; t++){ // loop variando o período de tempo
      k = 1;
      stdev_x = 1;
      stdev_x2 = 1;
      while (stdev_x > 0.1 or stdev_x2 >0.1) { // condição de parada: erro de 10% satisfeito para ambos os deslocamentos
         total_med_x = 0;
         total_med_x2 = 0;
         stdev_x = 0;
         stdev_x2 = 0;
         for(int w=0; w<=k; ++w){ // criação de k amostras
            med_x = 0;
            med_x2 = 0;
            for (int i = 0; i <= t; i++){ // cálculo dos deslocamentos médios
               number = (2*double(rand() % int(pow(10, 5)))/pow(10, 5)) - 1;
               med_x += number;
               med_x2 += pow(number, 2);
            }
            med_x  = med_x/t;
            med_x2 = med_x2/t;

            total_med_x += med_x;
            total_med_x2 += med_x2;

            X[w] = med_x;
            X2[w] = med_x2;
         }
         total_med_x = total_med_x/double(k+1);
         total_med_x2 = total_med_x2/double(k+1);

         for(int i=0; i<=k; i++){ // cálculo do desvio padrão relacionado às médias
            stdev_x = pow(total_med_x - X[i], 2);
            stdev_x2 = pow(total_med_x2 - X2[i], 2);
         }

         stdev_x = sqrt(stdev_x/double(k));
         stdev_x2 = sqrt(stdev_x2/double(k));

         k++; // incremento de k (até satisfazer condição de parada)
      }
      data << t << "\t" << total_med_x << "\t" << total_med_x2 << "\t" << k << "\n";
   }

   data.close();
   system("python3 graph2.py"); // gráfico dos resultados
   return 0;
}
