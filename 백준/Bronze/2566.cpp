#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector< vector<int> > v(9, vector<int>(9, 0));
    int max = 0, x = 0, y = 0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>v[i][j];
            if(v[i][j] > max){
                max = v[i][j];
                x = i;
                y = j;
            }
        }
    }
    cout<<max<<'\n'<<x+1<<' '<<y+1;
}