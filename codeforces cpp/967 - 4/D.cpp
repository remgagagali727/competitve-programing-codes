#include <bits/stdc++.h>

using namespace std;

struct nde{
    int M, m;
    nde() {
        M = 0;
        m = INT_MAX;
    }
};

int n;
vector<nde> t;

void update(int k, nde v, int l = 0, int r = n - 1, int node = 0) {
    if(l == r) {
        t[node] = t[node] = v;
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) {
        update(k, v, l, m, node * 2 + 1);
    } else {
        update(k, v, m + 1, r, node * 2 + 2);
    }
    t[node].M = max(t[node * 2 + 1].M, t[node * 2 + 2].M);
    t[node].m = min(t[node * 2 + 1].m, t[node * 2 + 2].m);
}

nde query(int lq, int rq, int l = 0, int r = n - 1, int node = 0) {
    if(r < lq || l > rq) {
        return nde();
    }
    if(l >= lq && r <= rq) return t[node];
    int m = (l + r) / 2;
    auto lf = query(lq, rq, l, m, node * 2 + 1);
    auto rg = query(lq, rq, m + 1, r, node * 2 + 2);
    nde toRet;
    toRet.M = max(lf.M, rg.M);
    toRet.m = min(lf.m, rg.m);
    return toRet;
}

int main() {
    int k; cin >> k;
    while(k--) {
        cin >> n;
        vector<int> a(n);
        vector<int> freq(n + 1);
        t = vector<nde>(4 * n);
        for(int i = 0;i < n;i++) {
            cin >> a[i];
            nde ndd;
            ndd.M = ndd.m = a[i];
            update(i, ndd);
            freq[a[i]]++;
        }
        vector<int> ans;
        bool turno = true;
        int last = 0;
        nde ndd;
        ndd.M = 0;
        ndd.m = INT_MAX;
        for(int i = 0;i < n;i++) {
            freq[a[i]]--;
            if(freq[a[i]] < 0) {
                update(i, ndd);
            } else if(freq[a[i]] == 0) {
                auto x = query(last, i);
                last = i + 1;
                if(turno) {
                    ans.push_back(x.M);
                } else {
                    ans.push_back(x.m);
                }
                turno = !turno;
                freq[ans[ans.size() - 1]] = -1;
                if(ans[ans.size() - 1] != a[i]) {
                    ans.push_back(a[i]);
                    freq[ans[ans.size() - 1]] = -1;
                    turno = !turno;
                }
                update(i, ndd);
            }
        }
        cout << ans.size() << '\n';
        for(auto x : ans) cout << x << ' ';
        cout << '\n';
    }
}