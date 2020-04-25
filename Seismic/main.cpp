#include <iostream>
#include <thread>
#include <mutex>

#include "SeismicWells.h"

const int m_i = 10;
const int m_j = 2;

float m_table[m_i][m_j] = {
    { 1, 10 },
    { 2, 11 },
    { 3, 12 },
    { 4, 18 },
    { 5, 14 },
    { 6, 15 },
    { 7, 16 },
    { 8, 17 },
    { 9, 18 },
    { 10, 19 },
};

//float m_table[m_i][m_j] = {
//    { 10, 3.8 },
//    { 14, 4.8 },
//    { 21, 5.9 },
//    { 23, 6.1 },
//    { 27, 6.2 },
//    { 32, 6.3 },
//    { 39, 6.6 },
//    { 45, 7.4 },
//    { 55, 8.5 },
//    { 61, 9.7 },
//    { 62, 10.5 },
//    { 68, 12.4 },
//};

double s_xx()
{
    double sum = 0;
    for (size_t i = 0; i < m_i; i++)
        sum += m_table[i][0] * m_table[i][0];
    return sum;
}
double s_yy()
{
    double sum = 0;
    for (size_t i = 0; i < m_i; i++)
        sum += m_table[i][1] * m_table[i][1];
    return sum;
}

double s_xy()
{
    double sum = 0;
    for (size_t i = 0; i < m_i; i++)
        sum += m_table[i][0] * m_table[i][1];
    return sum;
}

double s_x()
{
    double sum = 0;
    for (size_t i = 0; i < m_i; i++)
        sum += m_table[i][0];
    return sum;
}

double s_y()
{
    double sum = 0;
    for (size_t i = 0; i < m_i; i++)
        sum += m_table[i][1];
    return sum;
}

int main()
{
    std::cout << "Start......\n";
    auto t1 = s_xx();
    auto t2 = s_yy();
    auto t3 = s_xy();
    auto t4 = s_x();
    auto t5 = s_y();

    auto r = (m_i * s_xy() - s_x() * s_y())
        / (sqrt(m_i * s_xx() - s_x() * s_x()) * sqrt(m_i * s_yy() - s_y() * s_y()));

    std::cout << r << std::endl;
    Matrix m;
    auto t6 = m.colNumbers();
    SeismicWells seismic;
    auto r0 = seismic.r(0, 1);

    for (int col1 = 0; col1 < t6 - 1; col1++)
    {
        int col2 = col1 + 1;
        while (col2 < t6)
        {
            auto t7 = seismic.r(col1, col2);
            col2++;
            int rr = 0;
        }
    }

    return 0;
}
