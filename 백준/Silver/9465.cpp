#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int test; cin>>test;
    int arr[2][100001]={{0}} , dp[2][100001] ={{0}};
    while(test--){
        int n,res=0; cin>>n;
        for(int i=0;i<n;i++) cin>>arr[0][i];
        for(int i=0;i<n;i++) cin>>arr[1][i];
        for(int i=0;i<n;i++){
            if(i==0){
                dp[0][0] = arr[0][0];
                dp[1][0] = arr[1][0];
                res = max(dp[0][0],dp[1][0]);
            }if(i==1){
                dp[0][1] = arr[0][1] + dp[1][0];
                dp[1][1] = arr[1][1] + dp[0][0];
                res = max(res, dp[0][1]);
                res = max(res,dp[1][1]);
            }else{
                dp[0][i] = max(arr[0][i] + dp[1][i-1], arr[0][i]+dp[1][i-2]);
                dp[1][i] = max(arr[1][i] + dp[0][i-1], arr[1][i]+dp[0][i-2]);
                res = max(res, dp[0][i]);
                res = max(res,dp[1][i]);
            }
        }
        cout<<res<<"\n";
    }
}