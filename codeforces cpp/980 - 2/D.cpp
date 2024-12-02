#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

void caso() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for(ll i = 0;i < n;i++) cin >> a[i].first;
    for(ll i = 0;i < n;i++) {
        cin >> a[i].second;
        a[i].second--;
    }
    vector<ll> costo(n, LLONG_MAX);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    costo[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()) {
        ll l = pq.top().first;
        ll idx = pq.top().second;
        pq.pop();

        if(costo[idx] != l) continue;

        if(idx != 0) {
            if(costo[idx - 1] > l) {
                costo[idx - 1] = l;
                pq.push({l, idx - 1});
            }
        }
        if(costo[a[idx].second] > a[idx].first + l) {
            ll dis = a[idx].first + l;
            costo[a[idx].second] = dis;
            pq.push({dis, a[idx].second});
        }
    }
    ll acum = 0;
    ll ans = 0;
    for(ll i = 0;i < n;i++) {
        acum += a[i].first;
        if(costo[i] == LLONG_MAX) continue;
        ans = max(ans, acum - costo[i]);
    }
    cout << ans << "\n";
}

int main() {
    ll t; cin >> t; while(t--) caso();
}