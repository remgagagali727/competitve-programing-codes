#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> t;

void update(int k, int v, int l, int r, int nodo) {
    if(l == r) t[nodo] = v;
    else {
        int m = (l + r) / 2;
        if(k <= m) update(k, v, l, m, nodo * 2 + 1);
        else update(k, v, m + 1, r, nodo * 2 + 2);
        t[nodo] = min(t[nodo * 2 + 1], t[nodo * 2 + 2]);
    }
}

int qry(int l, int r, int ql, int qr, int nodo) {
    if(ql > r || l > qr) return INT_MAX;
    if(ql <= l && r <= qr) return t[nodo];
    int m = (l + r) / 2;
    return min(qry(l, m, ql, qr, nodo * 2 + 1), qry(m + 1, r, ql, qr, nodo * 2 + 2));
}

int main() {
    int n, q;
    cin >> n >> q;
    t.resize(n * 4);
    for(int i = 0;i < n;i++) {
        int ai; cin >> ai;
        update(i, ai, 0, n - 1, 0);
    }
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int k, v;
            cin >> k >> v;
            k--;
            update(k, v, 0, n - 1, 0);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << qry(0, n-  1, l, r, 0) << '\n';
        }
    }
}