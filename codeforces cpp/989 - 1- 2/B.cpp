#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        int ans = 0;
        int last = 0;
        int left = 0;
        for(int i = 0;i < n;i++) {
            if(left > 0) {
                left--;
                continue;
            }
            if(s[i] == '1') {
                last = 0;
            } else {
                last++;
            }
            if(last >= m) {
                ans++;
                left = k - 1;
                last = 0;
            }
        }
        cout << ans << '\n';
    }
}