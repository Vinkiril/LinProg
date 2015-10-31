#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <iomanip>
#include "mainwindow.h"
using namespace std;
const int n=2;
const int m=3;
vector<vector<double> > input(int n,int m){

    vector<vector<double> >arr(n,vector<double>(m));
    cout<<"Enter array: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    return arr;
}

void output(vector<vector <double> > arr){
    cout<<"Array: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout.precision(3);
            cout<<setw(6)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<double> > Jardan(vector<vector<double> >arr){
    vector<vector<double> >jardArr(n,vector<double>(m));
    cout<<"select element:[i][j] "<<endl;
    int k,s;
    cin>>k;
    cin>>s;
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if((i!=k)&&(j!=s))
                jardArr[i][j]=(arr[i][j]*arr[k][s]-arr[i][s]*arr[k][j])/arr[k][s];
            else
            {
                if((i!=k)&&(j==s))
                jardArr[i][j]=arr[i][j]/arr[k][s]*(-1);
                if((i==k)&&(j!=s))
                jardArr[i][j]=arr[i][j]/arr[k][s];
                if((i==k)&&(j==s))
                jardArr[i][j]=1/arr[k][s];
            }
         }
    }
    return jardArr;
}


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
