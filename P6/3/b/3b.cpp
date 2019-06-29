#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	ofstream data;
   double y;
   double x;
   double r2;
   double stdev_r2;
   double med_r2, total_med_r2;
   double number;
   vector<double> Meds_R2;
   vector<double> R2;
   int k{0};
   R2.reserve(100000000);

	data.open("dados.dat");

   for (int t = 0; t <= 200; t++){
      k = 1;
      stdev_r2 = 1;
      while (stdev_r2 > 0.01) {
         total_med_r2 = 0;
         stdev_r2 = 0;
         for(int w=0; w<=k; ++w){
            med_r2 = 0;
            for (int i = 0; i <= t; i++){
               x = (2*double(rand() % int(pow(10, 5)))/pow(10, 5)) - 1;
               y = (2*double(rand() % int(pow(10, 5)))/pow(10, 5)) - 1;
               med_r2 += pow(x, 2) + pow(y, 2);
            }
            med_r2 = med_r2/t;
            total_med_r2 += med_r2;
            R2[w] = med_r2;
         }
         total_med_r2 = total_med_r2/double(k);

         for(int i=0; i<=k; i++){
            stdev_r2 = pow(total_med_r2 - R2[i], 2);
         }

         stdev_r2 = sqrt(stdev_r2/double(k));

         k++;
      }
      data << t << "\t" << total_med_r2 << "\t" << k << "\n";
   }	

	data.close();
	system("python3 graph.py");
	return 0;
}