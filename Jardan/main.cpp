#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int n;
int m;
vector<vector<double> > input(){
    cout<<"Enter size matrix(x y):"<<endl;
    cin>>n;
    cin>>m;

    vector<vector<double> >arr(n,vector<double>(m));
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

    return arr;

}

void output(vector<vector <double> > arr){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout.precision(3);          //округление
            cout<<setw(6)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int selectSTR(int STB,vector<vector<double> >arr){//выбираем строку при заднном столбце
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


vector<vector<double> > Jardan(vector<vector<double> >arr){
    vector<vector<double> >jardArr(n,vector<double>(m)); //отжарденный массив
    cout<<"select column:  [j] (j>0)"<<endl;
    int k,s;
    do{
    cin>>s;                                                 //выбираем столбец

    }while(s==0);
    k=selectSTR(s,arr);                                 // cтрока выбирается автоматически
    cout<<"Selected element a["<<k<<"]["<<s<<"] = "<<arr[k][s]<<endl;
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
    return jardArr;
}


int main()
{

    vector<vector<double> > v;
    v=input();
    cout<<"Entered array"<<endl;
    output(v);
    v=Jardan(v);
    cout<<"Jardan matrix: "<<endl;
    output(v);
    return 0;
}
