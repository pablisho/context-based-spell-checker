#include "perceptronNeuron.h"
#include <iostream>
#include <cmath>
#include <random>

const double PerceptronNeuron::LEARNING_FACTOR = 0.1;

PerceptronNeuron::PerceptronNeuron(int inputNumber) : distribution(-1.0,1.0){
	this->inputNumber = inputNumber;
	for (int i=0; i < inputNumber+1; i++){
		weights.push_back(distribution(generator));
	} 
	this->b = 1;
}

PerceptronNeuron::PerceptronNeuron(int inputNumber, double b) : distribution(0.0,1.0){
	this->inputNumber = inputNumber;
	for (int i=0; i < inputNumber+1; i++){
		weights.push_back(distribution(generator));
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
