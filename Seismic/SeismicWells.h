#pragma once
#include <list>

#include "Matrix.h"

class SeismicWells
{
public:
	int measurementsNumbers();
	double r();

private:


private:
	std::list <int> m_excludedMeasurements;
	Matrix m_measurementsTable;
};
