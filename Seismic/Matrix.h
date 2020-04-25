#pragma once
#include <vector>

class Matrix
{
public:
	Matrix();
	int strNumbers();

private:
	void load();

private:
	std::vector<std::vector<double>> m_matrix;
};
