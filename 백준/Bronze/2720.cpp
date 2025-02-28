#include<iostream>

using namespace std;

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test; cin >> test;
    while(test--){
        int c;cin>>c;
        int arr[] = {25,10,5,1};
        int cnt[4] = {0,};
        for(int i=0;i<4;i++){
            cnt[i] = c/arr[i];
            c %= arr[i];
        }
        for(int i=0;i<4;i++){
            cout << cnt[i] << " ";
        }
        cout << "\n";
    }
}