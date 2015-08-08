cmake_minimum_required (VERSION 2.6)
project (SpellChecker)

include_directories(include)

add_executable(SpellChecker 
		src/main.cpp 
		src/outputNeuron.cpp 
		src/hiddenNeuron.cpp 
		src/perceptronNeuron.cpp
		src/perceptronLayer.cpp
		src/outputLayer.cpp
		src/hiddenLayer.cpp)

target_link_libraries(SpellChecker m)
