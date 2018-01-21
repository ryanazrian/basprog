#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>

using namespace std;
template <class X, class Y>


class Maksimum{
    X a;
    Y b;
    int n;

public:
    Maksimum(){
        X jumlah1 =0, hasil1;
        Y jumlah2 =0, hasil2;
        cin >> n;
        for(int i=0 ; i< n; i++){
            cin >> a;
            jumlah1 = jumlah1+a;
            cin >> b;
            jumlah2 = jumlah2+b;
        }
        hasil1 = jumlah1/n;
        hasil2 = jumlah2/n;
        cout <<fixed<< setprecision(2)<< hasil1 << " " << hasil2 << endl;    
    }
};

int main(){
    Maksimum <double, double> x;

    return 0;
}