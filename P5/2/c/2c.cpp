#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

float G(float x,float r){
   return r*x*(1 - x); // Função G(x, r)
}


// Mesmo progrma que em 2.b, mudando apenas o intervalo de r (para que possamos determinar com maior precisão os pontos de divisão)
int main(){
   float r = 0;
   float x;
   ofstream data;
   data.open("pontos");
   for (int i=1; i <= 5000; i++){
      x = 0.5;
      r = 3.52 + (3.58 - 3.52)*float(i)/5000;
      for (int j = 0; j <= 300; j++){
         x = G(x,r);
      }
      for (int j = 0; j <= 990; j++){
         data << r << "\t" << x << "\n";
         x = G(x, r);
      }
   }
   system("python3 pontos.py");
   return 0;
}
