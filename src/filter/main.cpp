#include <iostream>
#include "simulate.hpp"
#include <string>
#include <sstream>

int main(int argc, const char * argv[])
{
	std::cout << "hello world!\n\n";

	Simulator simulator;
	Measurement currentMeas;
	for (size_t i = 0; i <= 50; i++) {
		std::cout << "Step: " << i << "\n";
		std::cout << "Current noisy position value: " << currentMeas.noisyPosition << "\n";
		std::cout << "Current true position value: " << currentMeas.truePosition << "\n";
		std::cout << "Current true velocity value: " << currentMeas.trueVelocity << "\n\n";
		currentMeas = simulator.step();
	}


	return 0;
}
