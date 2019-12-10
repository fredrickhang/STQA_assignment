#include"inputMethod.h"
#include <random>
#include <chrono>
#include <iostream>
#include<ctime>
#include <map>
#include <iomanip>
double random_unint(unsigned int min, unsigned int max, unsigned int seed = 0)
{
	static std::default_random_engine e(seed);
	static std::uniform_real_distribution<double> u(0, 10);
	return u(e);
}
int main() {
	inputMethod();
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine gen(seed);
	std::normal_distribution<double> dis(10, 1);
	for (int i = 0; i < 20;i++) {
	//	std::cout<<abs(dis(gen))<<"\n";

	}

	//double cls_random::randomExponential(
	//	double lambda)
	//{
	/*for () {
		double pV = 0.0;
		while (true)
		{
			pV = (double)rand() / (double)RAND_MAX;
			if (pV != 1)
			{
				break;
			}
		}
		pV = (-1.0 / 1) * log(1 - pV);
		std::cout << pV * 1000 << "\n";
	
	}*/

	
		
		//return pV;
	//}
	std::random_device rd;
	std::exponential_distribution<>rng(1 / 0.1);
	std::mt19937 rnd_gen(rd());

	for (int k = 0; k < 500; k++) {

		std::cout << rng(rnd_gen) * 1000<<"\n";
	}
	//int x = 0;
	//double cdf = 0;
	//double lambda = 0.2;
	//double u;
	//
	//
	//
	//	u = random_unint(0, 4, time(NULL));
	//	while (u >= cdf) {
	//		x++;
	//		cdf = 1 - exp(-1.0 * lambda * x);
	//		std::cout << cdf << "\n";
	//	}
	//	
	//}
	//	

	
	

	return 0;
}



