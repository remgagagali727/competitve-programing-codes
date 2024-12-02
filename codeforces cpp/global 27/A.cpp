#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, m, r, c;
        cin >> n >> m >> r >> c;
        ll times = n - r;
        ll ans = times * (m - 1) + m - c;
        ans += times * m;
        cout << ans << '\n';
    }
}