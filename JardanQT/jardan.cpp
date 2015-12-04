#include "jardan.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "mainwindow.h"
#include "ui_mainwindow.h"
/*
void Jardan::input(){

    cout<<"Enter size matrix(x y):"<<endl;
    cin>>n;
    cin>>m;

    this->arr = vector<vector<double> >(n,vector<double>(m));
    cout<<"random?(yes/no) "<<endl;
    string answer="";
    cin>>answer;
    if(answer=="yes"){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=rand()%100;
            }
        }
    }
    else{
        cout<<"Enter array: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
    }
}

void Jardan::output(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout.precision(3);          //округление
            cout<<setw(6)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int Jardan::selectColumn(int STB){
    int coord=0; //запомниает строку минимального частного
    double div; //значение частного
    double temp=1000;//предыдущее значение

    for(int i=0;i<n;i++){
          if(arr[i][STB]!=0){
            div=arr[i][0]/arr[i][STB];
            if(div<temp){
                temp=div;
                coord=i;
            }
        }
    }
    return coord;
}
*/
void Jardan::init(){
    this->arr = vector<vector<double> >(n,vector<double>(m));
}

void Jardan::jardArr(int k, int s){
    vector<vector<double> >jardArr(n,vector<double>(m)); //отжарденный массив
//    cout<<"Selected element a["<<k<<"]["<<s<<"] = "<<arr[k][s]<<endl;
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if((i!=k)&&(j!=s))
                jardArr[i][j]=(arr[i][j]*arr[k][s]-arr[i][s]*arr[k][j])/arr[k][s];  //считаем прочие элемнты
            else
            {
                if((i!=k)&&(j==s))
                jardArr[i][j]=arr[i][j]/arr[k][s]*(-1); // считаем выбраный столбец
                if((i==k)&&(j!=s))
                jardArr[i][j]=arr[i][j]/arr[k][s];      // считаем выбранную строку
                if((i==k)&&(j==s))
                jardArr[i][j]=1/arr[k][s];              //выбранный элемент делмаем обратным
            }
         }
    }
    arr=jardArr;
}

Jardan::Jardan()
{

}


