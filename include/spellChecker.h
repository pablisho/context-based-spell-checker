#ifndef __SPELL_CHECKER_H__
#define __SPELL_CHECKER_H__

#include "winnow.h"
#include <string>
#include <vector>

class SpellChecker {
	public:
		SpellChecker(std::string word1, std::string word2);
		virtual ~SpellChecker();
		void teach (std::vector<std::string>& input, std::string& word);
		std::string getOutput(std::vector<std::string>& input);
	private:	
		std::string word1;
		std::string word2;
		Winnow winnow;		
};
#endif

