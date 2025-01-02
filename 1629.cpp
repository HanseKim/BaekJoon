#include<iostream>
using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    long long result = 1;
    while(b > 0){
        if(b % 2 == 1){
            result *= a;
            result %= c;
        }
        a *= a;
        a %= c;
        b /= 2;
    }
    cout << result << endl;
    return 0;
}