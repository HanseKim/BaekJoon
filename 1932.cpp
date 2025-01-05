#include <iostream>
#include <vector>
using namespace std;

int main() {
    long n;
    cin >> n;
    vector<long> arr((n * (n + 1)) / 2 + 1, 0);
    long max = 0, cnt = 1, plus = 1;

    for (int i = 1; i <= (n * (n + 1)) / 2; i++) {
        long num;
        cin >> num;
        arr[i] += num;
        if (i + plus <= (n * (n + 1)) / 2 && arr[i + plus] < arr[i])
            arr[i + plus] = arr[i];
        if (i + plus + 1 <= (n * (n + 1)) / 2 && arr[i + plus + 1] < arr[i])
            arr[i + plus + 1] = arr[i];
        if (cnt == plus) {
            plus++;
            cnt = 0;
        }
        cnt++;
    }

    for (int i = (n * (n + 1)) / 2; i >= (n * (n + 1)) / 2 - plus; i--) {
        if (max < arr[i])
            max = arr[i];
    }
    if(n==1) cout << arr[1];
    else 
        cout << max;
}