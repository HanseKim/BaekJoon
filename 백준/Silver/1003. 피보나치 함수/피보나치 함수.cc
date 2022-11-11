// DP

#include<stdio.h>

int n0[41] = {1,0,};
int n1[41] = {0,1,};

/*
int fibonacci(int n) {
    if (n == 0) {
        n0++;
        return 0;
    } else if (n == 1) {
        n1++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
*/

void fibo(int n){
    if(n==0){
        printf("%d %d\n",n0[0], n1[0]);
    }
    else if(n==1)printf("%d %d\n",n0[1], n1[1]);
    else{
        for(int i=2;i<=n;i++){
            n0[i] = n0[i-1] + n0[i-2];
            n1[i] = n1[i-1] + n1[i-2];
        }
        printf("%d %d\n",n0[n],n1[n]);
    }
}

int main(void){
    int num, n;
    scanf("%d",&num);
    /*
    for(int i=0;i<num;i++){
        scanf("%d",&n);
        n0=0;
        n1=0;
        fibonacci(n);
        printf("%d %d\n",n0, n1);
    }*/
    for(int i=0;i<num;i++){
        scanf("%d",&n);
        fibo(n);
    }
}