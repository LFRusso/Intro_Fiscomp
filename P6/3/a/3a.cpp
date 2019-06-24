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

   t = 50;
   for (int k = 0; k <= 10000; k++){
      P = 0;
      for (int j = 0; j <= t; j++){
         number = (2*double(rand() % int(pow(10, 5)))/pow(10, 5)) - 1;
         P += number;
      }
      data1 << P << "\n";
   }

   t = 100;
   for (int k = 0; k <= 10000; k++){
      P = 0;
      for (int j = 0; j <= t; j++){
         number = (2*double(rand() % int(pow(10, 5)))/pow(10, 5)) - 1;
         P += number;
      }
      data2 << P << "\n";
   }

   t = 200;
   for (int k = 0; k <= 10000; k++){
      P = 0;
      for (int j = 0; j <= t; j++){
         number = (2*double(rand() % int(pow(10, 5)))/pow(10, 5)) - 1;
         P += number;
      }
      data3 << P << "\n";
   }

   data1.close();
   data2.close();
   data3.close();
   system("python3 graph.py");

   return 0;
}
