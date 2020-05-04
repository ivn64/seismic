#include <iostream>
#include <thread>
#include <mutex>

#include "SeismicWells.h"

int main()
{
    Matrix m;
    m.load();
    SeismicWells seismic(m);

    std::vector<double *> rList;
    std::vector<std::thread> threads;

    auto colNumbers = m.colNumbers();
    auto strNumbers = m.strNumbers();


    for (int col1 = 0; col1 < colNumbers - 1; col1++)
    {
        int col2 = col1 + 1;
        while (col2 < colNumbers)
        {
            double * r = new double();
            rList.push_back(r);
            threads.push_back(std::thread(&SeismicWells::r, &seismic, col1, col2, 0, r));
            col2++;
        }
    }

    for (auto& t : threads)
    {
        if (t.joinable())
            t.join();
    }

    for (auto & r : rList)
        delete r;

    return 0;
}
