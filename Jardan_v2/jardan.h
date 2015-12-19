#ifndef JARDAN_H
#define JARDAN_H
#include <vector>
#include <set>
using namespace std;
class jardan
{
public:
    jardan();
    void setSize(size_t rowsCount, size_t columnsCount);
    void print();
    void hideColumn(size_t column_id);
    double getElement (size_t r, size_t c);
    void setElement (size_t r, size_t c, double val);
    size_t getId(size_t r, size_t c);

private:
    size_t				rowsCount;
    size_t				columnsCount;
    vector<double>      data;
    set<size_t>         hideColumns;
};

#endif // JARDAN_H
