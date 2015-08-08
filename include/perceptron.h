#ifndef __PERCEPTRON_H__
#define __PERCEPTRON_H__

#include "perceptronLayer.h"
#include "hiddenLayer.h"
#include "outputNeuron.h"

class Perceptron {
	public:
		Perceptron(int neurons, int inputs, double b);
		virtual ~Perceptron();
		double getOutput(std::vector<double>& input);
		void teach(std::vector<double>& input, double desiredOutput);
	private:
		HiddenLayer hiddenLayer;
		OutputNeuron outputNeuron;
		int numberOfInputs;
};

#endif
