#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include<numeric>
#include<map>

using namespace std;

int main(){
    string s;
    int kurang =0;
    int lebih =0;
    map <string, int> m;
    map <string, int>::iterator it;

    
    while(cin >> s){
        if(s!="<TEXT>" && s!= "</TEXT>" && s!=":" && s!="." && s!="," && s!="-" && s!= "(" && s!=")" && s!=";"){
            for(int i =0; i<s.length(); i++){
                if (s[i]==':' || s[i]=='.' || s[i]==',' || s[i]=='-' || s[i]=='(' || s[i]==')' || s[i]==';'){
                    s.erase(s.begin()+i);
                    i--;
                }
                s[i] = tolower(s[i]);
            }
            if(s.length()>= 3){
                m[s]++;
            }
        }
    }

    for(it = m.begin(); it!=m.end(); ++it){
        if(it-> second < 3) kurang++;
        if(it-> second > 3) lebih++;
    }

    cout << lebih << " " << kurang << endl;

}