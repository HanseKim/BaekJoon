#include<iostream>
#include<queue>

using namespace std;

int cnt=0;
queue<pair<int,int>> q;

void move(int n, int fr, int to, int els){
    if(n==1){
        q.push({fr,to});
        cnt++;
        return;
    }
    move(n-1,fr,els,to);
    q.push({fr,to});
    cnt++;
    move(n-1,els,to,fr);
}

int main(){
    int n; cin>>n;
    move(n,1,3,2);
    cout<<cnt<<"\n";
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        cout<<a<<" "<<b<<"\n";
        q.pop();
    }
}