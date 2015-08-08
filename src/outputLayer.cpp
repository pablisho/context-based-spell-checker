#include "outputLayer.h"
#include "outputNeuron.h"

OutputLayer::OutputLayer(int neurons, int inputs, double b) : PerceptronLayer(neurons,inputs,b) {
	for (int i = 0; i< neurons; i++){
		this->neurons.push_back(new OutputNeuron(inputs,b));
	}
}

OutputLayer::~OutputLayer(){
}
