#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;    

int main(){
    int n,check=0; cin>> n;
    map<char, int> m;
    for(int i=0; i<n; i++){
        string s; cin>> s;
        m[s[0]]++;
    }
    for(auto i=m.begin(); i!=m.end(); i++){
        if(i->second > 4){
            check++;
            cout<< i->first << "";
        }
    }
    if(check==0) cout<<"PREDAJA";
}