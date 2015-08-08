#ifndef __PERCEPTRON_NEURON_H__
#define __PERCEPTRON_NEURON_H__
#include <vector>
#include <random>

class PerceptronNeuron {
	public:
		PerceptronNeuron(int inputNumber);
		PerceptronNeuron(int inputNumber, double B);
		virtual ~PerceptronNeuron();
		double getOutput(std::vector<double>& input);
		virtual std::vector<double> teach(std::vector<double>& input, double desiredOutput) = 0;
	protected:
		// Number of inputs
		int inputNumber;
		// Weight of each input plus one extra dimension
		std::vector<double> weights;
		// Scale factor of tanh
		double b;
		// Learning factor, known as Nu
		static const double LEARNING_FACTOR;
		 
		std::default_random_engine generator;
  		std::uniform_real_distribution<double> distribution;	
};
#endif
