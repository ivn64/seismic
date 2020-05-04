#include "SeismicWells.h"

#include <cassert>

SeismicWells::SeismicWells(Matrix m)
{
	m_measurementsTable = m;
}

int SeismicWells::measurementsNumbers()
{
	return m_measurementsTable.strNumbers();
}

void SeismicWells::r(int col1, int col2, int excludedStr, double * r)
{
	auto strNumbers = m_measurementsTable.strNumbers();
	auto s12 = sum(col1, col2, excludedStr);
	auto s1  = sum(col1, -1, excludedStr);
	auto s2  = sum(col2, -1, excludedStr);
	auto s11 = sum(col1, col1, excludedStr);
	auto s22 = sum(col2, col2, excludedStr);

	*r = (strNumbers * s12 - s1 * s2)
	   / (sqrt(strNumbers * s11 - s1 * s1) * sqrt(strNumbers * s22 - s2 * s2));
}

double SeismicWells::sum(int col1, int col2, int excludedStr)
{
	auto colNumbers = m_measurementsTable.colNumbers();
	assert(col1 < colNumbers && col2 < colNumbers);

	double sum = 0;
	for (size_t i = 0; i < m_measurementsTable.strNumbers(); i++)
	{
		if (static_cast<int>(i) == excludedStr)
			continue;
		if (col2 == -1)
			sum += m_measurementsTable.value(i, col1);
		else
			sum += m_measurementsTable.value(i, col1) * m_measurementsTable.value(i, col2);
	}

	return sum;
}
