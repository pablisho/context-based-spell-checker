#include "perceptron.h"
#include <iostream>
#include "outputNeuron.h"

int main(int argc, char* argv[]){
	
	Perceptron p(5,2,1);
	std::vector<double> input;
	std::cout << "Iniciando" << std::endl;
	input.push_back(1);
	input.push_back(0);
	for (int i = 0; i < 20000; i++){
		input[0] = 1;
		input[1] = 1;
		p.teach(input, -1);

		input[0] = -1;
		input[1] = 1;
		p.teach(input, 1);

		input[0] = 1;
		input[1] = -1;
		p.teach(input, 1);

		input[0] = -1;
		input[1] = -1;
		p.teach(input, -1);

	}

	input[0] = 1;
	input[1] = 1;
	double output = p.getOutput(input);
	std::cout << "1 + 1 = " << output << std::endl;

	input[0] = -1;
	input[1] = 1;
	output = p.getOutput(input);
	std::cout << "0 + 1 = " << output << std::endl;

	input[0] = 1;
	input[1] = -1;
	output = p.getOutput(input);
	std::cout << "1 + 0 = " << output << std::endl;

	input[0] = -1;
	input[1] = -1;
	output = p.getOutput(input);
	std::cout << "0 + 0 = " << output << std::endl;

	std::cout << "RUNNING EXAMPLE" << std::endl;
	return 0;
}
