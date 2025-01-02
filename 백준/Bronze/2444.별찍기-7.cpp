#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int space = n-1;
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<abs(space);j++) cout<<" ";
        for(int j=0;j<2*n-1-abs(space)*2;j++) cout<<"*";
        cout<<"\n";
        space--;
    }
}