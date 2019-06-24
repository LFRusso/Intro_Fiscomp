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
   double med_x;
   double med_x2;
   double number;
   vector<double> X;
   vector<double> X2;
   vector<double> T;

   ofstream data;
   data.open("dados.dat");


   for (int t = 0; t <= 200; t++){
      while (erro <= 0.1) {
         for (int i = 0; i <= t; i++){
            number = (2*double(rand() % int(pow(10, 5)))/pow(10, 5)) - 1;
            x += number;
            x2 += pow(number, 2);
         }
         med_x  += x/t;
         med_x2 += x2/t;

      }
   }

   return 0;
}
