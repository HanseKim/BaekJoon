#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int m,cnt=0;
    cin>>m;
    for(int i=0;i<n;i++)
        if(arr[i]==m) cnt++;
    cout<<cnt;
}