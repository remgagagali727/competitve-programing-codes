#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = 0;i < n;i++) {
        ll a; cin >> a;
        pq.push(a);
    }
    ll ans = 0;
    while(pq.size() > 1) {
        if(pq.size() % 2 == 0) {
            pq.push(0);
        }
        ll tAns = 0;
        for(int i = 0;i < 3;i++) {
            tAns += pq.top(); pq.pop();
        }
        ans += tAns;
        pq.push(tAns);
    }
    cout << ans << '\n';
}