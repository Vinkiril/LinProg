#include "jardan.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>
void jardan::setSize (size_t rowsCount, size_t columnsCount)    //размеры матрицы и её заполнение
{
    double elem;
    this->rowsCount = rowsCount;
    this->columnsCount = columnsCount;

    data.resize(rowsCount*columnsCount);        //создаем матрицу нужного рамера.
    cout<<"Enter element matrix: "<<endl;
    for (size_t id = 0; id < data.size(); ++id)
    {
        cin>>elem;
        data[id] = elem;
        //data[id] = id;
    }
}

size_t jardan::getId(size_t r, size_t c)
    {
        if (r >= rowsCount) throw std::runtime_error("r >= rowsCount");
        if (c >= columnsCount) throw runtime_error("c >= columnsCount");

        return r*columnsCount + c;
    }

void jardan::hideColumn (size_t column_id)  //записываем столбец который выбрали и прячем
    {
        hideColumns.insert(column_id);
    }

void jardan::print()
    {
        for (size_t r = 0; r < rowsCount; ++r)
        {
            for (size_t c = 0; c < columnsCount; ++c)
            {
                if (hideColumns.find(c) == hideColumns.end())
                {
                    cout << setfill(' ') << setw(4) << getElement(r,c) << " ";
                }
            }
            cout << endl;
        }
    }

double jardan::getElement (size_t r, size_t c)
    {
        return data[getId(r, c)];
    }


void jardan::setElement (size_t r, size_t c, double val)
{
    data[getId(r, c)] = val;
}

jardan::jardan()
{

}

