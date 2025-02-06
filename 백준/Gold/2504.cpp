#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    string s; cin >> s;
    stack<char> st;  // 스택을 전역 변수로 두지 않고 main 안에서 선언
    int res = 0, temp = 1;
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            temp *= 2;
            st.push('(');
        }
        else if(s[i] == ')') {
            if(st.empty() || st.top() != '(') { // 스택이 비어있는 경우 처리
                cout << 0;
                return 0;
            }
            if(i > 0 && s[i-1] == '(') res += temp;
            temp /= 2;
            st.pop();
        }
        else if(s[i] == '['){
            temp *= 3;
            st.push('[');
        }
        else if(s[i] == ']') {
            if(st.empty() || st.top() != '[') { // 스택이 비어있는 경우 처리
                cout << 0;
                return 0;
            }
            if(i > 0 && s[i-1] == '[') res += temp;
            temp /= 3;
            st.pop();
        }
    }
    
    if(!st.empty()) cout << 0;  // 모든 괄호가 짝이 맞지 않으면 0 출력
    else cout << res;
}
