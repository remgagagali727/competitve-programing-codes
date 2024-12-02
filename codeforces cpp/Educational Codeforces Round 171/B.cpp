#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n + 2);
        for(int i =1; i <= n;i++) cin >> a[i];
        a[n + 1] = a[n] + 1;
        a[0] = a[1] - 1;
        n += 2;
        ll ans = LLONG_MAX;
        for(int i = 1;i < n - 1;i++) {
            if(n % 2 == 0) break; 
            if((a[i] - 1 == a[i - 1]) && (a[i] + 1 == a[i + 1])) continue;
            ll tAns = 1;
            ll last = 0;
            bool turn = true;
            for(int j = 1;j < n - 1;j++) {
                if(j == i) continue;
                if(turn) {
                    last = j;
                } else {
                    tAns = max(a[j] - a[last], tAns);
                }
                turn = !turn;
                // cout << tAns << " tans\n"; 
            }
            // if(!turn) 
            // cout << tAns << "end\n";
            ans = min(tAns, ans);
        }
        ll tAns = 1;
        ll last = 0;
        bool turn = !(n % 2);
        for(int j = 1;j < n - 1;j++) {
            if(turn) {
                last = j;
            } else {
                tAns = max(a[j] - a[last], tAns);
            }
            turn = !turn;
        }
        ans = min(tAns, ans);    
        cout << ans << '\n';
    }
}