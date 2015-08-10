#ifndef __OUTPUT_PERCEPTRON_H__
#define __OUTPUT_PERCEPTRON_H__


#include <vector>
#include "perceptronNeuron.h"


class OutputNeuron : public PerceptronNeuron {
	public:		
		OutputNeuron(int inputNumber);
		OutputNeuron(int inputNumber, double B);
		virtual ~OutputNeuron();
		virtual std::vector<double> teach(std::vector<double>& input, double desiredOutput);
};
#endif
