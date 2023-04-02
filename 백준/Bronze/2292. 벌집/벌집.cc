#include<stdio.h>
int main(){
	int n,i=1,end=7;
	scanf("%d",&n);

	if(n==1) {
		printf("1");
	}
	else{
		while(end<n){
			i+=1;
			end+=6*i;
		}
		printf("%d",i+1);
	}

}
