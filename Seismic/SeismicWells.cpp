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

double SeismicWells::r(int col1, int col2)
{
	auto strNumbers = m_measurementsTable.strNumbers();
	auto s12 = sum(col1, col2);
	auto s1  = sum(col1, -1);
	auto s2  = sum(col2, -1);
	auto s11 = sum(col1, col1);
	auto s22 = sum(col2, col2);

	auto r1 = (strNumbers * s12 - s1 * s2)
		/ (sqrt(strNumbers * s11 - s1 * s1) * sqrt(strNumbers * s22 - s2 * s2));

	return r1;
}

double SeismicWells::sum(int col1, int col2)
{
	auto colNumbers = m_measurementsTable.colNumbers();
	assert(col1 < colNumbers && col2 < colNumbers);
	
	double sum = 0;
	if (col2 == -1)
		for (size_t i = 0; i < m_measurementsTable.strNumbers(); i++)
			sum += m_measurementsTable.value(i, col1);
	else
		for (size_t i = 0; i < m_measurementsTable.strNumbers(); i++)
			sum += m_measurementsTable.value(i, col1) * m_measurementsTable.value(i, col2);

	return sum;
}
