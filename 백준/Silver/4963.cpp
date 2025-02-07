#include<iostream>
#include<queue>

using namespace std;

int n,m;
int island[51][51],visited[51][51];
queue<pair<int,int>> q;

void bfs(int x,int y){
    int dx[] = {0,1,0,-1,1,1,-1,-1};
    int dy[] = {1,0,-1,0,-1,1,-1,1};
    q.push({x,y});
    visited[x][y] = 1;
    while(!q.empty()){
        //cout<<"x: "<<q.front().first<<", y: "<<q.front().second<<" ";
        int x_cur = q.front().first, y_cur = q.front().second;
        for(int i=0;i<8;i++){
            int X = x_cur + dx[i], Y = y_cur+dy[i];
            if(X>=0 && X<n && Y>=0 && Y<m){
                if(!visited[X][Y] && island[X][Y]){
                    q.push({X,Y});
                    visited[X][Y]=1;
                }
            }
            
        }
        q.pop();
    }
    //cout<<"\n";
}

int counting(){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && island[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    cin>>m>>n;
    while(n!=0 && m!=0){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>island[i][j];
                visited[i][j] = 0;
            }
        }
        cout<<counting()<<"\n";
        cin>>m>>n;
    }
}