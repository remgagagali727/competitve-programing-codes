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

#define valSlot 0
#define totalCostSlot 1
#define tamSlot 2
#define parentSlot 3
#define realCostSlot 4

using namespace std;

const ll mod = 1000000007;

class Graph{
    private:
    vector<vector<ll>> adj;
    vector<vector<ll>> val;
    ll n;
    bool biconnected;

    public:

    Graph(ll _n, bool _biconnected) {
        n = _n;
        biconnected = _biconnected;
        adj.resize(n);
        val.resize(n, vector<ll>(4));
        val[0][0] = val[0][1] = val[0][2] = val[0][3] = val[0][4] = 0;
    }

    void adjust() {
        val[0][valSlot] = val[1][valSlot];
    }

    void add(ll v, ll u) {
        adj[v].pb(u);
        if(!biconnected) adj[u].pb(v);
    }

    void set_val(ll v, ll _val) {
        val[v][valSlot] = _val;
    }

    ll getTam(ll v, ll p) {
        ll t = 1;
        for(auto u : adj[v]) {
            if(u == p) continue;
            t += getTam(u, v);
        }
        val[v][tamSlot] = t;
        val[v][parentSlot] = p;
        return t;
    }
    
    ll getCost(ll v, ll p) {
        ll cost;
        cost = val[v][tamSlot] * (val[v][valSlot] ^ val[p][valSlot]);
        for(auto u : adj[v]) {
            if(u == p) continue;
            cost += getCost(u, v);
        }
        val[v][totalCostSlot] = cost;
        return cost;
    }

    ll getNodeAsRootCost(ll v) {
        return val[v][realCostSlot];
    }

    ll getCost(ll v) {
        return val[v][totalCostSlot];
    }

    void realCost(ll v, ll p, ll acumCost) {
        ll totalCost = 0;
        for(auto u : adj[v]) {
            if(p != u) {
                totalCost += val[u][totalCostSlot];
            } else {
                totalCost += acumCost - val[v][totalCostSlot] + (val[p][valSlot] ^ val[v][valSlot]) * (n - 1 - val[v][tamSlot]);
            }
        }
        for(auto u : adj[v]) {
            if(p != u) {
                realCost(u, v, totalCost);
            }
        }
        val[v][realCostSlot] = totalCost;
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
    ll n;
    cin >> n;
    Graph graph(n + 1, false);
    for(int i = 1;i <= n;i++) {
        ll h;
        cin >> h;
        graph.set_val(i, h);
    }
    for(int i = 1;i < n;i++) {
        ll u, v;
        cin >> u >> v;
        graph.add(u, v);
    }
    graph.adjust();
    graph.getTam(1, 0);
    graph.getCost(1, 0);
    graph.realCost(1, 0, graph.getCost(1));
    for(int i = 1;i <= n;i++) {
        cout << graph.getNodeAsRootCost(i) << " ";
    }
    cout << nl;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--) sol();
}