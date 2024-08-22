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

ll calculateBridgeCost(ll m, ll d) {
    vector<ll> bridge(m);
    multiset<ll> dp;
    for(int i = 0;i < m;i++) {
        cin >> bridge[i];
        bridge[i]++;
    }
    dp.insert(bridge[0]);
    for(int i = 1;i < m;i++) {
        ll acum = bridge[i];
        acum += *dp.begin();
        dp.insert(acum);
        if(i > d) { dp.erase(dp.find(bridge[i - d - 1])); }
        bridge[i] = acum;
    }
    return bridge[m - 1];
}

void sol() {
    ll n, m, k, d;
    ll ans = 0;
    ll acum = 0;
    cin >> n >> m >> k >> d;
    vector<ll> bridgeCost(n);
    for(int i = 0;i < n;i++) {
        bridgeCost[i] = calculateBridgeCost(m, d);
    }
    for(int i = 0;i < k;i++) {
        acum += bridgeCost[i];
    }
    ans = acum;
    for(int i = k;i < n;i++) {
        acum -= bridgeCost[i - k];
        acum += bridgeCost[i];
        ans = min(ans, acum);
    }
    cout << ans << nl;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--) sol();
}