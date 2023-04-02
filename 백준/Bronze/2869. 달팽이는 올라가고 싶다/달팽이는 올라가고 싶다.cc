
#include<stdio.h>
int main(){
	int h=0,a,b,v,day;
	scanf("%d %d %d",&a,&b,&v);
	day=(v-b)/(a-b);
	if((v-b)%(a-b)!=0){
		day+=1;
	}
	printf("%d",day); 
}
