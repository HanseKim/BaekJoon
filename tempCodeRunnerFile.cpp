#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, cnt = 1;
    cin >> n;
    while (n != 0) {
        vector<string> name(n);
        vector<vector<int>> nasty(n);

        for (int i = 0; i < n; i++) {
            cin >> name[i];
            for (int j = 0; j < n-1; j++) {
                string str;

                cin >> str;
                if (str == "N") {
                    nasty[i].push_back((n-1 - j + i)%n); // i가 j에게 "Nasty" 발언
                }
                cout<<((n-j+i)%n)<<" ";
            }
        }
        if(cnt!=1)cout<<"\n";
        cout << "Group " << cnt << "\n";
        bool hasNasty = false;
        for (int i = 0; i < n; i++) {
            if (!nasty[i].empty()) {
                hasNasty = true;
                for (int j : nasty[i]) {
                    cout << name[j] << " was nasty about "<< name[i] << "\n";
                    //cout<<"i: "<<i<<" j; "<<j<<'\n';
                }
            }
        }
        if (!hasNasty) {
            cout << "Nobody was nasty\n";
        }
        
        cin >> n;
        cnt++;
    }

    return 0;
}
