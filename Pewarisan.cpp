#include<iostream>
#include<iomanip>
#include<numeric>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

   class Poligon {
    protected:
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

   class Segitiga : public Poligon{
       double rata2;
       vector<double> luas;

public:
        void luas1(){
            double l = (x[1]*y[2] + x[2]*y[0] + x[0]*y[1]) - (x[1]*y[0] + x[2]*y[1] + x[0]*y[2]);
            luas.push_back(l);
            x.clear(); y.clear();

        }

        double rata(){
            rata2 = accumulate(luas.begin(), luas.end(), 0.00)/luas.size(); 
            return rata2;
        }

        int count(){
            int counter  =0;
            for(int i =0; i< luas.size(); i++){
                if(luas[i] > rata2){
                    counter++;
                }
            }
            return counter;
        }
   };

   class segiempat : public Poligon{
       vector<double> luas;
       double rata2 = 0;

       public:
        void luas1(){
            double l = (keliling()/4.0) ;
            l =l*l;
            luas.push_back(l);
            x.clear();
            y.clear();
            hasil.clear();
        }

        double rata(){
            rata2 = accumulate(luas.begin(), luas.end(), 0.00)/luas.size();
            return rata2;
        }

        int count(){
            int counter  =0;
            for(int i =0; i< luas.size(); i++){
                if(luas[i] > rata2){
                    counter++;
                }
            }
            return counter;
        }
   };


int main(){
    double x[100], y[100];
    int n, m;

    Segitiga T;
    segiempat E;

    cin >> n;

    for(int i =0; i<n ; i++){
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

        for(int j=0 ; j<3 ; j++){
            T.set(x[j], y[j]);
        }
        T.luas1();
    }

        cin >> m;

    for(int i =0; i<m ; i++){
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];

        for(int j=0 ; j<4 ; j++){
            E.set(x[j], y[j]);
        }
        E.luas1();
    }

    cout << fixed << setprecision(2) << T.rata() << " " << E.rata() << endl;
    cout << T.count() << " " << E.count() << endl;
}
