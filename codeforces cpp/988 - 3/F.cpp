#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int k, n, m;
        cin >> n >> m >> k;
        vector<ll> h(n), x(n);
        for(int i = 0;i < n;i++) cin >> h[i]; 
        for(int i = 0;i < n;i++) cin >> x[i];
        int l = 0, r = 1e9 + 1;
        while(l + 1 < r) {
            vector<pair<int, int>> even;
            ll atac = (l + r) / 2;
            for(int i = 0;i < n;i++) {
                if(h[i] > atac * m) continue;
                ll ld = 0, rd = m + 1;
                while(ld + 1 < rd) {
                    ll md = (ld + rd) / 2;
                    if((h[i] + md - 1) / md > atac) {
                        ld = md;
                    } else {
                        rd = md;
                    }
                }
                ll dif = m - rd;
                even.push_back({x[i] + dif + 1, -1});   
                even.push_back({x[i] - dif, 1});   
            }
            sort(even.begin(), even.end());
            int score = 0;
            int tscore = 0;
            for(int i = 0;i < even.size();i++) {
                tscore += even[i].second;
                score = max(score, tscore);
            }
            if(score < k) {
                l = atac;
            } else {
                r = atac;
            }
        }
        if(r > 1e9) {
            cout << -1;
        } else {
            cout << r;
        }
        cout << '\n';
    }
}