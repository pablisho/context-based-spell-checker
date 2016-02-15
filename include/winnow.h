#ifndef __WINNOW_H__
#define __WINNOW_H__

#include <vector>
#include <map>

class Winnow {
	public:
		Winnow(double promoteFactor, double decreaseFactor);
		virtual ~Winnow();
		double getOutput(std::vector<std::string>& input);
		void teach(std::vector<std::string>& input, double output);
	private:
		std::map<std::string,double> weights;
		double promoteFactor;
		double decreaseFactor;
};
#endif

