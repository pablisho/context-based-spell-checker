#include "perceptron.h"
#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include "outputNeuron.h"

std::vector<std::string> &split(const std::string& s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


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

void Perceptron::setLearningFactor(double f){
	hiddenLayer.setLearningFactor(f);
	outputNeuron.setLearningFactor(f);
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

void Perceptron::teach(std::string& input, double desiredOutput, std::string& word){
	std::vector<double> realInput = getRealInput(input, word);
	teach(realInput,desiredOutput);
}

double Perceptron::getOutput(std::string& input, std::string& word){
	std::vector<double> realInput = getRealInput(input, word);
	return getOutput(realInput);
}

std::vector<double> Perceptron::getRealInput(std::string& input, std::string& word){
	if (numberOfInputs < 8){
		std::cout << "ERROR teach from string: Este metodo solo se puede usar en un perceptron con mas de 8 entradas";
		throw "ERROR";
	}
	
	double doubleInput[numberOfInputs];
	memset(doubleInput,0,numberOfInputs*sizeof(double));

	int cant = 0;
	for(int i=0; i<input.length(); i++){
		switch(input[i]){
			case ',':	doubleInput[0]+= 2;
					cant++;
					break;
			case ';': 	doubleInput[1]+= 2;
					cant++;
					break;
			case ':': 	doubleInput[2]+= 2;
					cant++;
					break;
			case '?': 	doubleInput[3]+= 2;
					cant++;
					break;
			case '!': 	doubleInput[4]+= 2;
					cant++;
					break;
		}
	}
	
	std::string result;
	std::remove_copy_if(input.begin(), input.end(),            
                        std::back_inserter(result), //Store output           
                        std::ptr_fun<int, int>(&std::ispunct)  
                       );

	std::hash<std::string> hashptr;
	std::vector<std::string> splitted = split(result,' ');
	std::vector<std::string>::iterator it;
	for(it = splitted.begin(); it != splitted.end(); it++){
		if(it->length() > 0 && it->compare(word)){
			int i = hashptr(*it) % (numberOfInputs - 4) + 4;
			doubleInput[i]+=2;
			cant++;
		}
	}
	#ifdef VERBOSE
	std::cout << "INPUT: ";
	#endif
	for ( int i=0; i< numberOfInputs; i++){
		if(doubleInput[i]){
			doubleInput[i] /= 2;
		}
		#ifdef VERBOSE
		std::cout << doubleInput[i] <<", ";
		#endif
	}
	#ifdef VERBOSE
	std::cout << std::endl;
	#endif	
	std::vector<double> realInput(doubleInput, doubleInput + numberOfInputs);
	return realInput;
}

