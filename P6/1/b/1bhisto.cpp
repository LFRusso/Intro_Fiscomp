// programa para construção dos histogramas

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
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

   double average(){
      double som = 0;
      for (int i = 0; i <= _size; i++){
         som += _elements[i];
      }
      return som/_size;
   }

   double stdev(){
      double dev = 0;
      for (int i=0; i<=_size; i++){
         dev += pow(_elements[i] - average(),2);
      }
      dev = sqrt(dev/_size);
      return dev;
   }
};

int main(){
   double number;
   int k{100};
   srand(45);

   ofstream data, data2;
   data.open("rmed.dat");

   for(int m = 2; m <= 4; ++m){ // loop variando tamanho dos vetores
      for(int i = 1; i <= k; ++i){ // loop criando os k vetores
         distribuction *V = new distribuction(int(pow(3, m)));
         for(int j = 0; j <= int(pow(3, m)); ++j){ // loop preenchendo os k vetores com números aleatórios
            number = double(rand() % int(pow(10, 5)))/pow(10, 5);
            V -> add(number);
         }
         data.precision(2);
         data << pow(3, m) << "\t" << V->average() << "\n";
      }
   }

   data.close();
   system("python3 graph.py");
   return 0;
}
