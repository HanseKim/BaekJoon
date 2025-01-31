#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    int res=0;
    vector<vector<int>> v(100,vector<int>(100,0));
    int arr[n][2];
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    for(int i=0;i<n;i++){
        for(int x=arr[i][0];x<arr[i][0]+10;x++){
            for(int y=arr[i][1];y<arr[i][1]+10;y++){
                if(v[x][y] == 0) {
                    res++;
                    v[x][y] = 1;
                }
            }
        }
    }
    cout<<res;
}