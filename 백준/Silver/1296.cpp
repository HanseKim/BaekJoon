#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;

    set<string> uniqueStrings; // 사전순 정렬을 위한 set 사용

    int n = str.length();
    for (int idx = 1; idx < n - 1; idx++) {
        for (int idx2 = idx + 1; idx2 < n; idx2++) {
            // 문자열 분할
            string s1 = str.substr(0, idx);
            string s2 = str.substr(idx, idx2 - idx);
            string s3 = str.substr(idx2);

            // 문자열 뒤집기
            reverse(s1.begin(), s1.end());
            reverse(s2.begin(), s2.end());
            reverse(s3.begin(), s3.end());

            // 결과 문자열 생성 및 저장
            string res = s1 + s2 + s3;
            uniqueStrings.insert(res);
        }
    }

    // 사전순으로 가장 첫 번째 문자열 출력
    cout << *uniqueStrings.begin() << endl;

    return 0;
}
