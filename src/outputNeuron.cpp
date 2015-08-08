#include "outputNeuron.h"
#include <iostream>
#include <cmath>

OutputNeuron::OutputNeuron(int inputNumber) : PerceptronNeuron(inputNumber){
}

OutputNeuron::OutputNeuron(int inputNumber, double b) : PerceptronNeuron(inputNumber, b){
}

OutputNeuron::~OutputNeuron(){
}

std::vector<double> OutputNeuron::teach(std::vector<double>& input, double desiredOutput){
	std::vector<double> backpropagation;
	if (input.size() != inputNumber){
		std::cout << "ERROR teach: Cantidad de entradas distinta a cantidad de pesos" << std::endl;
		throw "ERROR";
	}
	double actualOutput = this->getOutput(input);
	double derivate = b*(1- tanh(b*actualOutput)*tanh(b*actualOutput));
	double delta = derivate*(desiredOutput-actualOutput);
	// Actualizo pesos
	for(int i=0; i<inputNumber;i++){
		weights[i] += LEARNING_FACTOR*delta*input[i];
		backpropagation.push_back(weights[i]*delta);
	} 
	weights[inputNumber] += LEARNING_FACTOR*delta;
	#ifdef VERBOSE
	std::cout << "DesiredOutput: "<< desiredOutput << "Actual Output: "<< actualOutput << " Backpropagation: ";
	std::vector<double>::iterator it;
	for (it = backpropagation.begin(); it != backpropagation.end(); it++){ 
 		std::cout << *it << ", ";
	}
	std::cout << std::endl; 
	#endif
	return backpropagation;
}


