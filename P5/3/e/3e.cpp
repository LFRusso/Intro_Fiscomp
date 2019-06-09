#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
using namespace std;

double dxdt(double x, double y){
	double a = 0.481;
	double b = 0.025;
	return a*x - b*x*y;
}

double dydt(double x, double y){
	double c = 0.927;
	double d = 0.028;
	return -c*y + d*x*y;
}

int main(){
	ofstream data;
	vector<double> Vx(4);
	vector<double> Vy(4);
	double total_time = 20;
	double dt = 0.001;
	double time = 0;
	double x, y;
	int n;
	int auxiliar = 0;
	data.open("dados.dat");

	n = int(total_time/dt);
	x = 30;
	y = 4;
	cout << "Ano" << "\t" << "Lebre" << "\t" << "Lince" << endl;
	cout << 1900 << "\t" << 30 << "\t" << 4 << endl;
	for(int i = 0; i <= n; i++){
		time += dt;
		++auxiliar;
		
		if (auxiliar == int(1/dt)){
			cout << 1901+int(time) << "\t" << x << "\t" << y << endl;
			auxiliar = 0;
		}


		Vx[0] = dxdt(x, y);
		Vy[0] = dydt(x, y);

    	Vx[1] = dxdt(x + 0.5*dt*Vx[0], y + 0.5*dt*Vy[0]);
    	Vy[1] = dydt(x + 0.5*dt*Vx[0], y + 0.5*dt*Vy[0]);

    	Vx[2] = dxdt(x + 0.5*dt*Vx[1], y + 0.5*dt*Vy[1]);
    	Vy[2] = dydt(x + 0.5*dt*Vx[1], y + 0.5*dt*Vy[1]);

    	Vx[3] = dxdt(x + dt*Vx[2], y + dt*Vy[2]);
    	Vy[3] = dydt(x + dt*Vx[2], y + dt*Vy[2]);

		x += (dt/6) * (Vx[0] + 2*Vx[1] + 2*Vx[2] + Vx[3]);
		y += (dt/6) * (Vy[0] + 2*Vy[1] + 2*Vy[2] + Vy[3]);

		data << time << "\t" << x << "\t" << y << endl;
	}
	system("python3 graph.py");

	return 0;
}