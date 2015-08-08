#include "perceptron.h"
#include <iostream>

Perceptron::Perceptron(int neurons, int inputs, double b) :
	outputNeuron(neurons, b), hiddenLayer(neurons,inputs, b){
	this->numberOfInputs = inputs;
}

Perceptron::~Perceptron(){
}

double Perceptron::getOutput(std::vector<double>& input){
	std::vector<double> partialResult = hiddenLayer.getOutput(input);
	double result = outputNeuron.getOutput(partialResult);
	return result;
}

void Perceptron::teach(std::vector<double>& input, double desiredOutput){
	std::vector<double> hiddenOutput = hiddenLayer.getOutput(input);
	#ifdef VERBOSE
	std::cout << "HiddenOutput: ";
	std::vector<double>::iterator it;
	for (it = hiddenOutput.begin(); it != hiddenOutput.end(); it++){
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
	#endif
	std::vector<double> back = outputNeuron.teach(hiddenOutput, desiredOutput);
	hiddenLayer.teach(input, back);
}
