#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define ull     unsigned long long
#define lll     __int128_t
#define ulll    unsigned __int128_t
#define all(a)  a.begin(),a.end()

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
        // cout << ans << " " << v << " ANS EN V val " << nl;
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
    ll n;
    cin >> n;
    Graph g(n + 2);
    for(int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        g.set_val(i,a);
    }
    for(int i = 2;i <= n;i++) {
        int a;
        cin >> a;
        g.add(a,i);
    }
    cout << g.dfs_winner(1,0) << nl;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--) sol();
}