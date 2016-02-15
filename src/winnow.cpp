#include "winnow.h"

#include <vector>
#include <iostream>

Winnow::Winnow (double promoteFactor, double decreaseFactor) :
		promoteFactor(promoteFactor), decreaseFactor(decreaseFactor) {
}

Winnow::~Winnow(){
}

double Winnow::getOutput(std::vector<std::string>& input){
	double result = 0;
	std::vector<std::string>::iterator it;
	for(it=input.begin(); it!=input.end(); it++){
		if(weights.find(*it) != weights.end()){
			result += weights[*it];
		}
	}

	if(result > 50){
		return 1;
	} else {
		return 0;
	}
}

void Winnow::teach(std::vector<std::string>& input, double desiredOutput){
	double actualOutput = this->getOutput(input);
	if(actualOutput != desiredOutput){
//		std::cout << "Mistake. Desired:  " << desiredOutput << " actual: " << actualOutput << std::endl;
		std::vector<std::string>::iterator it;
        	for(it=input.begin(); it!=input.end(); it++){
               		if(weights.find(*it) != weights.end()){
                       		if(desiredOutput == 1){
					weights[*it] *= promoteFactor;
				} else {
					weights[*it] *= decreaseFactor;
				}
                	}else{
				weights[*it] = 1;
			}
        	}
	}
}

