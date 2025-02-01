#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    int b;
    long long res = 0;
    
    cin >> s >> b;
    
    for(char c : s) {
        res *= b;
        if(isalpha(c)) {
            res += toupper(c) - 'A' + 10;
        } else {
            res += c - '0';
        }
    }
    
    cout << res;
    return 0;
}