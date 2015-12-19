#ifndef JARDAN_H
#define JARDAN_H
#include <vector>
using namespace std;


class Jardan
{
    int                     n;
    int                     m;
    vector<vector<double> > arr;
    void input();
    void output();
    int selectColumn(int STB);

public:
    Jardan();
    void jardArr();
};

#endif // JARDAN_H
