cmake_minimum_required (VERSION 2.6)
project (SpellChecker)

 SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

add_executable(SpellChecker 
		src/main.cpp 
		src/outputNeuron.cpp 
		src/hiddenNeuron.cpp 
		src/perceptronNeuron.cpp
		src/perceptronLayer.cpp
		src/hiddenLayer.cpp
		src/perceptron.cpp)

target_link_libraries(SpellChecker m)
