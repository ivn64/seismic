#pragma once
#include <list>

#include "Matrix.h"

class SeismicWells
{
public:
	int measurementsNumbers();
	double r();

private:
	double sum(int col1, int col2);

private:
	std::list <int> m_excludedMeasurements;
	Matrix m_measurementsTable;
};
