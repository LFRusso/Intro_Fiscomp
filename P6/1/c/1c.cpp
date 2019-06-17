#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <omp.h>
#define k 100
using namespace std;

int main(){
   int S_in{0}, S_total{0};
   ofstream data;
   srand(42);
   double x, y;
   double E{1};
   data.open("data");
   int i = 0;

   #pragma omp parallel private(x, y, i) shared(S_in, S_total) num_threads(4)
   {
      #pragma omp for
      for (i = 0; i <= 10000000; i ++){
         x = (double(rand() % int(pow(10, 5)))/pow(10, 5))*2 - 1;
         y = (double(rand() % int(pow(10, 5)))/pow(10, 5))*2 - 1;
         if(pow(x,2)+pow(y,2) <= 1){
            ++S_in;
         }
         ++S_total;
      }
   }
   cout << (double(S_in)/double(S_total))*4 << endl;
   data.close();
   //system("python3 graph.py");
   return 0;
}
