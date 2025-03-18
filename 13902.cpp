#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(10000 + 1, -1); // -1: 아직 안 함
vector<int> s(1001, -1);

int wock(int n) {
    if (n < 0) return 0; // 음수면 불가능
    if (n == 0) return 1; // 0이면 가능
    if (dp[n] != -1) return dp[n]; // 이미 방문했으면 반환

    dp[n] = 0; // 기본값: 불가능
    for (int i = 0; i < 1001 && s[i] != -1; i++) {
        if (wock(n - s[i])) { // 남은 시간으로 가능하면
            dp[n] = 1; // 가능
            break; // 더 볼 필요 없음
        }
    }
    return dp[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> s[i];

    cout << wock(n);
    return 0;
}
