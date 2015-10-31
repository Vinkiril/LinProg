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
    cout<<"Selected element a["<<k<<"]["<<s<<"] = "<<arr[k][s]<<endl;
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

int main()
{

    vector<vector<double> > v=input();
    cout<<"Entered array"<<endl;
    output(v);
    v=Jardan(v);
    cout<<"Jardan matrix: "<<endl;
    output(v);
    return 0;
}
