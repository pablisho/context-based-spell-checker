#include "perceptronNeuron.h"
#include <iostream>
#include <cmath>

const double PerceptronNeuron::LEARNING_FACTOR = 1;

PerceptronNeuron::PerceptronNeuron(int inputNumber){
	this->inputNumber = inputNumber;
	for (int i=0; i < inputNumber+1; i++){
		weights.push_back(i);
	} 
	this->b = 1;
}

PerceptronNeuron::PerceptronNeuron(int inputNumber, double b){
	this->inputNumber = inputNumber;
	for (int i=0; i < inputNumber+1; i++){
		weights.push_back(i);
	}
	this->b = b;
}

PerceptronNeuron::~PerceptronNeuron(){
}

double PerceptronNeuron::getOutput(std::vector<double>& input){
	if (input.size() != inputNumber){
		std::cout << "ERROR getOutput: Cantidad de entradas distinta a cantidad de pesos" << std::endl;
		throw "ERROR";
	}
	double output = 0;
	for (int i=0; i<this->inputNumber; i++){
		output += input[i]*weights[i];
	}
	output += weights[inputNumber];
	return tanh(b*output);
}
