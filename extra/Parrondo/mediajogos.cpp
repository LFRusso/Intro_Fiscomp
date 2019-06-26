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
   int dinheiroA, dinheiroB, dinheiroC, dinheiroD;
   double medA, medB, medC, medD;
   double numero;
   int aux, aux2, aux3;
   ofstream dataC, dataA, dataB, dataD;
   dataC.open("Cmed.dat");
   dataA.open("Amed.dat");
   dataB.open("Bmed.dat");
   dataD.open("Dmed.dat");

   for (int jogtotais = 0; jogtotais <= 60; ++jogtotais){
      medA = 0;
      medB = 0;
      medC = 0;
      medD = 0;
      for (int jogos = 0; jogos <= 1000000; ++jogos){
         dinheiroA = 0;
         dinheiroB = 0;
         dinheiroC = 0;
	 dinheiroD = 0;
	 aux = 0;
	 aux2 = 0;
	 aux3 = 0;
         for (int i = 0; i <= jogtotais; ++i){
            A(dinheiroA);
            B(dinheiroB);
            C(dinheiroC);
	    if (aux % 2 == 0){
		    if (aux2 % 2 == 0){
		    	A(dinheiroD);
		    } else {
		    	B(dinheiroD);
		    }
		    aux2++;
	    } else {
		    if (aux3 % 2 == 0){
		    	A(dinheiroD);
		    } else {
		    	B(dinheiroD);
		    }
		    aux3++;
	    }
	    aux++;
	 }
         medA += double(dinheiroA)/double(1000000);
         medB += double(dinheiroB)/double(1000000);
         medC += double(dinheiroC)/double(1000000);
	 medD += double(dinheiroD)/double(1000000);
      }
      cout << jogtotais << endl;
      dataA << jogtotais << "\t" << medA << "\n";
      dataB << jogtotais << "\t" << medB << "\n";
      dataC << jogtotais << "\t" << medC << "\n";
      dataD << jogtotais << "\t" << medD << "\n";
   }



   dataC.close();
   dataB.close();
   dataA.close();
   dataD.close();
   system("python3 plot2.py");
   return 0;
}
