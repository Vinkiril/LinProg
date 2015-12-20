#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <vector>
#include <jardan.h>
using namespace std;

int main()
{
    jardan matrix;
    size_t n,m;

    cout<<"Enter size matrix(N x M): "<<endl;
    cin>>n;
    cin>>m;
    matrix.setSize(n,m);
    matrix.print();

    std::cout << std::endl << "==========================" << std::endl;

    matrix.hideColumn(0);
    matrix.print();

/*    std::cout << std::endl << "==========================" << std::endl;

    matrix.hideColumn(6);
    matrix.print();
*/
    return 0;
}

