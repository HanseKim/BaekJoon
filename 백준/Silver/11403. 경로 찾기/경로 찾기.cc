#include<iostream>
#include<queue>
using namespace std;
queue<int> q;

int main(){
  int n; cin>>n;
  int arr[n][n] = {{0}}, res[n][n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      res[i][j] = 0;
  for(int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      int m;cin>>m;
      arr[i][j] = m;
    }
  }

  //bfs
  for(int x=0; x<n; x++){
    while(!q.empty()) q.pop();
    q.push(x);
    int chk[101];
    for(int i=0;i<n;i++) chk[i]=0;
    while(!q.empty()){
      for(int i=0;i<n;i++){
        if(arr[q.front()][i] ==1 && chk[i]!=1){
          q.push(i);
          res[x][i] = 1;
          chk[i] = 1;
        }
      }
      q.pop();
    }
  }

  //print arr
  for(int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cout<<res[i][j]<<" ";
    }
    cout<<"\n";
  }
  
}