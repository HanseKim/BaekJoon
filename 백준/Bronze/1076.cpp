#include<iostream>
#include<cmath>
#define black 0
#define brown 1
#define red 2
#define orange 3
#define yellow 4
#define green 5
#define blue 6
#define violet 7
#define grey 8
#define white 9
using namespace std;

int main(){
    long res=0;
    string color;
    for(int i=0;i<2;i++){
        cin>>color;
        res*=10;
        if(color=="black") res+=black;
        else if(color=="brown") res+=brown;
        else if(color=="red") res+=red;
        else if(color=="orange") res+=orange;
        else if(color=="yellow") res+=yellow;
        else if(color=="green") res+=green;
        else if(color=="blue") res+=blue;
        else if(color=="violet") res+=violet;
        else if(color=="grey") res+=grey;
        else if(color=="white") res+=white;
    }
    cin>>color;
    if(color=="black") res*=pow(10,black);
    else if(color=="brown") res*=pow(10,brown);
    else if(color=="red") res*=pow(10,red);
    else if(color=="orange") res*=pow(10,orange);
    else if(color=="yellow") res*=pow(10,yellow);
    else if(color=="green") res*=pow(10,green);
    else if(color=="blue") res*=pow(10,blue);
    else if(color=="violet") res*=pow(10,violet);
    else if(color=="grey") res*=pow(10,grey);
    else if(color=="white") res*=pow(10,white);
    cout<<res;
}