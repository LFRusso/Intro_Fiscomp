// Este programa possui exatamente a mesma classe, métodos e funções que os já descritos em 2c e 2b
// A única diferença está os parâmetros iniciais dos astros e seus nomes.

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
using namespace std;

class planet{

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

public:

	planet(float rhox,float rhoy,float Vx,float Vy,float mass){
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

	void Runge_Kutta(float dt){
		_rhox = _rhox + dt*(_F1[0] + 2*_F1[1] + 2*_F1[2] + _F1[3])/6;
		_rhoy = _rhoy + dt*(_F2[0] + 2*_F2[1] + 2*_F2[2] + _F2[3])/6;
		_Vx = _Vx + dt*(_F3[0] + 2*_F3[1] + 2*_F3[2] + _F3[3])/6;
		_Vy = _Vy + dt*(_F4[0] + 2*_F4[1] + 2*_F4[2] + _F4[3])/6;
	}

	void Relate(planet Astro1, planet Astro2){
		_Ax = (Astro2.M()/Solar_Mass)*(_rhox - Astro2.x())/(pow(pow(_rhox - Astro2.x(), 2) + pow(_rhoy - Astro2.y(), 2), 1.5)) + (Astro1.M()/Solar_Mass)*(_rhox - Astro1.x())/(pow(pow(_rhox - Astro1.x(), 2) + pow(_rhoy - Astro1.y(), 2), 1.5));
		_Ay = (Astro2.M()/Solar_Mass)*(_rhoy - Astro2.y())/(pow(pow(_rhox - Astro2.x(), 2) + pow(_rhoy - Astro2.y(), 2), 1.5)) + (Astro1.M()/Solar_Mass)*(_rhoy - Astro1.y())/(pow(pow(_rhox - Astro1.x(), 2) + pow(_rhoy - Astro1.y(), 2), 1.5));
	}

	void F1(int i,float val){
		_F1[i] = val;
	}

	float F1(int i){return _F1[i];}

	void F2(int i, float val){
		_F2[i] = val;
	}

	float F2(int i){return _F2[i];}

	void F3(int i, float val){
		_F3[i] = val;
	}

	float F3(int i){return _F3[i];}

	void F4(int i,float val){
		_F4[i] = val;
	}

	float F4(int i){return _F4[i];}

	float M(){return _mass;}

	float x(){return _rhox;}
	
	float y(){return _rhoy;}	

	float Vx(){return _Vx;}

	float Vy(){return _Vy;}

	float Ax(){return _Ax;}

	float Ay(){return _Ay;}
};

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
	float dt = 0.012;
	int n;
	n = 4*int(total_time/dt);
	ofstream data;
	data.open("orbita.dat");
	float time = dt/4;
	float Sun_mass = 3.33 * pow(10, 5);

	planet P1(0.97000436, -0.24308753, 0.466203685, 0.43236573, Sun_mass);
	planet P2(-0.97000436, 0.24308753, 0.466203685, 0.43236573, Sun_mass);
	planet P3(0, 0, -0.93240737, -0.86473146, Sun_mass);

	for (int j=1; j <= n; j++){

		P1.Relate(P2, P3);
		P3.Relate(P1, P2);
		P2.Relate(P1, P3);

		get_F(dt, P1, P2, P3);

		P1.Runge_Kutta(dt);
		P2.Runge_Kutta(dt);
		P3.Runge_Kutta(dt);

		data << P1.x() << "\t" << P1.y() << "\t" << P2.x() << "\t" << P2.y() << "\t" << P3.x() << "\t" << P3.y() << "\n";

		time += dt/4;
	}
	data.close();
	system("python3 orbita.py");
	return 0;
}
