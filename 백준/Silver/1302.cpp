#include<iostream>
#include<map>

using namespace std;

int main(){
    map<string, int> m;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        if(m.find(s) != m.end()){
            m[s]++;
        }
        else {
            m.insert({s,1});
        }
    }
    string best = m.begin()->first;
    int bestnum = m.begin()->second;
    map<string,int>::iterator iter;
    for(iter = m.begin();iter!=m.end();iter++){
        if(iter->second > bestnum) {
            bestnum = iter->second;
            best = iter->first;
        }
    }
    cout<<best;
}