#ifndef __PERCEPTRON_H__
#define __PERCEPTRON_H__

#include "perceptronLayer.h"
#include "outputLayer.h"
#include "hiddenLayer.h"

class Perceptron {
	public:
		Perceptron(int hiddenLayers,std::vector<int>& neurons, int inputs, double b);
		virtual ~Perceptron();
		double getOutput(std::vector<double>& input);
		void teach(std::vector<double>& input, double desiredOutput);
	private:
		std::vector<HiddenLayer*> hiddenLayers;
		OutputLayer outputLayer;
		int numberOfHiddenLayers;
		int numberOfInputs;
};

#endif
