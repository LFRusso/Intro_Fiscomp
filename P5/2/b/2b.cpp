#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
using namespace std;

float G(float x,float r){
   return r*x*(1 - x); // Função G(x, r)
}

int main(){
   float r = 0; // valor inicial de r
   float x;
   ofstream data;
   data.open("pontos");
   for (int i=1; i <= 5000; i++){
      x = 0.5; // retorna valor de x0
      r = 2 + 2*float(i)/5000; // próximo valor de r. Pode ser alterado de acordo com o intervalo desejado
      for (int j = 0; j <= 100; j++){ // itera x para que ele se "estabilize"
         x = G(x,r);
      }
      for (int j = 0; j <= 1000; j++){ // itera para salvar pontos
         data << r << "\t" << x << "\n"; // salvando valores de r e x
         x = G(x, r); // iterando x
      }
   }
   system("python3 pontos.py"); // script para plot do gráfico
   return 0;
}
