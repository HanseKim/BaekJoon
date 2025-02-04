#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n,m,k;
int rec[101][101];
int visited[101][101];
queue<pair<int,int>> q;
vector<int> v;

int bfs(){
    int cnt=0;
    while(!q.empty()){
        cnt++;
        int x,y; 
        x = q.front().first; y = q.front().second;
        q.pop();
        if(x-1>=0 && visited[x-1][y]==0 && rec[x-1][y]==0){
            visited[x-1][y] = 1;
            q.push({x-1,y});
        }
        if(x+1<n && visited[x+1][y]==0 && rec[x+1][y]==0){
            visited[x+1][y] = 1;
            q.push({x+1,y});
        }
        if(y-1>=0 && visited[x][y-1]==0 && rec[x][y-1]==0){
            visited[x][y-1] = 1;
            q.push({x,y-1});
        }
        if(y+1<m && visited[x][y+1]==0 && rec[x][y+1]==0){
            visited[x][y+1] = 1;
            q.push({x,y+1});
        }
    }
    return cnt;
}

int main(){
    cin>>m>>n>>k;
    for(int i=0;i<k;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int x=x1;x<x2;x++){
            for(int y=y1;y<y2;y++){
                rec[x][y] = 1;
                visited[x][y] = 1;
            }
        }
    }
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            if(rec[x][y] == 0 && visited[x][y]==0){
                visited[x][y] = 1;
                q.push({x,y});
                v.push_back(bfs());
            }
        }
    }
    cout<<v.size()<<"\n";   
    sort(v.begin(),v.end());
    for(int vec : v){
        cout<<vec<<' ';
    }
}