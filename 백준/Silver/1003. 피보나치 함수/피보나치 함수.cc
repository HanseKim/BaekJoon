#include<iostream>

using namespace std;
int zero[41]={0,}, one[41]={0,};

void fibo(int n){
    for(int i=2;i<=n;i++){
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1]+ one[i-2];
    }
}

int main(){
    int t; scanf("%d",&t);
    zero[0] = 1; one[0] = 0;
    zero[1] = 0; one[1] = 1;
    for(int i=0;i<t;i++){
        int n; scanf("%d",&n);
        if(zero[n]==0 && one[n]==0){
            fibo(n);
        }
        printf("%d %d\n",zero[n],one[n]);
    }
}