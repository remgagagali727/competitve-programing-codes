#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define ull     unsigned long long
#define lll     __int128_t
#define ulll    unsigned __int128_t
#define all(a)  a.begin(),a.end()
#define swap(a,b) auto t = a; a = b; b = t

using namespace std;

class Graph{
    private:
    vector<vector<ll>> adj;
    vector<ll> val;
    ll n;

    public:

    Graph(ll _n) {
        n = _n;
        adj.resize(n);
        val.resize(n);
    }

    void add(ll v, ll u) {
        adj[v].pb(u);
        adj[u].pb(v);
    }

    void set_val(ll v, ll _val) {
        val[v] = _val;
    }

    ll dfs_winner(ll v, ll f) {
        ll ans = val[v];
        ll extra = LONG_LONG_MAX;
        for(auto u : adj[v]) {
            if(u != f) {
                extra = min(extra, dfs_winner(u, v));
            }
        }
        if(v == 1) {
            ans += extra;
        } else if(adj[v].size() != 1) {
            ans = min(extra, (ans + extra) / 2);
        }
        return ans;
    }
};

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

/*
Counts the digits of a number
*/
ll dig(ll n) {
    if(n == 0) return 0;
    return dig(n / 10) + 1;
}

void sol() {

    ll x, n;
    ll xi;
    ll DownUsed = 0;
    cin >> n >> x;
    vector<ll> a(n);

    for(int i = 0;i < n;i++) {
        cin >> a[i];
        if(a[i] == x) xi = i;
    }

    ll l = 0, r = n;
    while(l + 1 < r) {
        ll m = (l + r) / 2;
        if(a[m] <= x) {
            DownUsed++;
            l = m;
        } else {
            r = m;
        }
    }
    if(x == a[l]) cout << "0" << nl;
    else {
        if(DownUsed == x) {
            swap(a[0],a[n/2]);
            if(xi == n/2) {
                xi = 0;
            }
            ll l = 0, r = n;
            while(l + 1 < r) {
                ll m = (l + r) / 2;
                if(a[m] <= x) {
                    DownUsed++;
                    l = m;
                } else {
                    r = m;
                }
            }
            if(xi == l) {
                cout << "1" << nl;
                cout << "1 " << n/2 + 1 << nl;
            } else {
                cout << "2" << nl;
                cout << "1 " << n/2 + 1 << nl;
                cout << (xi + 1) << " " << l + 1 << nl; 
            }
        } else {
            cout << "1" << nl;
            cout << (xi + 1) << " " << l + 1 << nl; 
        }
    }

}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--) sol();
}