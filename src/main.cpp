#include "perceptron.h"
#include <iostream>
#include "outputNeuron.h"
#include <fstream>
#include <string>
#include <dirent.h>

int computarError(Perceptron& p, std::string& , std::string& ,std::string& , std::string&);

int main(int argc, char* argv[]){
	
	std::string w1 = argv[1];
	std::string w2 = argv[2];
	std::string w1S = " ";
	w1S += w1;
	w1S += " ";
	std::string w2S = " ";
	w2S += w2;
	w2S += " ";

	Perceptron p(20,128,1);
	std::ifstream file;
	bool una = true;
	for(int i=0; i< 1000;i++){
		std::cout << i << std::endl;
		if(i % 10 == 0){
			if(!computarError(p,w1,w1S,w2,w2S)){
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
					if (line.find(w1S) != std::string::npos){
						cant++;
						p.teach(line,-1,w1);
						una = false;
					}else if(line.find(w2S) != std::string::npos){
						cant++;
						p.teach(line,1,w2);
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
	computarError(p,w1,w1S,w2,w2S);
	return 0;
}


int computarError(Perceptron& p, std::string& w1, std::string& w1S, std::string& w2, std::string& w2S){
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
				if (line.find(w1S) != std::string::npos){
					total++;
					sin++;
					output = p.getOutput(line, w1);
					if ( output > 0){
						error++;
					}
					//std::cout << "QUE: "<< (output < 0 ? "OK" : "ERROR") << std::endl;
				}else if(line.find(w2S) != std::string::npos){
					total++;
					con++;
					output = p.getOutput(line, w2);
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
