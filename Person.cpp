#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>

using namespace std;

class Person{
private:
    string nama[100];
    int usia[100];
    int tinggi[100];
    double berat[100], hasil;
    int n;



public:
    Person(){
        nama[0] = "";
        usia[0] = 0;
        tinggi[0] = 0;
        berat[0] = 0;
    }

    void setPerson(){
        cin >> n;

        for(int i = 0; i< n; i++){
            cin >> nama[i] >> usia[i] >> tinggi[i] >> berat[i];
        }
    }

    void hitung(){
        double jumlah =0;
        int satu = 0;

        for(int i = 0; i< n;i ++){
            jumlah = jumlah + tinggi[i];
        }
        hasil = jumlah/n;
        for(int i= 0; i< n; i++){
            if(tinggi[i] > hasil){
                satu++;
            }
        }

        for(int i= 0; i< n; i++){
            cout << nama[i] << " " << usia[i] << endl;
        }
            cout << fixed << setprecision(2) << hasil << endl;
            cout << satu << endl;
    }

};


int main(){
    Person x;

    x.setPerson();
    x.hitung();

    return 0;
}
