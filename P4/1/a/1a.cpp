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

float Vy(float Vyi, float rho_xi, float rho_yi, float delta_tau) // Função para calcular próxima iteração Vy
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
   dados.open("dados.dat"); // Criando arquivo paras salvar dados
   float total_tau = 100; // tempo total
   float delta_tau = 0.001; // passo temporal
   float rho_xi = 1; // Valor inicial de Rx
   float rho_yi = 0; // Valor inicial de Ry
   float Vxi = 0; // Valor inicial de Vx
   float Vyi = 1/sqrt(rho_xi); // Valor iniical de Vy
   float tau = delta_tau; // Tempo transcorrido

   int n;
   n = int(total_tau/delta_tau);

   for(int i=0; i <= n; i++)
   {
      rho_yi = rho_y(rho_yi, Vyi, delta_tau);
      rho_xi = rho_x(rho_xi, Vxi, delta_tau);

      Vyi = Vy(Vyi, rho_xi, rho_yi, delta_tau);
      Vxi = Vx(Vxi, rho_xi, rho_yi, delta_tau); // Calculando valores da iteração

      dados << sqrt(pow(rho_xi,2) + pow(rho_yi,2)) << "\t" << sqrt(pow(Vxi, 2) + pow(Vyi, 2)) << "\t" << tau << "\n"; // Salvando dados
      tau += delta_tau;
   }
   dados.close();
   system("python3 graph.py"); // Executa programa em python para plotar gráfico
   return 0;
}
