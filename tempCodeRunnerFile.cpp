#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<bool> seen(N + 1, false);
    
    int card;
    // 남은 카드들이 몇 장인지 모르지만, 모두 입력받습니다.
    while(cin >> card){
        seen[card] = true;
    }
    
    for (int i = 1; i <= N; i++){
        if (!seen[i])
            cout << i << "\n";
    }
    return 0;
}
