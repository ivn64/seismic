#include "SeismicWells.h"

#include <cassert>

int SeismicWells::measurementsNumbers()
{
	return m_measurementsTable.strNumbers();
}

double SeismicWells::r()
{
	auto t1 = sum(0, 1);
	auto t2 = sum(0, 0);
	auto t3 = sum(0, -1);

	return 0.0;
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
