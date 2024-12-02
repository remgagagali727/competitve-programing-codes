#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int mod = 998244353;
const int maxa = 1e6;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n);
    dp[0] = 1;
    for(int i = 0;i < n;i++) cin >> a[i];
    map<int, int> c;
    vector<int> crib(maxa + 1);
    crib[0] = crib[1] = 1;
    for(ll i = 2;i <= maxa;i++) {
        if(crib[i] == 0) {
            crib[i] = i;
            for(ll j = i * i;j <= maxa;j+=i) {
                if(crib[j] == 0) crib[j] = i;
            }
        }
    }
    reverse(a.begin(), a.end());
    vector<int> prims;
    int x = a[0];
    int last = -1;
    while(x > 1) {
        if(crib[x] != last) {
            prims.push_back(last = crib[x]);
        }
        x /= crib[x];
    }
    int comb = 1 << prims.size();
    for(int i = 1;i < comb;i++) {
        int idx = 0;
        ll v = 1;
        for(;(1 << idx) <= i;idx++) {
            if((1 << idx) & i) {
                v *= (prims[idx]);
            }
        }
        c[v]++;
    }
    for(int it = 1;it < n;it++) {
        prims = vector<int>();
        x = a[it];
        last = -1;
        while(x > 1) {
            if(crib[x] != last) {
                prims.push_back(last = crib[x]);
            }
            x /= crib[x];
        }
        comb = 1 << prims.size();
        for(int i = 1;i < comb;i++) {
            int idx = 0;
            ll v = 1;
            int am = 0;
            for(;(1 << idx) <= i;idx++) {
                if((1 << idx) & i) {
                    v *= (prims[idx]);
                    am++;
                }
            }
            if(am % 2) {
                dp[it] += c[v];
            } else {
                dp[it] += mod - c[v];
            }
            dp[it] %= mod;
        }
        for(int i = 1;i < comb;i++) {
            int idx = 0;
            ll v = 1;
            for(;(1 << idx) <= i;idx++) {
                if((1 << idx) & i) {
                    v *= (prims[idx]);
                }
            }
            c[v] += dp[it];
            c[v] %= mod;
        }
    }
    cout << dp[n - 1] << '\n';
}