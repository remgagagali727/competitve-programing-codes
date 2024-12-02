#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> freq(n + 1);
        int ans = 0;
        for(int i = 0;i < n;i++) {
            int a; cin >> a;
            ans -= freq[a]++ / 2;
            ans += freq[a] / 2;
        }
        cout << ans << "\n";
    }
}