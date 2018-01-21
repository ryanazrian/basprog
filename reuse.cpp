#include<iostream>
#include<iomanip>
#include<numeric>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

   class Titik {
    protected:
        vector<double> x, y;
      public:
         void set(double p, double q) {
             x.push_back(p);
             y.push_back(q);
              }
        //  double getX() { return x; }
        //  double getY() { return y; }
        //  void print() { cout<<"("x<<","<<y<<")"; }
   };


   class Lingkaran : public Titik {
      Titik p;
      double r;
      double rata, rata1;
      vector <double> luas;
      vector<double> keliling;
      public:
         Titik getPusat(){
             return p;
         }

         double getR(){
             return r;
         }

        double kelilings(double r){
            double k = 3.14*2*r;
            keliling.push_back(k);
        }

        void luass(double r){
                double l = 3.14*r*r;
                luas.push_back(l);
            }
        double rataan(){
            rata = accumulate(luas.begin(), luas.end(), 0.00)/luas.size();
            rata1 = accumulate(keliling.begin(), keliling.end(), 0.00)/keliling.size();
        }

        pair<int, int> count(){
            int besar_lingkaran = 0;
            int besar1_lingkaran = 0;
            for(int i=0; i<luas.size(); i++){
                if(rata<luas[i]){
                    besar_lingkaran ++;
                }
                if(rata1<keliling[i]){
                    besar1_lingkaran ++;
                }
            }

            return make_pair(besar_lingkaran, besar1_lingkaran);
        }


   };


class Segitiga : public Titik{
     // double x[100], y[100];
      double rata, rata1;
      vector<double> luas, keliling;
      public:
         void luas1(){
            double l = (x[1]*y[2] + x[2]*y[0] + x[0]*y[1]) - (x[1]*y[0] + x[2]*y[1] + x[0]*y[2]);
            luas.push_back(l);
            x.clear(), y.clear();
            //cout << luas.back() << endl;
         }

         void keliling1(){
            double d, e, f = 0.0;
            for(int i = 0 ; i < 3; i++)
            {
                for(int j = i+1 ; j < 3 ; j++)
                {
                    d = (x[i]-x[j]); d*=d;
                    e = (y[i]-y[j]); e*=e;
                    f += sqrt(d+e);
                }
            }
            keliling.push_back(f);
         }

         void rataan1(){
             rata = accumulate(luas.begin(), luas.end(), 0.00)/luas.size();
            rata1 = accumulate(keliling.begin(), keliling.end(), 0.00)/keliling.size();

            //cout << rata << " " << rata1 << endl
         }

         pair<int, int> count1(){
            int besar_segitiga = 0;
            int besar1_segitiga = 0;
            for(int i=0; i<luas.size(); i++){
                if(rata<luas[i]){
                    besar_segitiga ++;
                }
                if(rata1<keliling[i]){
                    besar1_segitiga ++;
                }
            }

            return make_pair(besar_segitiga, besar1_segitiga);
        }

   };

int main(){
    Lingkaran R;
    Segitiga T;
    double x[100], y[100], r;

    int n, m;

    cin >> n >> m;

    for(int i= 0; i< n; i++){
        cin >> x[0] >> y[0] >> r;
        R.luass(r);
        R.kelilings(r);
    }
    R.rataan();

    for (int i =0; i< m; i++){
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

        for(int j=0; j < 3 ;j++){
            T.set(x[j], y[j]);
        }
        T.luas1();
        T.keliling1();
    }
    T.rataan1();

    cout << R.count().first << " " << T.count1().first << endl;
    cout << R.count().second << " " << T.count1().second << endl;

}
