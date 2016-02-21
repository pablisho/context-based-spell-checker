#include "spellChecker.h"
#include <iostream>
#include "outputNeuron.h"
#include <fstream>
#include <string>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <algorithm>
#include <locale>
#include <wctype.h>
#include <queue>

//using namespace std::string_literals;

int computarError(SpellChecker& p, std::string&, std::string&);
int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

std::string processWord(std::string word){
	std::string result;
        std::remove_copy_if(word.begin(), word.end(),
		std::back_inserter(result), //Store output           
        	std::ptr_fun<int, int>(&std::ispunct));
        std::transform(result.begin(), result.end(), result.begin(),::tolower);
	return result;
}

int main(int argc, char* argv[]){
	
	std::vector<std::string> words;
	int k = 3;

	std::string w1 = argv[1];
	std::string w2 = argv[2];

	int cantCon = 0;
	int cantSin = 0;
	SpellChecker spellChecker(w1,w2,10);
	std::ifstream file;
	for(int i=0; i< 50;i++){
		std::cout << i <<", ";
 		std::cout.flush();
		if(i % 10 == 0){
			if(!computarError(spellChecker,w1,w2)){
				break;
			}
		}
		int cant = 0;
		DIR *dir;
		struct dirent *ent;
		if ((dir = opendir ("./cuentos")) != NULL) {
			while ((ent = readdir (dir)) != NULL) {
				std::string name = "./cuentos/";
				name += ent->d_name;
				if(is_regular_file(name.c_str())){
					file.open(name);
					std::string word;
					while(file >> word){
						std::string result = processWord(word);
						if(result.length() > 0){
							words.push_back(result);
							if(words.size() > 2*k+1){
								words.erase(words.begin());
							}
							if(std::find(words.begin(), words.end(), w1) - words.begin() == k){
								words.erase(std::remove(words.begin(), words.end(), w1), words.end());
								spellChecker.teach(words,w1);				
							}else if(std::find(words.begin(), words.end(), w2) - words.begin() == k){	
								words.erase(std::remove(words.begin(), words.end(), w2), words.end());
								spellChecker.teach(words,w2);
							}
						}
					}
					file.close();
				}
  			}
  			closedir (dir);
		} else {
  			/* could not open directory */
  			perror ("");
  			return EXIT_FAILURE;
		}
		//std::cout << "MUESTRAS: " << cant << std::endl;
	}
	computarError(spellChecker,w1,w2);
	return 0;
}


int computarError(SpellChecker& spellChecker, std::string& w1, std::string& w2){
	std::ifstream file;
	
	std::string output;
	int total = 0;
	int con = 0;
	int sin = 0;
	int error = 0;
	int errorCon = 0;
	int errorSin = 0;
	DIR *dir;
	struct dirent *ent;
	int files = 0;
	
	int k = 3;
	std::vector<std::string> words;

	if ((dir = opendir ("./cuentos")) != NULL) {
		while ((ent = readdir (dir)) != NULL) {
			std::string name = "./cuentos/";
			name += ent->d_name;
			if(is_regular_file(name.c_str())){
				files++;
                        	file.open(name);
                                std::string word;
                                while(file >> word){
                                	std::string result = processWord(word);
                                        if(result.length() > 0){
                                        	words.push_back(result);
                                                if(words.size() > 2*k+1){
                                                	words.erase(words.begin());
                                                }
                                                if(std::find(words.begin(), words.end(), w1) - words.begin() == k){
                                                	words.erase(std::remove(words.begin(), words.end(), w1), words.end());
                                                        total++;
							sin++;
							output = spellChecker.getOutput(words);
							if(output != w1){
								error++;
								errorSin++;
							}
                                                }else if(std::find(words.begin(), words.end(), w2) - words.begin() == k){
                                                        words.erase(std::remove(words.begin(), words.end(), w2), words.end());
                                                        total++;
							con++;
							output = spellChecker.getOutput(words);
							if(output != w2){
								error++;
								errorCon++;
							}
                                                }
                                        }
                                }
                                file.close();
                        }
  		}
  		closedir (dir);
	} else {
  		/* could not open directory */
  		perror ("");
  		throw "ERROR";
	}
	double porc = (double)error* (double) 100 / (double)total;
	std::cout << "Archivos procesados: "<<files  <<" Ocurrencias Totales: " << total << "Palabra1: " << sin << " Palabra2: "<< con << " Errores totales: " << error <<  " Errores Palabra1: "<< errorSin << " Errores Palabra2: " << errorCon
				<<" Error Porcentual: " << porc << std::endl; 
	return error;
}

