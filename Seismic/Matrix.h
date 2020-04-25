#pragma once
#include <vector>

class Matrix
{
public:
	Matrix();
	int strNumbers();
	int colNumbers();
	double value(int str, int col);

private:
	void load();

private:
	std::vector<std::vector<double>> m_matrix;
};
