#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n; cin>>n;
    int arrA[n], arrB[n];
    priority_queue<int,vector<int>,greater<int>> pqA;
    priority_queue<int> pqB;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        pqA.push(a);
    }
    for(int i=0;i<n;i++){
        int b; cin>>b;
        pqB.push(b);
    }
    int res=0;
    while(!pqA.empty()){
        res += pqA.top() * pqB.top();
        pqA.pop();
        pqB.pop();
    }
    cout<<res;
}