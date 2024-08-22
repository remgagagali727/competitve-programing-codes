#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define ull     unsigned long long
#define lll     __int128_t
#define ulll    unsigned __int128_t
#define all(a)  a.begin(),a.end()

using namespace std;

class Hash{
private:
    const ll BASE = 71;
    const ll MOD = 1e9 + 1e5 + 1;

    void init() {
        b[0] = 1;
        for (int i = 1; i < n; i++)
            b[i] = (b[i-1] * BASE) % MOD;

        for (int i = 0; i < n; i++)
            h[i+1] = (h[i] + (s[i] - 'a' + 1) * b[i]) % MOD;
    }

public:
    vector<ll> b;
    vector<ll> h;
    int n;
    string s;


    Hash(int _n, string _s) {
        s = _s;
        n = _n;
        h.resize(n + 1, 0);
        b.resize(2 * n + 1);
        init();
    }

    ll check_hash(int l, int r) {
        return (((h[r] + MOD - h[l]) % MOD) * b[n - l - 1]) % MOD;
    }
};

ll dig(ll n) {
    if(n == 0) return 0;
    return dig(n / 10) + 1;
}

void sol() {

    vector<pair<ll, ll>> ans;
    ll n;
    ll nc = 0;

    cin >> n;
    ll base = pow(10,dig(n));
    ll dign = dig(n);
    while(nc < 10e9) {
        nc = nc * base + n;
    }
    while(nc > 10e6) {
        nc /= 10;
    }

    ll pw = 10000000;
    ll b;

    for(int i = 1;i < 8;i++) {
        ll res = nc / pw;
        ll digres = dig(res);
        for(int a = n;a <= 10e4;a+=n) {
            b = a - res;
            if(a == b) break;
            if(b <= 0) continue;
            if(a / n * dign - b == digres) {
                if(a / n > 10000) continue;
                ans.pb({a / n,b});
            }
        }
        pw /= 10;
    }

    cout << ans.size() << nl;

    for (const auto& p : ans) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) sol();
}
