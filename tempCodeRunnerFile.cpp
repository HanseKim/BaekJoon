#include<iostream>
#include<stack>
#include<string>

using namespace std;

stack<char> st;

int main(){
    string s; cin>>s;
    int res = 0, temp = 1;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            temp *= 2;
        }
        else if(s[i-1]=='(' && s[i] ==')'){
            res += temp; temp/=2;
        }
        else if(s[i] == ')') temp/=2;
        else if(s[i] =='['){
            temp*=3;
        }
        else if(s[i-1]=='[' && s[i] ==']'){
            res += temp; temp/=3;
        }
        else if(s[i]==']') temp/=3;
    }
    if(temp != 1) cout<<0;
    else cout<<res;
}