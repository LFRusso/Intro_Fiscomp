#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
using namespace std;

double dxdt(double x, double y){ // Função derivada de x no tempo
	double a = double(2)/double(3);
	double b = double(4)/double(3);
	return a*x - b*x*y;
}

double dydt(double x, double y){ // Função derivada de y no tempo
	double c = 1;
	double d = 1;
	return -c*y + d*x*y;
}

int main(){
	ofstream data;
	vector<double> Vx(4);
	vector<double> Vy(4);
	double total_time = 5; // tempo total em anos
	double dt = 0.001; // intervalo de tempo dt
	double time = 0; // tempo transcorrido
	double x, y;
	int n;
	data.open("dados.dat");

	n = int(total_time/dt); // numero de iterações
	x = 10; // numero inicial de presas
	y = 2; // numero inicial de predadores
	for(int i = 0; i <= n; i++){
		time += dt; // acresso o tempo em dt

		// implementação do método de Runge-Kutta 4
		Vx[0] = dxdt(x, y);
		Vy[0] = dydt(x, y);

    	Vx[1] = dxdt(x + 0.5*dt*Vx[0], y + 0.5*dt*Vy[0]);
    	Vy[1] = dydt(x + 0.5*dt*Vx[0], y + 0.5*dt*Vy[0]);

    	Vx[2] = dxdt(x + 0.5*dt*Vx[1], y + 0.5*dt*Vy[1]);
    	Vy[2] = dydt(x + 0.5*dt*Vx[1], y + 0.5*dt*Vy[1]);

    	Vx[3] = dxdt(x + dt*Vx[2], y + dt*Vy[2]);
    	Vy[3] = dydt(x + dt*Vx[2], y + dt*Vy[2]);

		x += (dt/6) * (Vx[0] + 2*Vx[1] + 2*Vx[2] + Vx[3]); // iteração de x
		y += (dt/6) * (Vy[0] + 2*Vy[1] + 2*Vy[2] + Vy[3]); // iteração de y
		// 

		data << time << "\t" << x << "\t" << y << endl; // salvando valores num arquivo
	}
	system("python3 graph.py"); // plot do gráfico

	return 0;
}