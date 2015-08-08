#ifndef __PERCEPTRON_LAYER_H__
#define __PERCEPTRON_LAYER_H__

#include <vector>
#include "perceptronNeuron.h"

class PerceptronLayer {
	public:
		PerceptronLayer(int neuronsNumber, int inputNumberi, double B);
		virtual ~PerceptronLayer();
		std::vector<double> getOutput(std::vector<double>& input);
		void teach(std::vector<double>& input, std::vector<double>& learn);
	protected:
		int neuronsNumber;
		int inputNumber;
		double b;
		std::vector<PerceptronNeuron*> neurons;
};
#endif
