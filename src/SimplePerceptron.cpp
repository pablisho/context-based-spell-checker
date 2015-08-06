#include "simplePerceptron.h"
#include <iostream>

SimplePerceptron::SimplePerceptron(int inputNumber){
	this->inputNumber = inputNumber;
	for (int i=0; i < inputNumber+1; i++){
		weights.push_back(i);
	} 
}

SimplePerceptron::~SimplePerceptron(){
}

double SimplePerceptron::getOutput(std::vector<double>& input){
	if (input.size() != inputNumber){
		std::cout << "ERROR: Cantidad de entradas distinta a cantidad de pesos" << std::endl;
		throw "ERROR";
	}
	double output = 0;
	for (int i=0; i<this->inputNumber; i++){
		output += input[i]*weights[i];
	}
	output += weights[inputNumber];
	return output;
}

void SimplePerceptron::teach(std::vector<double>& input, double desiredOutput){
	double actualOutput = this->getOutput(input);
	
}


