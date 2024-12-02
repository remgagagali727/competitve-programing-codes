#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    iostream::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0;i < n;i++) cin >> a[i];
    vector<ll> pf(n + 1);
    for(ll i = 1;i <= n;i++) pf[i] = pf[i - 1] + a[i - 1];
    stack<pair<ll, ll>> s;
    ll ans = 0;
    for(ll i = 0;i < n;i++) {
        if(!s.empty())
            while(s.top().first < a[i]) {
                s.pop();
                if(s.empty()) break;
            }
        if(!s.empty()) {
            auto x = s.top();
            ans = max(ans,((i - x.second - 1) * a[i]) - (pf[i] - pf[x.second + 1]));
        }
        if(!s.empty()) if(s.top().first == a[i]) s.pop();
        s.push({a[i], i});
    }
    s = stack<pair<ll, ll>>();
    for(ll i = n - 1;i >= 0;i--) {
        if(!s.empty())
            while(s.top().first < a[i]) {
                s.pop();
                if(s.empty()) break;
            }
        if(!s.empty()) {
            auto x = s.top();
            ans = max(ans,((x.second - i - 1) * a[i]) - (pf[x.second] - pf[i + 1]));
        }
        if(!s.empty()) if(s.top().first == a[i]) s.pop();
        s.push({a[i], i});
    }
    cout << ans << '\n';
}