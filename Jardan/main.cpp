#include <QCoreApplication>
#include <iostream>
#include <vector>
using namespace std;
const int n=2;
const int m=3;
vector<double> input(int n,int m){

    vector<double>arr;
    arr.resize(n*m);
    cout<<"Enter array: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i*n+j];
        }
    }

    return arr;
}

void output(vector <double> arr){
    cout<<"Array: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i*n+j]<<" ";
        }
        cout<<endl;
    }
}

vector<double> Jardan(vector<double>arr){


    return arr;
}


int main()
{
    output(input(n,m));
    return 0;
}
