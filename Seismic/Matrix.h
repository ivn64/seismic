#pragma once
#include <vector>

class Matrix
{
public:
	Matrix();
	void load();
	int strNumbers();
	int colNumbers();
	double value(int str, int col);

private:
	std::vector<std::vector<double>> m_matrix;
};
