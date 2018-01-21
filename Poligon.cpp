#include<iostream>
#include<iomanip>
#include<numeric>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

   class Poligon {
      vector<double> x;
      vector<double> y;
      vector<double> hasil;
public:
    void set(double a, double b){
            x.push_back(a);
            y.push_back(b);
    }

    double keliling(){
        double jumlah = 0;
        for(int i=0; i< x.size()-1; i++){
            double hasil1 = (x[i] - x[i+1]) * (x[i] - x[i+1]);
            double hasil2 = (y[i] - y[i+1]) * (y[i] - y[i+1]);

            double nilai = sqrt(hasil1+hasil2);
            hasil.push_back(nilai);  
        }

            double hasil1 = (x[0] - x[x.size()-1]) * (x[0] - x[x.size()-1]);
            double hasil2 = (y[0] - y[y.size()-1]) * (y[0] - y[y.size()-1]);
            double nilai = sqrt(hasil1+hasil2);
            hasil.push_back(nilai);


        return accumulate(hasil.begin(), hasil.end(), 0.00);
    }

    void cetak(){
            cout << fixed << setprecision(2) << "[" << x[0]<< "," << y[0] << "]" << "-";
            cout << fixed << setprecision(2) << "[" << x[x.size()-1]<< "," << y[y.size()-1] << "]" << endl;
            cout << fixed << setprecision(2) << keliling() << endl;
    }
   };


int main(){
    Poligon x;
    double j, k;
    int nEdge;

    cin >> nEdge;

    for(int i =0; i<nEdge ; i++){
        cin >>j >> k;
    x.set(j, k);
    }
    x.cetak();
}
