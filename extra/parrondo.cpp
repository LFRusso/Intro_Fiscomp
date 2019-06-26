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

int main() {
   int dinheiro;
   double numero;
   ofstream dataC, dataA, dataB;
   dataC.open("C.dat");
   dataA.open("A.dat");
   dataB.open("B.dat");

   for (int jogo = 0; jogo <= 50000; jogo++){
      dinheiro = 0;
      for (int jogada = 0; jogada <= 1000; jogada++){
         numero = double(rand() % int(pow(10, 5)))/pow(10, 5);
         if(numero <= 0.5){
            A(dinheiro);
         } else {
            B(dinheiro);
         }
      }
      dataC << dinheiro << "\n";
   }

   for (int jogo = 0; jogo <= 50000; jogo++){
      dinheiro = 0;
      for (int jogada = 0; jogada <= 1000; jogada++){
         A(dinheiro);
      }
      dataA << dinheiro << "\n";
   }

   for (int jogo = 0; jogo <= 50000; jogo++){
      dinheiro = 0;
      for (int jogada = 0; jogada <= 1000; jogada++){
         B(dinheiro);
      }
      dataB << dinheiro << "\n";
   }



   dataC.close();
   dataB.close();
   dataA.close();
   system("python3 plot.py");
   return 0;
}
