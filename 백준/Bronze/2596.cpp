#include<iostream>
#define A "000000"
#define B "001111"
#define C "010011"
#define D "011100"
#define E "100110"
#define F "101001"
#define G "110101"
#define H "111010"
#include<string>

using namespace std;

int n; 

int diff_cnt(string a, string b){
    int cnt=0;
    for(int i=0;i<6;i++){
        if(a[i] != b[i]) cnt++;
    }
    return cnt;
}

int main(){
    cin>>n;
    string str,arr[] = {A,B,C,D,E,F,G,H},res=("");
    cin>>str;
    for(int i=0;i<n;i++){
        string substr = str.substr(i*6,6);
        for(int j=0;j<8;j++){
            if(diff_cnt(substr, arr[j]) < 2){
                switch (j){
                    case 0: 
                        res+="A";
                        break;
                    case 1:
                        res+="B";
                        break;
                    case 2:
                        res+="C";
                        break;
                    case 3:
                        res+="D";
                        break;
                    case 4:
                        res+="E";
                        break;
                    case 5:
                        res+="F";
                        break;
                    case 6:
                        res+="G";
                        break;
                    default:
                        res+="H";
                        break;
                }
                break;
            }
            if(j==7 && diff_cnt(substr,arr[5])>=2){
                cout<<i+1;
                return 0;
            }
        }
    }
    cout<<res;
    return 0;
}