#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <numeric>
using namespace std;


class Bilangan{
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
public:
    Bilangan(){
        int nilai = 0;
        while(nilai!=-9){
            cin >> nilai;
            if(nilai != -9){
                v1.push_back(nilai);            
            }
            else{
                break;
            }
        }
        nilai = 0;
        while(nilai!=-9){
            cin >> nilai;
            if(nilai != -9){
                v2.push_back(nilai);            
            }
            else{
                break;
            }
        }

    }


    void hapus(){
        v3 = v1;
        //vector<int>::iterator i;        
        for(;!v2.empty();v2.pop_back()){
            v3.erase(v3.begin()+v2.back()-1);
            //cout << " " << *i;
        }
    }

    double rata1(){
        if(v1.empty()){
            return -9.99;
        }
            return accumulate(v1.begin(), v1.end(), 0.0)/v1.size();
    }

    double rata2(){
        if(v3.empty()){
            return -9.99;
        }
            return accumulate(v3.begin(), v3.end(), 0.0)/v3.size();
    }

    int vsatu(){
        return v1.size();
    }
  
   int vtiga(){
        return v3.size();
    }
};


int main(){
    Bilangan x;

    x.hapus();
    cout << x.vsatu() << " " << x.vtiga() << endl;
    cout<< fixed << setprecision(2) << x.rata1()<<" " <<  x.rata2() << endl;
}