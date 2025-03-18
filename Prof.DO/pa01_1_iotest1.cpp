#include <iostream>
#include <vector>
using namespace std;

vector<int> v(10001,10001);
int insertion(int n,int k) {
    int cnt = 0;
    for (int i=1;i<n;i++) {
        int key=v[i],j=i-1;
        if (i==k) {
            while (j>=0) {
                cnt++;
                if (v[j] <= key) break;
                v[j + 1] = v[j];
                j--;
            }
        }
        else{
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                j--;
            }
        }
        v[j + 1] = key;
    }
    return cnt;
}

int main() {
    int n, k; cin>>n>>k;
    for (int i = 0; i < n; i++) cin >> v[i];
    int result = insertion(n, k-1);
    cout<<result;

    // int cnt=0;
    // for(int i=0;i<k;i++) if(v[k-1] < v[i]) cnt++;
    // cout<<cnt;
    return 0;
}