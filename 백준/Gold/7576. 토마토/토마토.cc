//7576 tomato
#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;
int tomato[1000][1000]={{0}};
int date[1000][1000]={{0}}; //dp
int main(){
	int n,m;
	
	scanf("%d %d",&m,&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&tomato[i][j]);
			if(tomato[i][j] ==1){ //1일때 큐에 좌표넣기 
				q.push(i);
				q.push(j);
				date[i][j] = 1;
			}
			if(tomato[i][j]==-1){
				date[i][j]=-1;
			}
		}
	}
	
	while(!q.empty()){
		int a=q.front();
		q.pop();
		int b=q.front();
	
		if(tomato[a-1][b]==0&&a>=1){ //윗칸 
			tomato[a-1][b] =1;
			date[a-1][b]=date[a][b]+1;
			q.push(a-1);
			q.push(b);
		}
		if(tomato[a+1][b]==0&&a<n-1){ //아랫칸 
			tomato[a+1][b] =1;
			date[a+1][b]=date[a][b]+1;
			q.push(a+1);
			q.push(b);
		}
		if(tomato[a][b+1]==0&&b<m-1){ //오른쪽칸 
			tomato[a][b+1] =1;
			date[a][b+1]=date[a][b]+1;
			q.push(a);
			q.push(b+1);
		}
		if(tomato[a][b-1]==0&&b>=1){ //왼쪽칸 
			tomato[a][b-1] =1;
			date[a][b-1]=date[a][b]+1;
			q.push(a);
			q.push(b-1);
		}
		q.pop();
	}

	int max=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(max<=date[i][j]) max = date[i][j];
			if(date[i][j]==0) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d",max-1);
}