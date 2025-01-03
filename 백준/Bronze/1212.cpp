#include<iostream>
#include<string>
using namespace std;

string oct2binary(char oct){
    string binary = "";
    int o = oct-'0';
    for(int i=0;i<3;i++){
        binary = to_string(o%2) + binary;
        o/=2;
    }
    return binary;
}

int main(){
    int first=0;
    string oct,bin="";
    cin >> oct;
    if(oct=="0"){
        cout << "0\n";
        return 0;
    }
    for(int i=0;i<oct.length();i++){
        bin +=  oct2binary(oct[i]);
    }
    for(int i=0;i<bin.length();i++){
        if(first==0 && bin[i]=='0') continue;
        if(first==0 && bin[i]=='1') first = 1;
        cout << bin[i];
    }
    cout<<"\n";
}