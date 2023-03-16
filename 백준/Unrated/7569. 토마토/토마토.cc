#include <bits/stdc++.h>

using namespace std;

int m,n,h;
int *tomato,*date;
queue<int> q;

void print_tomato(){
    cout<<"\n";
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int p=0;p<m;p++)
                cout<<tomato[((m*n)*i)+(m*j)+p]<<" ";
            cout<<"\n";
        }
    }
}
void input_tomato(){
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int p=0;p<m;p++){
                cin>>tomato[((m*n)*i)+(m*j)+p];
                if(tomato[((m*n)*i)+(m*j)+p] == 1){
                    q.push(i); q.push(j); q.push(p); // h n m
                    date[((m*n)*i)+(m*j)+p] = 1;
                }
                else if(tomato[((m*n)*i)+(m*j)+p] == -1){
                    date[((m*n)*i)+(m*j)+p] = -1;
                }
            }
        }
    }
}
int bfs(){
    while(!q.empty()){
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        int z = q.front(); q.pop();
        //up - flour
        if(x + 1 < h && tomato[(m*n)*(x+1) + m*y + z] == 0){
            tomato[(m*n)*(x+1) + m*y + z] = 1;
            date[(m*n)*(x+1) + m*y + z] = date[(m*n)*x + m*y + z] + 1;
            q.push(x+1); q.push(y); q.push(z);
        }
        //down - flour
        if(x - 1 >= 0 && tomato[(m*n)*(x-1) + m*y + z] == 0){
            tomato[(m*n)*(x-1) + m*y + z] = 1;
            date[(m*n)*(x-1) + m*y + z] = date[(m*n)*x + m*y + z] + 1;
            q.push(x-1); q.push(y); q.push(z);
        }
        //right
        if(z + 1 < m && tomato[(m*n)*x + m*y + z + 1] == 0){
            tomato[(m*n)*x + m*y + z + 1] = 1;
            date[(m*n)*x + m*y + z + 1] = date[(m*n)*x + m*y + z] + 1;
            q.push(x); q.push(y); q.push(z+1);
        }
        //left
        if(z - 1 >= 0 && tomato[(m*n)*x + m*y + z - 1] == 0){
            tomato[(m*n)*x + m*y + z - 1] = 1;
            date[(m*n)*x + m*y + z - 1] = date[(m*n)*x + m*y + z] + 1;
            q.push(x); q.push(y); q.push(z-1);
        }
        //up
        if(y + 1 < n && tomato[(m*n)*x + m*(y+1) + z] == 0){
            tomato[(m*n)*x + m*(y+1) + z] = 1;
            date[(m*n)*x + m*(y+1) + z] = date[(m*n)*x + m*y + z] + 1;
            q.push(x); q.push(y+1); q.push(z);
        }
        //down
        if(y - 1 >= 0 && tomato[(m*n)*x + m*(y-1) + z] == 0){
            tomato[(m*n)*x + m*(y-1) + z] = 1;
            date[(m*n)*x + m*(y-1) + z] = date[(m*n)*x + m*y + z] + 1;
            q.push(x); q.push(y-1); q.push(z);
        }
    }
    int max=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int p=0;p<m;p++){
                if(max<=date[(m*n)*i + m*j + p]) max = date[(m*n)*i + m*j + p];
                if(date[(m*n)*i + m*j + p] == 0){
                    return -1;
                }
            }
        }
    }
    return max-1;
}

int main()
{
    cin>>m>>n>>h;
    tomato = new int[m*n*h];
    date = new int[m*n*h];
    input_tomato();

    cout<<bfs();
    //print_tomato();
}
