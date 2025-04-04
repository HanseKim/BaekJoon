#include<iostream>
#include<queue>

using namespace std;

int city[21][21] ={{0}};

int main(){
    int n, c1, c2;
    cin>>n>>c1>>c2;
    for ( int i=0;i<n-1;i++){
        int a,b,l; cin>>a>>b>>l;
        city[a][b] = l;
        city[b][a] = l;
    }
}