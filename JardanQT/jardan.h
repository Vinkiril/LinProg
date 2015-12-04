#ifndef JARDAN_H
#define JARDAN_H
#include <vector>
#include <QMainWindow>
using namespace std;


class Jardan
{
public:
    int n;
    int m;
    vector<vector<double> >arr;
    void jardArr(int k, int s);
    Jardan();
    void init();
private:
    void input();
    void output();

    int selectColumn(int STB);

};

#endif // JARDAN_H
