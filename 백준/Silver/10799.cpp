#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    string s;
    cin>>s;
    stack<string> st;
    int res=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push("(");
        }
        else if(s[i]==')' && s[i-1] ==')') {
            res+=1;
            st.pop();
        }
        else if(s[i] ==')'){
            st.pop();
            res+=st.size();
        }
    }
    cout<<res;
}