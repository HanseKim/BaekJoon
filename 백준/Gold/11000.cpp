#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    // 강의 시작시간과 종료시간을 저장할 벡터
    vector<pair<int, int>> lectures(N);
    
    // 입력 받기
    for(int i = 0; i < N; i++) {
        cin >> lectures[i].first >> lectures[i].second;
    }
    
    // 시작 시간을 기준으로 정렬
    sort(lectures.begin(), lectures.end());
    
    // 현재 사용중인 강의실의 종료 시간을 저장하는 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // 첫 번째 강의의 종료 시간을 우선순위 큐에 삽입
    pq.push(lectures[0].second);
    
    // 두 번째 강의부터 확인
    for(int i = 1; i < N; i++) {
        // 현재 강의실 중 가장 빨리 끝나는 시간보다 
        // 다음 강의 시작시간이 크거나 같다면
        if(pq.top() <= lectures[i].first) {
            // 강의실을 이어서 사용할 수 있으므로 pop
            pq.pop();
        }
        // 현재 강의의 종료 시간을 우선순위 큐에 삽입
        pq.push(lectures[i].second);
    }
    
    // 우선순위 큐의 크기가 필요한 강의실의 개수
    cout << pq.size() << '\n';
    
    return 0;
}