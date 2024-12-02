#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> time(n);
    for(int i = 0;i < n;i++) {
        cin >> time[i];
        time[i] = 86400 - time[i];
    }
    ll ans = 0;
    ll i = 0;
    while(t > 0) {
        if(i == n) i = 0;
        t -= time[i];
        i++;
        ans++;
    }
    cout << ans << '\n';
}