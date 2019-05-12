// Aplicação do método de Runge-Kutta 4 para três corpos

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
using namespace std;

class planet{ // Tipo de dado definido "planet", com membros armazenando os valores de cada objeto

	float _rhox;
	float _rhoy;
	float _Vx;
	float _Vy;
	float _mass;
	vector<float> _F1;
	vector<float> _F2;
	vector<float> _F3;
	vector<float> _F4;
	float _Ax;
	float _Ay;
	float Solar_Mass;

public: // Funções "públicas para o usuário"(que podem ser acessadas por fora da classe)

	planet(float rhox,float rhoy,float Vx,float Vy,float mass){ // Usado ao declarar o planeta; estabelece seus valores iniciais
		_rhox = rhox;
		_rhoy = rhoy;
		_Vx = Vx;
		_Vy = Vy;
		_mass = mass;
		_F1.reserve(4);
		_F2.reserve(4);
		_F3.reserve(4);
		_F4.reserve(4);
		Solar_Mass = 3.33 * pow(10, 5);
	}; 

	void Runge_Kutta(float dt){ // Método que itera as variáveis-membro do planeta pelo método Runge-Kutta
		_rhox = _rhox + dt*(_F1[0] + 2*_F1[1] + 2*_F1[2] + _F1[3])/6;
		_rhoy = _rhoy + dt*(_F2[0] + 2*_F2[1] + 2*_F2[2] + _F2[3])/6;
		_Vx = _Vx + dt*(_F3[0] + 2*_F3[1] + 2*_F3[2] + _F3[3])/6;
		_Vy = _Vy + dt*(_F4[0] + 2*_F4[1] + 2*_F4[2] + _F4[3])/6;
	}

	void Relate(planet Astro1, planet Astro2){ // Método Relate, que dado os outros dois astros, calcula as acelerações em x e y deste de acordo com as caracteristicas e posições dos outros em relação a este
		_Ax = (Astro2.M()/Solar_Mass)*(_rhox - Astro2.x())/(pow(pow(_rhox - Astro2.x(), 2) + pow(_rhoy - Astro2.y(), 2), 1.5)) + (Astro1.M()/Solar_Mass)*(_rhox - Astro1.x())/(pow(pow(_rhox - Astro1.x(), 2) + pow(_rhoy - Astro1.y(), 2), 1.5));
		_Ay = (Astro2.M()/Solar_Mass)*(_rhoy - Astro2.y())/(pow(pow(_rhox - Astro2.x(), 2) + pow(_rhoy - Astro2.y(), 2), 1.5)) + (Astro1.M()/Solar_Mass)*(_rhoy - Astro1.y())/(pow(pow(_rhox - Astro1.x(), 2) + pow(_rhoy - Astro1.y(), 2), 1.5));
	}

	void F1(int i,float val){ // Método para alterar o valor de F1, dado o índice e o novo valor
		_F1[i] = val;
	}

	float F1(int i){return _F1[i];} // Método para retornar o valor armazenado em dada cordenada de F1

	void F2(int i, float val){ // Método para alterar o valor de F2, dado o índice e o novo valor
		_F2[i] = val;
	}

	float F2(int i){return _F2[i];} // Método para retornar o valor armazenado em dada cordenada de F2

	void F3(int i, float val){ // Método para alterar o valor de F3, dado o índice e o novo valor
		_F3[i] = val;
	}

	float F3(int i){return _F3[i];}// Método para retornar o valor armazenado em dada cordenada de F3

	void F4(int i,float val){ // Método para alterar o valor de F4, dado o índice e o novo valor
		_F4[i] = val;
	}

	float F4(int i){return _F4[i];} // Método para retornar o valor armazenado em dada cordenada de F4

	float M(){return _mass;} // Método para retornar a massa do planeta

	float x(){return _rhox;} // Método para retornar Rx
	
	float y(){return _rhoy;} // Método para retornar Ry

	float Vx(){return _Vx;} // Método para retornar Vx

	float Vy(){return _Vy;} // Método para retornar Vy

	float Ax(){return _Ax;} // Método para retornar Ax

	float Ay(){return _Ay;} // Método para retornar Ay
};


