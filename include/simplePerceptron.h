#include <vector>

class SimplePerceptron {
	public:
		SimplePerceptron(int inputNumber);
		virtual ~SimplePerceptron();
		double getOutput(std::vector<double>& input);
		void teach(std::vector<double>& input, double desiredOutput);
	private:
		int inputNumber;
		std::vector<double> weights;
};
