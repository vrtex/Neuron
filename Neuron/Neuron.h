#pragma once

#include <vector>
#include <string>

float inline GetRandom()
{
	return ((float)rand() / (float)RAND_MAX) * 2.f - 1.f;
}

class Neuron
{
public:
	Neuron(int n);

	int Guess(std::vector<float> input, int label, bool train = true);
	void Train(std::vector<float> input, int error);
	std::string ToString() const;

	void ChangeLearningRate(float change);
	float GetLearningRate() const { return learningRate; }

private:
	std::vector<float> weights;

	float learningRate = 0.25f;
};

