#include<bits/stdc++.h>
using namespace std;

int main(){
    int board[101] = {0,};
    int dice[6] = {1,2,3,4,5,6};
    int n,m; cin>>n>>m;
    map<int,int> snake;
    queue<int> q;
    for(int i=0;i<n+m;i++){
        int a,b;
        cin>>a>>b;
        snake.insert({a,b});
    }
    q.push(1);
    int k=0,front = q.front();q.pop();
    while(front!=100){
        for(int i=1;i<=6;i++){
            if(front+i>100) break;
            if(snake.find(front+i)!=snake.end()){
                if(board[snake[front+i]]==0 || board[snake[front+i]] > board[front]+1) {
                    board[snake[front+i]] = board[front]+1;
                    q.push(snake[front+i]);
                }
            }
            else if(board[front+i]==0) {
                board[front+i] = board[front] + 1;
                q.push(front+i);
            }
            else if(board[front+i] > board[front]+1){
                board[front+i] = board[front]+1;
                q.push(front+i);
            }
        }
        front = q.front(); q.pop();
    }
    cout<<board[100];
}