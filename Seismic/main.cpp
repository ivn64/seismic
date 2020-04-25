#include <iostream>
#include <thread>
#include <mutex>

#include "SeismicWells.h"

int main()
{
    Matrix m;
    m.load();
    SeismicWells seismic(m);

    auto colNumbers = m.colNumbers();
    for (int col1 = 0; col1 < colNumbers - 1; col1++)
    {
        int col2 = col1 + 1;
        while (col2 < colNumbers)
        {
            auto r = seismic.r(col1, col2);
            col2++;
        }
    }

    return 0;
}
