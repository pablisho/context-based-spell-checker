#include "hiddenNeuron.h"
#include <iostream>
#include <cmath>

HiddenNeuron::HiddenNeuron(int inputNumber) : PerceptronNeuron(inputNumber){
}

HiddenNeuron::HiddenNeuron(int inputNumber, double b) : PerceptronNeuron(inputNumber, b){
}

HiddenNeuron::~HiddenNeuron(){
}

void HiddenNeuron::teach(std::vector<double>& input, double propagation){
	if (input.size() != inputNumber){
		std::cout << "ERROR teach: Cantidad de entradas distinta a cantidad de pesos" << std::endl;
		throw "ERROR";
	}
	double actualOutput = this->getOutput(input);
	double derivate = b*(1- tanh(b*actualOutput)*tanh(b*actualOutput));
	double delta = derivate*propagation;
	// Actualizo pesosº
	for(int i=0; i<inputNumber;i++){
		weights[i] += LEARNING_FACTOR*delta*input[i];
	} 
	weights[inputNumber] += LEARNING_FACTOR*delta;

}