// A função get_F definida abaixo recebe os três astros que devem ser considerados e calcula os valores de F para cada um deles
// Os astros devem ser passado por referência usando o &, pois a função ALTERA os valores de F deles como variáveis GLOBAIS, não apenas localmente
void get_F(float dt, planet& Astro1, planet& Astro2, planet& Astro3){
	float rhox_i_1, rhoy_i_1, rhox_i_2, rhoy_i_2, rhox_i_3, rhoy_i_3;
	float Vx_i_1, Vy_i_1, Vx_i_2, Vy_i_2, Vx_i_3, Vy_i_3;
	float Axi_1, Ayi_1, Axi_2, Ayi_2, Axi_3, Ayi_3;

	float Solar_Mass = 3.33 * pow(10, 5);
	vector<float> auxiliar;
	auxiliar.reserve(3);
	auxiliar[0] = 2;
	auxiliar[1] = 2;
	auxiliar[2] = 1;

	Astro1.F1(0, Astro1.Vx());
	Astro1.F2(0, Astro1.Vy());
	Astro1.F3(0, -Astro1.Ax());
	Astro1.F4(0, -Astro1.Ay());

	Astro2.F1(0, Astro2.Vx());
	Astro2.F2(0, Astro2.Vy());
	Astro2.F3(0, -Astro2.Ax());
	Astro2.F4(0, -Astro2.Ay());

	Astro3.F1(0,Astro3.Vx());
	Astro3.F2(0,Astro3.Vy());
	Astro3.F3(0,-Astro3.Ax());
	Astro3.F4(0,-Astro3.Ay());

	for (int i = 0; i < 3; i++){
		rhox_i_1 = Astro1.x() + (dt/auxiliar[i])*Astro1.F1(i);
		rhoy_i_1 = Astro1.y() + (dt/auxiliar[i])*Astro1.F2(i);
		Vx_i_1 =  Astro1.Vx() + (dt/auxiliar[i])*Astro1.F3(i);
		Vy_i_1 = Astro1.Vy() + (dt/auxiliar[i])*Astro1.F4(i);
		Astro1.F1(i+1, Vx_i_1);
		Astro1.F2(i+1, Vy_i_1);

		rhox_i_2 = Astro2.x() + (dt/auxiliar[i])*Astro2.F1(i);
		rhoy_i_2 = Astro2.y() + (dt/auxiliar[i])*Astro2.F2(i);
		Vx_i_2 =  Astro2.Vx() + (dt/auxiliar[i])*Astro2.F3(i);
		Vy_i_2 = Astro2.Vy() + (dt/auxiliar[i])*Astro2.F4(i);
		Astro2.F1(i+1, Vx_i_2);
		Astro2.F2(i+1, Vy_i_2);

		rhox_i_3 = Astro3.x() + (dt/auxiliar[i])*Astro3.F1(i);
		rhoy_i_3 = Astro3.y() + (dt/auxiliar[i])*Astro3.F2(i);
		Vx_i_3 =  Astro3.Vx() + (dt/auxiliar[i])*Astro3.F3(i);
		Vy_i_3 = Astro3.Vy() + (dt/auxiliar[i])*Astro3.F4(i);
		Astro3.F1(i+1, Vx_i_3);
		Astro3.F2(i+1, Vy_i_3);		

		Axi_1 = (Astro2.M()/Solar_Mass)*(rhox_i_1 - rhox_i_2)/(pow(pow(rhox_i_1 - rhox_i_2, 2) + pow(rhoy_i_1 - rhoy_i_2, 2), 1.5)) + (Astro3.M()/Solar_Mass)*(rhox_i_1 - rhox_i_3)/(pow(pow(rhox_i_1 - rhox_i_3, 2) + pow(rhoy_i_1 - rhoy_i_3, 2), 1.5));
		Ayi_1 = (Astro2.M()/Solar_Mass)*(rhoy_i_1 - rhoy_i_2)/(pow(pow(rhox_i_1 - rhox_i_2, 2) + pow(rhoy_i_1 - rhoy_i_2, 2), 1.5)) + (Astro3.M()/Solar_Mass)*(rhoy_i_1 - rhoy_i_3)/(pow(pow(rhox_i_1 - rhox_i_3, 2) + pow(rhoy_i_1 - rhoy_i_3, 2), 1.5));
		Astro1.F3(i+1, -Axi_1);
		Astro1.F4(i+1, -Ayi_1);

		Axi_2 = (Astro1.M()/Solar_Mass)*(rhox_i_2 - rhox_i_1)/(pow(pow(rhox_i_1 - rhox_i_2, 2) + pow(rhoy_i_1 - rhoy_i_2, 2), 1.5)) + (Astro3.M()/Solar_Mass)*(rhox_i_2 - rhox_i_3)/(pow(pow(rhox_i_2 - rhox_i_3, 2) + pow(rhoy_i_2 - rhoy_i_3, 2), 1.5));
		Ayi_2 = (Astro1.M()/Solar_Mass)*(rhoy_i_2 - rhoy_i_1)/(pow(pow(rhox_i_1 - rhox_i_2, 2) + pow(rhoy_i_1 - rhoy_i_2, 2), 1.5)) + (Astro3.M()/Solar_Mass)*(rhoy_i_2 - rhoy_i_3)/(pow(pow(rhox_i_2 - rhox_i_3, 2) + pow(rhoy_i_2 - rhoy_i_3, 2), 1.5));
		Astro2.F3(i+1, -Axi_2);
		Astro2.F4(i+1, -Ayi_2);
	
		Axi_3 = (Astro1.M()/Solar_Mass)*(rhox_i_3 - rhox_i_1)/(pow(pow(rhox_i_1 - rhox_i_3, 2) + pow(rhoy_i_1 - rhoy_i_3, 2), 1.5)) + (Astro2.M()/Solar_Mass)*(rhox_i_3 - rhox_i_2)/(pow(pow(rhox_i_2 - rhox_i_3, 2) + pow(rhoy_i_2 - rhoy_i_3, 2), 1.5));
		Ayi_3 = (Astro1.M()/Solar_Mass)*(rhoy_i_3 - rhoy_i_1)/(pow(pow(rhox_i_1 - rhox_i_3, 2) + pow(rhoy_i_1 - rhoy_i_3, 2), 1.5)) + (Astro2.M()/Solar_Mass)*(rhoy_i_3 - rhoy_i_2)/(pow(pow(rhox_i_2 - rhox_i_3, 2) + pow(rhoy_i_2 - rhoy_i_3, 2), 1.5));
		Astro3.F3(i+1, -Axi_3);
		Astro3.F4(i+1, -Ayi_3);
	}
}

