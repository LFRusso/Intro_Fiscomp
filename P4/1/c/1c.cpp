// Programa implementando o método de Runge-Kutta para a iteração dos membros da classe planeta

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
using namespace std;

class planet{ // Tipo de dado definido "planet", com membros armazenando os valores de cada objeto
	float _rhox;
	float _rhox_i;
	float _rhoy;
	float _rhoy_i;
	float _Vx;
	float _Vx_i;
	float _Vy;
	float _Vy_i;
	float _mass;
	vector<float> _F1;
	vector<float> _F2;
	vector<float> _F3;
	vector<float> _F4;
	vector<float> _auxiliar;

public: // Funções "públicas para o usuário"(que podem ser acessadas por fora da classe)
	planet(float rhox,float rhoy,float Vx,float Vy,float mass){ // Usado ao declarar o planeta; estabelece seus valores iniciais
		_rhox = rhox;
		_rhoy = rhoy;
		_Vx = Vx;
		_Vy = Vy;
		_mass = mass;
		_auxiliar.reserve(3);
		_auxiliar[0] = 2;
		_auxiliar[1] = 2;
		_auxiliar[2] = 1;
		_F1.reserve(4);
		_F2.reserve(4);
		_F3.reserve(4);
		_F4.reserve(4);
	}; 

	void Runge_Kutta(float dt){ // Método que itera as variáveis-membro do planeta pelo método Runge-Kutta
		get_F(dt); // Obtenhos os valores necessários de F para RK4
		_rhox = _rhox + dt*(_F1[0] + 2*_F1[1] + 2*_F1[2] + _F1[3])/6;
		_rhoy = _rhoy + dt*(_F2[0] + 2*_F2[1] + 2*_F2[2] + _F2[3])/6;
		_Vx = _Vx + dt*(_F3[0] + 2*_F3[1] + 2*_F3[2] + _F3[3])/6;
		_Vy = _Vy + dt*(_F4[0] + 2*_F4[1] + 2*_F4[2] + _F4[3])/6;
	}

	void get_F(float dt){ // Função obtendo os valores de F através da posição e velocidade atuais do planeta
		_F1[0] = _Vx;
		_F2[0] = _Vy;
		_F3[0] = -_rhox/(pow(pow(_rhox,2)+pow(_rhoy,2),1.5));
		_F4[0] = -_rhoy/(pow(pow(_rhox,2)+pow(_rhoy,2),1.5));
		for (int i = 0; i < 3; i++){
			_rhox_i = _rhox + (dt/_auxiliar[i])*_F1[i];
			_rhoy_i = _rhoy + (dt/_auxiliar[i])*_F2[i];
			_Vx_i = _Vx + (dt/_auxiliar[i])*_F3[i];
			_Vy_i = _Vy + (dt/_auxiliar[i])*_F4[i];
			_F1[i+1] = _Vx_i;
			_F2[i+1] = _Vy_i;
			_F3[i+1] = -_rhox_i/(pow(pow(_rhox_i,2)+pow(_rhoy_i,2),1.5));
			_F4[i+1] = -_rhoy_i/(pow(pow(_rhox_i,2)+pow(_rhoy_i,2),1.5));	
		}
	}

	float x(){ // Método para retornar valor de Rx atual do planeta
		return _rhox;
	}
	
	float y(){ // Método para retornar valor de Ry atual do planeta
		return _rhoy;
	}	

	float Vx(){ // Método para retornar valor de Vx atual do planeta
		return _Vx;
	}

	float Vy(){ // Método para retornar valor de Vy atual do planeta
		return _Vy;
	}
};

int main()
{
	float total_time = 100;
	planet Terra(1, 0, 0, 1, 1);
	float dt = 0.01;
	int n;
	n = int(total_time/dt);
	ofstream data, data2;
	data.open("orbita_RK.dat"); // arquivo onde salvarei Rxt e Vxt, pedidos no exercício
	data2.open("trajec.dat"); // arquivo onde salvarei a órbita do planeta, apenas para checar
	float time = dt;

	for (int i=1; i <= n; i++){
		Terra.Runge_Kutta(dt); // Iterando planeta pelo método RK4
		data << sqrt(pow(Terra.x(), 2) + pow(Terra.Vx(), 2)) << "\t" << sqrt(pow(Terra.x(), 2) + pow(Terra.Vy(), 2)) << "\t" << time <<"\n";
		data2 << Terra.x() << "\t" << Terra.y() << "\n";
		// Acima salvo os valores obtidos nos arquivos

		time += dt;
	}
	data.close();
	data2.close();
	system("python3 orbita_RK.py"); // ploto gráfico pedido no exercício
	system("python3 trajec.py"); // ploto gráfico da trajetória
	return 0;
}
