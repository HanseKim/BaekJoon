/**
 * @file 1992 쿼드트리.cpp
 * @author HanseKim (kimbird2002@naver.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-25
 * @see https://www.acmicpc.net/problem/1992
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>

using namespace std;

char** arr;

void F(int x,int y,int n){
    
    int state=0;
    char c = arr[x][y];
    for(int i=x;i<n+x;i++){
        for(int j=y;j<n+y;j++){
            if(state==0 && arr[i][j] != c){
                cout<<"(";
                F(x,y,n/2);
                F(x,y+n/2,n/2);
                F(x+n/2,y,n/2);
                F(x+n/2,y+n/2,n/2);
                state=1;
                cout<<")";
            }
            if(state) break;
        }
        if(state) break;
    }
    if (!state)
    {
        cout<<c;
    }
    
}

int main(){
    cin.tie(0);
    int n; cin>>n;
    arr = new char*[n];
    for(int i=0;i<n;i++){
        arr[i] = new char[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    F(0,0,n);
    
}