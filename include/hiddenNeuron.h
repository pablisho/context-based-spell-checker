#ifndef __HIDDEN_PERCEPTRON_H__
#define __HIDDEN_PERCEPTRON_H__

#include <vector>
#include "perceptronNeuron.h"

class HiddenNeuron : public PerceptronNeuron {
	public:		
		HiddenNeuron(int inputNumber);
		HiddenNeuron(int inputNumber, double B);
		virtual ~HiddenNeuron();
		virtual std::vector<double> teach(std::vector<double>& input, double propagation);
};
#endif
