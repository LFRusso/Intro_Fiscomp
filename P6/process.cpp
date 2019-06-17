#include <omp.h>
#include <iostream>

int main(){

	std::cout <<  omp_get_num_procs() << std::endl;
	return 0;
}
