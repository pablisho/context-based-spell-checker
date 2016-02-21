#include "spellChecker.h"

#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>




SpellChecker::SpellChecker(std::string word1, std::string word2, int amount) :
	word1(word1), word2(word2), amount(amount) {
        double step = 0.8 / amount;
	for(int i=0; i< amount; i++){
		for(int j=0; j< amount;j++){
			winnows.push_back(Winnow(1+step*i, 1-step*j));
			upWeight.push_back(1);
			downWeight.push_back(1);
		}
	}
}

SpellChecker::~SpellChecker(){
}

void SpellChecker::teach(std::vector<std::string>& input, std::string& word){
 	double desiredOutput;
        if (word == word1){
                desiredOutput = 1;
        } else if (word == word2){
                desiredOutput = -1;
        }else{
                std::cout << "ERROR NO CONFUSION SET WORD PRESENT" << std::endl;
        }
	for(int i=0; i< amount*amount; i++){
		winnows[i].teach(input, desiredOutput);
	}
	std::string output = getOutput(input);
	double result;
	if(output != word){
		for(int i=0; i< amount*amount; i++){
                	result = winnows[i].getOutput(input);
                	if(desiredOutput == 1){
				if(result){
					upWeight[i] *= 1.05;
				}else{
					downWeight[i] *= 0.96;
				}
			}else{
				if(result){
					upWeight[i] *= 0.96;
				}else{
					downWeight[i] *= 1.05;
				}
			}
		}	
	}
}

std::string SpellChecker::getOutput(std::vector<std::string>& input){
	double result;
	double output;
        for(int i=0; i< amount*amount; i++){
                result = winnows[i].getOutput(input);
		//std::cout << "Individual result: " << result << std::endl;
        	output += result == 1 ?  upWeight[i] : -downWeight[i];
	}	
	if (output > 0){
		return word1;
	}else{
		return word2;
	}
}
