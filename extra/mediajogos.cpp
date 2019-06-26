#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

void A(int &dinheiro){
   double numero = double(rand() % int(pow(10, 5)))/pow(10, 5);
   if (numero <= 0.495){
      ++dinheiro;
   } else {
      --dinheiro;
   }
}

void B(int &dinheiro){
   double numero = double(rand() % int(pow(10, 5)))/pow(10, 5);
   if (dinheiro % 3 == 0){
      if (numero <= 0.095){
         ++dinheiro;
      } else {
         --dinheiro;
      }
   } else {
      if (numero <= 0.745){
         ++dinheiro;
      } else {
         --dinheiro;
      }
   }
}

void C(int &dinheiro){
   double numero = double(rand() % int(pow(10, 5)))/pow(10, 5);
   if (numero <= 0.5){
      A(dinheiro);
   } else {
      B(dinheiro);
   }
}

int main() {
   int dinheiroA, dinheiroB, dinheiroC;
   double medA, medB, medC;
   double numero;
   ofstream dataC, dataA, dataB;
   dataC.open("Cmed.dat");
   dataA.open("Amed.dat");
   dataB.open("Bmed.dat");

   for (int jogtotais = 0; jogtotais <= 60; ++jogtotais){
      medA = 0;
      medB = 0;
      medC = 0;
      for (int jogos = 0; jogos <= 100000; ++jogos){
         dinheiroA = 0;
         dinheiroB = 0;
         dinheiroC = 0;
         for (int i = 0; i <= jogtotais; ++i){
            A(dinheiroA);
            B(dinheiroB);
            C(dinheiroC);
         }
         medA += double(dinheiroA)/double(100000);
         medB += double(dinheiroB)/double(100000);
         medC += double(dinheiroC)/double(100000);
      }
      cout << jogtotais << endl;
      dataA << jogtotais << "\t" << medA << "\n";
      dataB << jogtotais << "\t" << medB << "\n";
      dataC << jogtotais << "\t" << medC << "\n";
   }



   dataC.close();
   dataB.close();
   dataA.close();
   system("python3 plot2.py");
   return 0;
}
