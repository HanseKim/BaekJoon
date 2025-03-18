#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, k;
    cin >> N >> k;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int comparisons = 0;

    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;

        if (i == k - 1) {
            while (j >= 0) {
                comparisons++;
                if (arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                } else {
                    break;
                }
            }
            arr[j + 1] = key;
            break;
        } else {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    cout << comparisons << "\n";
    return 0;
}
