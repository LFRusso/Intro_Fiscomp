// Programa para demonstrar que valor de dt que resulta em uma excentricidade de 10E-3 para órbita terrestre é 0.0009
// AVISO: Pode demorar para executrar, uma vez que um número grande de iterações é realizado para a demonstração

#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>

using namespace std;

float rho_y(float rho_yi, float Vyi, float delta_tau) // Função para calcular próxima iteração de Ry
{
   return rho_yi + Vyi*delta_tau;
}

float rho_x(float rho_xi, float Vxi, float delta_tau) // Função para calcular próxima iteração de Rx
{
   return rho_xi + Vxi*delta_tau;
}

float Vy(float Vyi, float rho_xi, float rho_yi, float delta_tau) // Função para calcular próxima iteração de Vy
{
   return Vyi - (rho_yi/pow((sqrt(pow(rho_xi,2) + pow(rho_yi,2))),3))*delta_tau;
}

float Vx(float Vxi, float rho_xi, float rho_yi, float delta_tau) // Função para calcular próxima iteração de Vx
{
   return Vxi - (rho_xi/pow((sqrt(pow(rho_xi,2) + pow(rho_yi,2))),3))*delta_tau;
}


int main()
{
   ofstream dados;
   dados.open("excentr.dat"); // Criando arquivo paras salvar dados
   float tau = 1000; // tempo total (deve ser considerávelmente grande para a demonstração)
   float delta_tau = 0.0009; // valor de dt para o qual delta <= 10E-3
   float rho_xi = 1; // Valor inicial de Rx
   float rho_yi = 0; // Valor inicial de Ry
   float Vxi = 0; // Valor inicial de Vx
   float Vyi = 1/sqrt(rho_xi); // Valor inicial de Vy

   int n;
   n = int(tau/delta_tau);

   for(int i=0; i <= n; i++)
   {
      Vyi = Vy(Vyi, rho_xi, rho_yi, delta_tau);
      Vxi = Vx(Vxi, rho_xi, rho_yi, delta_tau);

      rho_yi = rho_y(rho_yi, Vyi, delta_tau);
      rho_xi = rho_x(rho_xi, Vxi, delta_tau); // Calculo das iterações
      dados << rho_xi << "\t" << rho_yi << "\t" << tau << "\n"; // Salvando dados no arquivo
      tau += delta_tau;
   }
   dados.close();
   system("python3 excentr.py"); // Executando programa para plotar resultados
   return 0;
}
