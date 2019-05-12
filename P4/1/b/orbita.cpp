// Programa para calcular órbita de todos os planetas do sistema solar, para a relação pedida entre A e Vy

#include <iostream>
#include <fstream>
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

	float Vx(){ // Método para retornar valor de Vx atual do planeta
		return _Vx;
	}

	float Vy(){ // Método para retornar valor de Vy atual do planeta
		return _Vy;
	}
};

int main()
{
	ofstream data;
	data.open("orbita.dat"); // Criando arquivo paras salvar dados

	float total_t = 10000; // Valor total do tempo, grande o bastante para garantir que todos os planetas realizarão ao menos algumas voltas
	float t = 0; // Tempo total transcorrido
	float dt = 0.01; // Passo temporal

	planet Mercurio(0.39, 0, 0, 1/sqrt(0.39), 0.055); // Defino o planeta Mercúrio
	planet Venus(0.72, 0, 0, 1/sqrt(0.72), 0.825); // Defino o planeta Venus
	planet Terra(1, 0, 0, 1, 1); // Defino o planeta Terra
	planet Marte(1.52, 0, 0, 1/sqrt(1.52), 0.107); // Defino o planeta Marte
	planet Jupiter(5.2, 0, 0, 1/sqrt(5.2), 318); // Defino o planeta Jupiter
	planet Saturno(9.58, 0, 0, 1/sqrt(9.58), 95.2); // Defino o planeta Saturno
	planet Urano(19.2, 0, 0, 1/sqrt(19.2), 14.5); // Defino o planeta Urano
	planet Netuno(30.1, 0, 0, 1/sqrt(30.1), 17.1); // Defino o planeta Netuno
	
	int n;
	n = int(total_t/dt);

	for(int i = 0; i <= n; i++){
		data << Mercurio.x() << " " << Mercurio.y() << " " << Venus.x() << " " <<  Venus.y() << " " << Terra.x() << " " << Terra.y() << " " << Marte.x() << " " << Marte.y() << " " << Jupiter.x() << " " << Jupiter.y() << " " << Saturno.x() << " " << Saturno.y() << " " << Urano.x() << " " << Urano.y() << " " << Netuno.x() << " " << Netuno.y() << "\n";
		// Acima, salvo os valores atuais de cada planeta em um arquivo

		Mercurio.iterate(dt);
		Venus.iterate(dt);
		Terra.iterate(dt);
		Marte.iterate(dt);
		Jupiter.iterate(dt);
		Saturno.iterate(dt);
		Urano.iterate(dt);
		Netuno.iterate(dt); // Itero todos os planetas com o passo temporal dt
		t += dt;
	}

	data.close();
	system("python3 orbita.py"); // Executo programa python para plotar resultados
	return 0;
}
