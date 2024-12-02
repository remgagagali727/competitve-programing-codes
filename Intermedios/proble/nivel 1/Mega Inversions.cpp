#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pii = pair<int, int>;
vector<ll> t;


void update(int l, int r, int k, int v, int nodo) {
    if(l == r) t[nodo] = v;
    else {
        int m = (l + r) / 2;
        if(k <= m) update(l, m, k, v, nodo * 2 + 1);
        else update(m + 1, r, k, v, nodo * 2 + 2);
        t[nodo] = t[nodo * 2 + 1] + t[nodo * 2 + 2];
    }
}

ll query(int l, int r, int lt, int rt, int nodo) {
    if(r < lt || l > rt) return 0;
    if(l <= lt && rt <= r) return t[nodo];
    int m = (lt + rt) / 2;
    return query(l, r, lt, m, nodo * 2 + 1) + query(l, r, m + 1, rt, nodo * 2 + 2);
}



int main() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<ll> valores(n, 1);
    valores[0] = valores[n - 1] = 0;
    t = vector<ll>(4 * n);
    for(int i = 0;i < n;i++) {
        if(a[i].second < n - 1) valores[a[i].second] *= query(a[i].second + 1, n - 1, 0, n - 1, 0);
        update(0, n - 1, a[i].second, 1, 0);
    }
    t = vector<ll>(4 * n);
    for(int i = n - 1;i >= 0;i--) {
        if(a[i].second > 0) valores[a[i].second] *= query(0, a[i].second - 1, 0, n - 1, 0);
        update(0, n - 1, a[i].second, 1, 0);
    }
    ll ans = 0;
    for(auto x : valores) {
        ans += x;
    }
    cout << ans << '\n';
}