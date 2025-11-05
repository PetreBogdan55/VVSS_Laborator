#include "Utils.h"

double calculateAverage(const std::vector<double>& vector)
{
	double total = 0.0;
	int count = vector.size();
	if (count == 0)
		throw std::invalid_argument("Vector gol");

	for (double value : vector)
		total += value;

	double average = total / count;
	return average;
}

int maxValue(const std::vector<int>& vector)
{
	if (vector.size() == 0)
		throw std::invalid_argument("Vector gol");
	int maxim = vector[0];
	for (int value : vector)
		if (value > maxim)
			maxim = value;
	return maxim;
}