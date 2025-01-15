#include<iostream>
using namespace std;

int main(){
    int n,l,d;
    cin>>n>>l>>d;
    int time = l,flag=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<5;j++){
            if(time%d == 0){
                cout<<time;
                return 0;
            }
            time+=1;
        }
        time+=l;
    }
    while(time%d!=0){
        time+=1;
    }
    cout<<time;
    return 0;
}