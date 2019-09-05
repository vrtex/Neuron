#include "Neuron.h"
#include <iostream>

Neuron::Neuron(int n)
{
	for(int i = 0; i < n + 1; ++i)
		weights.push_back(GetRandom());
}



int Neuron::Guess(std::vector<float> input, int label, bool train)
{
	if(input.size() != weights.size() - 1)
		throw std::exception();
	
	float sum = 0;
	
	for(size_t i = 0; i < input.size(); ++i)
		sum += input[i] * weights[i];

	sum += weights[input.size()];

	int guess = sum >= 0 ? 1 : -1;;

	if(guess != label && train)
		Train(input, label - guess);

	return guess;
}

void Neuron::Train(std::vector<float> input, int error)
{
	for(size_t i = 0; i < input.size(); ++i)
		weights[i] += input[i] * error * learningRate;
}

std::string Neuron::ToString() const
{
	std::string toReturn = "{ ";
	for(auto w : weights)
		toReturn += std::to_string(w) + ", ";
	toReturn += " }";
	return toReturn;
}


void Neuron::ChangeLearningRate(float change)
{
	learningRate += change;
}