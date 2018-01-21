#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

class ClassPertama {
private:
    double nilai1, nilai2;

public:
    ClassPertama(){
        nilai1 = 0;
        nilai2 = 0;
    }
    void SetNilai(){
        cin >> nilai1;
        cin >> nilai2;
    }

    double hitung(){
        return nilai1+nilai2;
    }
};

int main(){
    ClassPertama x;

    x.SetNilai();
    cout << fixed << setprecision(2) << x.hitung() << endl;
}

