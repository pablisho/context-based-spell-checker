cmake_minimum_required (VERSION 2.6)
project (SpellChecker)

include_directories(include)

add_executable(SpellChecker src/main.cpp src/SimplePerceptron.cpp)
