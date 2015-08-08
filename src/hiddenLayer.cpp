#include "hiddenLayer.h"
#include "hiddenNeuron.h"

HiddenLayer::HiddenLayer(int neurons, int inputs, double b) : PerceptronLayer(neurons,inputs,b) {
	for (int i = 0; i< neurons; i++){
		this->neurons.push_back(new HiddenNeuron(inputs,b));
	}
}

HiddenLayer::~HiddenLayer(){
}
