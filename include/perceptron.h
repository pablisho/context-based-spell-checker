#ifndef __PERCEPTRON_H__
#define __PERCEPTRON_H__

#include "perceptronLayer.h"
#include "hiddenLayer.h"
#include "outputNeuron.h"
#include <string>

class Perceptron {
	public:
		Perceptron(int neurons, int inputs, double b);
		virtual ~Perceptron();
		double getOutput(std::vector<double>& input);
		double getOutput(std::string& input, std::string& word);
		void teach(std::vector<double>& input, double desiredOutput);
		void teach(std::string& input, double desiredOutput, std::string& word);
		void setLearningFactor(double f);
	private:
		std::vector<double> getRealInput(std::string& input, std::string& word);
		HiddenLayer hiddenLayer;
		OutputNeuron outputNeuron;
		int numberOfInputs;
};

#endif
