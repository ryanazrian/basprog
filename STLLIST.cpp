#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include <numeric>
#include<list>


using namespace std;

class StlList {
   private:
      string nama;
      int usia;
      int tinggi;
      double berat;
      double imt;
      string status;
      double IMT() { double t=(double)tinggi/100.0; return (berat/(t*t)); }
      string StatusGizi() {
         double t=IMT();
         if (t<17.0) return "sangat kurus";
         else if (t<18.5) return "kurus";
         else if (t<25.0) return "normal";
         else if (t<28.0) return "gemuk";
         else return "sangat gemuk"; }
   public:
      StlList() { nama=""; usia=tinggi=0; berat=0.0; }
      void setPerson(string nm, int u, int t, double b) {
         nama=nm; usia=u; tinggi=t; berat=b; 
         imt=IMT(); status=StatusGizi();
      }
      string getNama() { return nama; }
      int getUsia() { return usia; }
      int getTinggi() { return tinggi; }
      double getBerat() { return berat; }
      double getIMT() { return imt; }
      string getStatusGizi() { return status; }
      void cetak() {
         cout << nama << " " << usia << " " << tinggi << " ";
         cout << fixed << setprecision(2) << berat << " " << imt << " " << status << endl;
      }
};

int main(){

    string nama;
    int usia, tinggi, n, nilai;
    double berat;

    list <StlList> p;
    list <StlList>::iterator it;

    StlList data;
    cin >> n;
    
    for(int i = 0; i< n; i++){
        cin >> nama >> usia >> tinggi >> berat;
        data.setPerson(nama, usia, tinggi, berat);
        p.push_back(data);
    }

    while (n !=-9){
        cin >> n;
        if (n == -9 ){
            break;
        }
        else if(n==1){
            cin >> nama >> usia >> tinggi >> berat;
            data.setPerson(nama, usia, tinggi, berat);
            p.push_front(data);
        }
        else if(n == 2){
            cin >> nama >> usia >> tinggi >> berat;
            data.setPerson(nama, usia, tinggi, berat);
            p.push_back(data);
        }

        else if(n==3){
            p.pop_front();
        }

       else if(n==4){
            p.pop_back();
        }
       else if( n==5){
           cin >> nilai;
           cin >> nama >> usia >> tinggi >> berat;
           data.setPerson(nama, usia, tinggi, berat);
           it = p.begin();

           for (int i =0;i<nilai;i++){
               it++;
           }
           p.insert(it, data);
       }
    }
    for(it = p.begin(); it!=p.end(); it++){
        (*it).cetak();
    }
}