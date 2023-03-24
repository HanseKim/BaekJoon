#include<bits/stdc++.h>
using namespace std;

int T,A,B;


int _L(int _a){
    int n1 = _a/1000,n2=(_a/100)%10,n3=(_a/10)%10,n4=_a%10;
    return n2*1000 + n3*100 + n4*10 + n1;
}
int _R(int _a){
    int n1 = _a/1000,n2=(_a/100)%10,n3=(_a/10)%10,n4=_a%10;
    return n4*1000 + n1*100 + n2*10 + n3;
}

int main(){
    cin>>T;
    while(T--){
        cin>>A>>B;
        int visited[10001]={0,};
        queue<pair<int,string>> q;
        q.push({A,""});
        visited[A] = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front().first;
                string str = q.front().second;
                q.pop();

                if(curr==B) { cout<<str<<"\n"; while(!q.empty()) q.pop(); break;}

                int D = (curr*2)%10000;
                if(!visited[D]) {
                    q.push({D,str+"D"}); visited[D] = 1;
                }
                int S = (curr - 1 + 10000) % 10000;
                if(!visited[S]){
                    q.push({S,str+"S"}); visited[S] = 1;
                }
                int L = _L(curr);
                if(!visited[L]){
                    q.push({L,str+"L"}); visited[L] = 1;
                }
                int R = _R(curr);
                if(!visited[R]){
                    q.push({R,str+"R"}); visited[R] = 1;
                }
            }
        }
    }
}