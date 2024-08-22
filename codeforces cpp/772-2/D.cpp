#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define ull     unsigned long long
#define lll     __int128_t
#define ulll    unsigned __int128_t
#define all(a)  a.begin(),a.end()
#define rall(a)  a.rbegin(),a.rend()
#define swap(a,b) auto t = a; a = b; b = t

using namespace std;

const ll mod = 1000000007;

class Graph{
    private:
    vector<vector<ll>> adj;
    vector<ll> val;
    vector<ll> visited;
    ll n;
    bool biconnected;

    public:

    Graph(ll _n, bool _biconnected) {
        n = _n;
        biconnected = _biconnected;
        adj.resize(n);
        val.resize(n);
        visited.resize(n);
    }

    void add(ll v, ll u) {
        adj[v].pb(u);
        if(!biconnected) adj[u].pb(v);
    }

    void set_val(ll v, ll _val) {
        val[v] = _val;
    }

    ll dfs(ll v) {
        ll ans = 0;
        visited[v] = 1;
        for(auto u : adj[v]) {
            if(visited[u] == 0) {
                ans = max(ans, dfs(u));
            } else if(visited[u] == 1) {
                ans = u;
            }
        }
        visited[v] = 2;
        return ans;
    }
    
    ll dfs_getMinElement(ll v) {
        ll ans = v;
        visited[v] = true;
        for(auto u : adj[v]) {
            if(!visited[u]) {
                ll pos = dfs_getMinElement(u);
                if(val[v] > val[pos]) ans = pos;
            }
        }
        return ans;
    }

    void printDfs(ll v) {
        visited[v] = true;
        for(auto u : adj[v]) {
            if(!visited[u]) {
                printDfs(u);
            }
        }
        cout << v << " ";
    }

    bool isVisited(ll v) {
        return visited[v];
    }

    void resetVisited() {
        for(int i = 0;i < n;i++) visited[i] = false;
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

ll dig(ll n) {
    if(n == 0) return 0;
    return dig(n / 10) + 1;
}

ll countOnes(string s) {
    ll n = s.size();
    ll ans = 0;
    for(int i = 0;i < n;i++) {
        if(s[i] == '1') ans++;
    }
    return ans;
}

ll getLog2(ll x) {
    if(x == 1) return 0;
    else return getLog2(x / 2) + 1;
}

void sol() {
    ll n, p;
    ll ans = 0;
    cin >> n >> p;
    vector<ll> fibboAcum(p + 1);
    fibboAcum[0] = fibboAcum[1] = 1;
    for(int i = 2;i <= p;i++) {
        fibboAcum[i] = fibboAcum[i - 1] + fibboAcum[i - 2];
        fibboAcum[i] %= mod;
    }
    for(int i = 1;i <= p;i++) {
        fibboAcum[i] += fibboAcum[i - 1];
        fibboAcum[i] %= mod;
    }

    set<ll> bases;
    vector<ll> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(all(a));
    for(int i = 0;i < n;i++) {
        ll valor = a[i];
        bool insertar = true;
        while(valor >= 1) {
            auto t = bases.find(valor);
            if(t != bases.end()) {
                insertar = false;
                break;
            }
            if(valor % 2) {
                valor = (valor - 1) / 2;
            } else {
                if(valor % 4) break;
                valor /= 4;
            }
        }
        if(insertar) bases.insert(a[i]);
    }

    for(auto x : bases) {
        ll lg2 = getLog2(x) + 1;
        ll idx = p - lg2;
        if(idx >= 0) ans += fibboAcum[idx];
        ans %= mod;
    }

    cout << ans % mod << nl;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--) sol();
}