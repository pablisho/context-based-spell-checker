#include "outputNeuron.h"
#include <iostream>
#include <cmath>

OutputNeuron::OutputNeuron(int inputNumber) : PerceptronNeuron(inputNumber){
}

OutputNeuron::OutputNeuron(int inputNumber, double b) : PerceptronNeuron(inputNumber, b){
}

OutputNeuron::~OutputNeuron(){
}

void OutputNeuron::teach(std::vector<double>& input, double desiredOutput){
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
	} 
	weights[inputNumber] += LEARNING_FACTOR*delta;

}