int main()
{
	float total_time = 30;
	float dt = 0.012; // dt determinado como aproximadamente a média de dt_max para cada raio
	int n;
	n = 4*int(total_time/dt);
	ofstream data, data2;
	data.open("orbita.dat"); // Arquivo onde salvo a trajetória de todos astros
	data2.open("Rxt.dat"); // Arquivo onde salvo o raio R da Terra em função do tempo transcorrido
	float time = dt/4;
	float Sun_mass = 3.33 * pow(10, 5); // Definição da massa solar

	// Abaixo, a definição dos astros considerados
	planet Terra(1, 0, 0, 1, 1);
	planet Jupiter(5.2, 0, 0, 1/sqrt(5.2), 318);
	planet Sun(-1/Sun_mass - 1653.5/Sun_mass, 0, 0, sqrt(318)/Sun_mass, Sun_mass);

	for (int j=1; j <= n; j++){

		Terra.Relate(Jupiter, Sun);
		Sun.Relate(Terra, Jupiter);
		Jupiter.Relate(Terra, Sun); // Relaciono os astros entre si, obtendo a atual aceleração deles

		get_F(dt, Terra, Sun, Jupiter); // Obtenho os valores de F necessários para o RK4

		Terra.Runge_Kutta(dt);
		Jupiter.Runge_Kutta(dt);
		Sun.Runge_Kutta(dt); // Itero todos os astros, obtendo suas novas posições e velocidades

		data << Terra.x() << "\t" << Terra.y() << "\t" << Jupiter.x() << "\t" << Jupiter.y() << "\t" << Sun.x() << "\t" << Sun.y() << "\n";
		data2 << time << "\t" << sqrt(pow(Terra.x(), 2) + pow(Terra.y(),2)) << "\n";
		// Salvando resultados

		time += dt/4;
	}

	data2.close();
	data.close();
	system("python3 Rxt.py");	
	system("python3 orbita.py"); // Plotando resultados
	return 0;
}
