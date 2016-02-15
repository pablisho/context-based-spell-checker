#include "spellChecker.h"

#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>




SpellChecker::SpellChecker(std::string word1, std::string word2) :
	word1(word1), word2(word2), winnow(1.5,0.5) {
}

SpellChecker::~SpellChecker(){
}

void SpellChecker::teach(std::vector<std::string>& input, std::string& word){
	double desiredOutput;
	if (word == word1){
		desiredOutput = 1;
	} else if (word == word2){
		desiredOutput = 0;
	}else{
		std::cout << "ERROR NO CONFUSION SET WORD PRESENT" << std::endl;
	}
	winnow.teach(input, desiredOutput);
}

std::string SpellChecker::getOutput(std::vector<std::string>& input){
	double output = winnow.getOutput(input);
	if (output){
		return word1;
	}else{
		return word2;
	}
}
