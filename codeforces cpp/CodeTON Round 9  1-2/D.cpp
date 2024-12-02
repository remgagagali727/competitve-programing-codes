#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for(int i = 0;i < m;i++) cin >> a[i];
        sort(a.rbegin(), a.rend());
        vector<int> crib(n + 1);
        crib[0] = crib[1] = 1;
        for(ll i = 2;i <= n;i++) {
            if(crib[i] == 0) {
                crib[i] = 1;
                for(ll j = i * i;j <= n;j += i) {
                    if(crib[j] == 0) crib[j] = i;
                }
            }
        }
        vector<int> ans(n + 1);
        bool imposible = false;
        ans[1] = a[0];
        for(int i = 2;i <= n;i++) {
            if(crib[i] == 1) {
                if(1 == m) {
                    imposible = true;
                    break;
                }
                crib[i] = 1;
                ans[i] = a[1];
            } else {
                int id = crib[i / crib[i]] + 1;
                if(id == m) {
                    imposible = true;
                    break;
                }
                crib[i] = id;
                ans[i] = a[id];
            }
        }
        if(imposible) {
            cout << "-1\n";
        } else {
            for(int i = 1;i <= n;i++) {
                cout << ans[i] << " ";
            }
            cout << '\n';
        }
    }
}