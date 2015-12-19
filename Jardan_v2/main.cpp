#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <vector>
#include <jardan.h>
using namespace std;

int main()
{
    jardan m;


        m.setSize(10,8);
        m.print();

        std::cout << std::endl << "==========================" << std::endl;

        m.hideColumn(4);
        m.print();

        std::cout << std::endl << "==========================" << std::endl;

        m.hideColumn(0);
        m.print();

        return 0;

    return 0;
}

