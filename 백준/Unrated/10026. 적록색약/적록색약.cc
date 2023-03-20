#include<bits/stdc++.h>
using namespace std;
int n;
char grid[101][101];
int vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dfs(int i,int j){    
    vis[i][j] = 1;
    for(int p=0;p<4;p++){
        int nx = i + dx[p];
        int ny = j + dy[p];
        if(nx<0||ny<0||nx>=n||ny>n) continue;
        if(vis[nx][ny]||grid[nx][ny]!=grid[i][j]) continue;
        dfs(nx,ny);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        cin>>grid[i][j];
    }
    /*print
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    //dfs
    int normal=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]) continue;
            dfs(i,j);
            normal++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 'R')grid[i][j]='G';
            vis[i][j] = 0;
        }
    }
    int abnormal=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]) continue;
            dfs(i,j);
            abnormal++;
        }
    }
    cout<<normal<<" "<<abnormal;
}