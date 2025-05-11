#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int minPalindromeCuts(const string& s) {
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // 길이 1: 자기 자신은 항상 팰린드롬
    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    // 길이 2 이상 팰린드롬 판별
    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            if (s[i] == s[j]) {
                if (length == 2 || dp[i + 1][j - 1])
                    dp[i][j] = true;
            }
        }
    }

    vector<int> cut(n, 0);
    for (int i = 0; i < n; ++i) {
        if (dp[0][i]) {
            cut[i] = 0;
        } else {
            cut[i] = numeric_limits<int>::max();
            for (int j = 0; j < i; ++j) {
                if (dp[j + 1][i] && cut[j] + 1 < cut[i]) {
                    cut[i] = cut[j] + 1;
                }
            }
        }
    }

    return cut[n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << minPalindromeCuts(s) << '\n';
    }

    return 0;
}
