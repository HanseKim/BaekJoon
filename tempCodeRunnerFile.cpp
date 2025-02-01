#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main(){
    string s;
    long long b, res=0, j=1;
    cin>>s>>b;
    for(int i=s.length()-1;i>=0;i--){
        if(isalpha(s[i]) == 1){
            res += j * (s[i] - 'A' + 10 );
        }
        else {
            res += j * (s[i] - '0' );
        }
        j*=b;
    }
    printf("%lld", res);
}