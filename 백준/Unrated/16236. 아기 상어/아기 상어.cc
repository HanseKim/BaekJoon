#include<bits/stdc++.h>
using namespace std;

pair<int,int> shark;
queue<pair<int,int>> q, start, eat;
int T=0,n,**fish,time_[21][21],fish_size=2,eat_cnt=0,dx[4] = {-1,0,0,1}, dy[4] = {0,-1,1,0};

void print_fish(pair<int,int> a){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==a.first && j==a.second) {
                cout<<"*"<<" ";
                continue;
            }
            cout<<fish[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

pair<int,int> near(int X,int Y){
    int x,y,min=99999,min_x=0,min_y=0;
    //cout<<"Find Near ! :\n";
    while(!eat.empty()){
        x = eat.front().first; y = eat.front().second;
        //cout<<"x: "<<x<<" y: "<<y<<"\n";
        if(time_[x][y] < min){
            min = time_[x][y];
            min_x = x;
            min_y = y;
        }
        else if(time_[x][y] == min){
            if(x < min_x){
                min_x = x;
                min_y = y;
            }
            else if(x == min_x && y < min_y){
                min_x = x;
                min_y = y;
            }
        }
        eat.pop();
    }
    //cout<<"Near x: "<<min_x<<" y: "<<min_y<<"\n";
    return {min_x,min_y};
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    fish = new int*[n]; for(int i=0;i<n;i++) fish[i] = new int[n];
    //time_ = new int*[n]; for(int i=0;i<n;i++) time_[i] = new int[n];
    //input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>fish[i][j];
            if(fish[i][j]==9) {
                shark = {i,j};
                fish[i][j] = 0;
            }
        }
    }
    start.push(shark);//시작점체크용
    q.push(shark);//처음 bfs용
    while(!start.empty()){
        //print_fish(start.front());
        int X=start.front().first,Y=start.front().second;
        start.pop();
        //initialize
        for(int i=0;i<n;i++)
            //memset(time_[i], 0, sizeof(int) * n);
            for(int j=0;j<n;j++) time_[i][j] = 0;
        //bfs
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            for(int i=0;i<4;i++){
                //범위 안 일때
                if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<n){
                    //eat fish
                    if(fish[x+dx[i]][y+dy[i]] > 0 && fish[x+dx[i]][y+dy[i]] < fish_size){
                        if(time_[x+dx[i]][y+dy[i]]==0){
                            time_[x+dx[i]][y+dy[i]] = time_[x][y] + 1;
                            eat.push({x+dx[i],y+dy[i]});
                        }
                    }
                    else if(fish[x+dx[i]][y+dy[i]] == 0 || fish[x+dx[i]][y+dy[i]] == fish_size){
                        if(time_[x+dx[i]][y+dy[i]]==0){
                            q.push({x+dx[i],y+dy[i]});
                            time_[x+dx[i]][y+dy[i]] = time_[x][y]+1;
                        }
                    }
                }
            }
            q.pop();
        }
        if(!eat.empty()) {
            start.push(near(X,Y));
            fish[start.front().first][start.front().second] = 0;
            T+=time_[start.front().first][start.front().second];
            q.push({start.front().first,start.front().second});
            eat_cnt++;
            if(eat_cnt == fish_size){
                fish_size++;
                eat_cnt=0;
            }
        }
    }
    cout<<T;
}