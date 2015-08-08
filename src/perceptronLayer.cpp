#include "perceptronLayer.h"
#include <iostream>

PerceptronLayer::PerceptronLayer(int neuronsNumber, int inputNumber, double B){
	this->neuronsNumber = neuronsNumber;
	this->inputNumber = inputNumber;
	this->b = B;
}

PerceptronLayer::~PerceptronLayer(){
	std::vector<PerceptronNeuron*>::iterator it;
	for(it=this->neurons.begin() ; it != this->neurons.end(); it++){
		delete *it;
	}
}

std::vector<double> PerceptronLayer::getOutput(std::vector<double>& input){
	std::vector<double> output;
	std::vector<PerceptronNeuron*>::iterator it;
	for (it = this->neurons.begin(); it != this->neurons.end(); it++){
		output.push_back((*it)->getOutput(input));
	}
	return output;
}

void PerceptronLayer::teach(std::vector<double>& inputs, std::vector<double>& learn){
        if (learn.size() != this->neuronsNumber){
                std::cout << "ERROR Layer teach: Numero de salidas a aprender no coincide con cantidad de neuronas";
                throw "ERROR";
        }
        std::vector<PerceptronNeuron*>::iterator it;
        std::vector<double>::iterator learnIt = learn.begin();
        for(it = this->neurons.begin(); it != this->neurons.end(); it++,learnIt++){
                (*it)->teach(inputs,*learnIt);
        }
}

