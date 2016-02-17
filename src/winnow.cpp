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
	int i=0;
        for(it=input.begin(); it!=input.end(); it++){
		double ventana = 1;
		if(i <=5){
		  ventana=(double)(i+1)/5;
		}else{
		  ventana =(double)(10-i)/5;
		}
 		if(weights.find(*it) != weights.end()){
			result += weights[*it]*ventana;
		}else{
 			result += 1*ventana;
		}
                i++;
	}

	if(result > 500){
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

