#include<bits/stdc++.h>
using namespace std;

using namespace std;

int main(){
	int tc;
	scanf("%d",&tc);
	for(int t=1;t<=tc;t++){
		int M,N,x,y;
		scanf("%d %d %d %d",&M,&N,&x,&y);
		int big=M>N?M:N;
		int small=M<N?M:N;
        int X,Y;
        if( M==N){
            X = x;
            Y = y;
        }
        else{
            X=M<N?x:y;
            Y=M>N?x:y;//M,N의 크기에 따라 x,y를 바꿔준다.
        }
        
        
		
        
		long long int itr=M*N;//따로 최소공배수 안구함
		long long int year=X;//작은 수를 중심으로 year를 구한다.
		int id=1;
		bool check=false;
		while(year<=itr){
			int cmp;
			if(year%big==0){
				cmp=big;
			}
			else
				cmp=year%big;
			if(cmp==Y){
				check=true;
				break;
			}
			year+=small;//year를 작은 m에 따라 증가시켜줌
		}
		if(!check)
			printf("-1\n");
		else
			printf("%ld\n",year);
	}
}