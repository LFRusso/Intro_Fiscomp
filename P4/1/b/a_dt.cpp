// Programa para variar A e calcular valor de dt_max equivalente
// ATENÇÃO: pode demorar, príncipalmente para A's pequenos

#include <iostream>
#include <fstream>
#include <cmath>
#include <cmath>
#include <stdlib.h>
using namespace std;

class planet{ // Tipo de dado definido "planet", com membros armazenando os valores de cada objeto
	float _rhox;
	float _rhoy;
	float _Vx;
	float _Vy;
	float _mass;
public: // Funções "públicas para o usuário"(que podem ser acessadas por fora da classe)
	planet(float rhox,float rhoy,float Vx,float Vy,float mass){ // Usado ao declarar o planeta; estabelece seus valores iniciais
		_rhox = rhox;
		_rhoy = rhoy;
		_Vx = Vx;
		_Vy = Vy;
		_mass = mass;
	}; 

	void iterate(float dt){ // Método que itera as variáveis-membro do planeta pelo método de Euler-Cromer
		_rhox = _rhox + _Vx*dt;
		_rhoy = _rhoy + _Vy*dt;
		_Vx = _Vx - (_rhox/pow(sqrt(pow(_rhox,2) + pow(_rhoy,2)),3))*dt;
		_Vy = _Vy - (_rhoy/pow(sqrt(pow(_rhox,2) + pow(_rhoy,2)),3))*dt;
	}

	float x(){ // Método para retornar valor de Rx atual do planeta
		return _rhox;
	}
	
	float y(){ // Método para retornar valor de Ry atual do planeta
		return _rhoy;
	}	
};

int main()
{
	float rho_max = 0;
	float rho_min = 99;
	float delta = 1;
	float rho;
	float dt = 0;
	ofstream data;
	data.open("a_dt.dat"); // Criando arquivo paras salvar dados
	float total_time = 1000;
	int n;
	float a = 0.5;
	for (int i = 1; i <= 100; i++){ // Loop para variar A
		a += 0.1;
		dt = 0.8; // dt inicial suficientemente grande, pare ser diminuído até encontrar o desejado
		delta = 1;
		cout << a << endl; // Escrevo no terminal o valor de A que está sendo calculado, para maior controle do andamento do programa (visto que pode demorar um pouco)
		while (delta >= pow(10, -3)){ // Loop diminuindo valor de dt até que seja obtido o delta <= 10E-3 desejado
			dt -= 0.0002;
			planet terra(a, 0, 0,1/sqrt(a), 1);
			rho_max = 0;
			rho_min = 99;
			n = int(total_time/dt); // Retornando variáveis ao estado inicial para o próximo loop
			for (int j = 1; j <= n; j++){ // Loop para iterar planeta ao longo a órbita, obtendo R_max e R_min para calcular delta
				terra.iterate(dt);
				rho = sqrt(pow(terra.x(), 2) + pow(terra.y(), 2));
				if (rho > rho_max){rho_max = rho;}
				if (rho < rho_min){rho_min = rho;}
				delta = rho_max/rho_min - 1;
			}
		}
		data << a << "\t" << dt << "\n"; // Salvando resultados em um arquivo
	}
	data.close();
	system("python3 a_dt.py"); // plotando resultados

	return 0;
}
