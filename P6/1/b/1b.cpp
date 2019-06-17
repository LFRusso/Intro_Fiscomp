#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#define k 100
using namespace std;

class distribuction{
   int _size;
   vector<double> _elements;
public:
   distribuction(int size){
      _size = size;
      _elements.reserve(size);
   };
   void add(double number){
      _elements.push_back(number);
   }

   vector<double> display(){
      return _elements;
   }
};

int main(){
   double med;
   double stdev;
   double number;
   srand(42);

   ofstream data, data2;
   data.open("rmed.dat");
   data2.open("desvio.dat");

   for(int m = 2; m <= 4; ++m){ // loop variando tamanho dos vetores
      for(int i = 1; i <= k; ++i){ // loop criando os k vetores
         distribuction *V = new distribuction(int(pow(3, m)));
         med = 0;
         stdev = 0;
         for(int j = 0; j <= int(pow(3, m)); ++j){ // loop preenchendo os k vetores com números aleatórios
            number = double(rand() % int(pow(10, 5)))/pow(10, 5);
            med += number;
            V -> add(number);
         }
         med = med/pow(3, m);

         for(int x = 0; x <= int(pow(3, m)); ++x){
            stdev += pow((V -> display()[x]) - med,2);
         }
         stdev = sqrt(stdev/pow(3, m));

         data.precision(4);
         data << pow(3, m) << "\t" << stdev << "\t" << med << "\n";


      }
   }
   data.close();
   system("python3 graph.py");
   return 0;
}
