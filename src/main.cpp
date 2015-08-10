#include "perceptron.h"
#include <iostream>
#include "outputNeuron.h"
#include <fstream>
#include <string>
#include <dirent.h>

int computarError(Perceptron& p);

int main(int argc, char* argv[]){
	
	Perceptron p(20,128,1);
	std::ifstream file;
	bool una = true;
	for(int i=0; i< 1000;i++){
		std::cout << i << std::endl;
		if(i % 10 == 0){
			if(!computarError(p)){
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
				file.open(name);
				std::string line;
				while (getline(file,line, '.')){
					if (line.find(" se ") != std::string::npos){
						cant++;
						std::string word = "se";
						p.teach(line,-1,word);
						una = false;
					}else if(line.find(" sé ") != std::string::npos){
						cant++;
						std::string word = "sé";
						p.teach(line,1,word);
						una = true;
					}
				}
				file.close();
  			}
  			closedir (dir);
		} else {
  			/* could not open directory */
  			perror ("");
  			return EXIT_FAILURE;
		}
		if(i == 50){
			p.setLearningFactor(0.01);
		}
		//std::cout << "MUESTRAS: " << cant << std::endl;
	}
	computarError(p);
	return 0;
}


int computarError(Perceptron& p){
	std::ifstream file;
	
	double output;
	int total = 0;
	int con = 0;
	int sin = 0;
	int error = 0;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("./cuentos")) != NULL) {
		while ((ent = readdir (dir)) != NULL) {
			std::string name = "./cuentos/";
			name += ent->d_name;
			file.open(name);
			std::string line;
			while (getline(file,line, '.')){
				if (line.find(" se ") != std::string::npos){
					total++;
					sin++;
					std::string word = "se";
					output = p.getOutput(line, word);
					if ( output > 0){
						error++;
					}
					//std::cout << "QUE: "<< (output < 0 ? "OK" : "ERROR") << std::endl;
				}else if(line.find(" sé ") != std::string::npos){
					total++;
					con++;
					std::string word = "sé";
					output = p.getOutput(line, word);
					if (output < 0){
						error++;
					}
					//std::cout << "QUÉ: "<< (output > 0 ? "OK" : "ERROR") << std::endl;
				}
			}
			file.close();
  		}
  		closedir (dir);
	} else {
  		/* could not open directory */
  		perror ("");
  		throw "ERROR";
	}
	double porc = (double)error* (double) 100 / (double)total;
	std::cout <<"TOTAL: " << total << " CON: " << con << "SIN: "<< sin << " ERRORES: " << error << " ERROR PORCENTUAL: " << porc << std::endl; 
	return error;
}
