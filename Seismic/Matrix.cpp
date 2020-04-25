#include "Matrix.h"

#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>

Matrix::Matrix()
{
	load();
}

int Matrix::strNumbers()
{
	return m_matrix.size();
}

void Matrix::load()
{
	std::ifstream file("1.txt");
	assert(file.is_open());

	std::string line;
	double var = 0.0;

	while (!file.eof())
	{
		std::getline(file, line);
		std::vector<double> vec;
		std::istringstream iss(line);
		while (!iss.eof())
		{
			iss >> var;
			vec.push_back(var);
		}

		m_matrix.push_back(vec);
	}

	file.close();
}
