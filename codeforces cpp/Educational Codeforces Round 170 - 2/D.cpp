#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define nl          "\n"
#define pb          push_back
#define ll          long long
#define ull         unsigned long long
#define ld          long double
#define uld         unsigned long double
#define lll         __int128_t
#define ulll        unsigned __int128_t
#define all(a)      a.begin(),a.end()
#define rall(a)     a.rbegin(),a.rend()
#define swap(a,b)   auto t = a; a = b; b = t
#define tswap(a,b)  t = a; a = b; b = t
#define ullinf      LONG_LONG_MAX
#define INF         INT_MAX
#define in(x,a,b)   x > a && x < b
#define unqueue(a)  a.front(); a.pop();
#define unstack(a)  a.top(); a.pop();

using namespace std;
using namespace __gnu_pbds;

const ll mod = 1000000007;

using TV = pair<int, int>;

typedef tree<TV,
    null_type,
    less<TV>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.resize(n);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int qrry(int l, int r){
        if(l == 0) return qrry(r);
        return qrry(r) - qrry(l - 1);
    }

    int qrry(int r) {
        ll ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ans = ans + bit[r];
        return ans;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += val;
    }
};  

class Flow{
    public:
    int n;
    vector<vector<int>> capacity;
    vector<vector<int>> adj;

    Flow(int _n) {
        n = _n;
        capacity.resize(n, vector<int>(n));
        adj.resize(n);
    }

    void add(int v, int u, int cap) {
        adj[v].pb(u);
        capacity[v][u] += cap;
        capacity[u][v] += cap;
    }

    int bfs(int s, int t, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, INF});

        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int next : adj[cur]) {
                if (parent[next] == -1 && capacity[cur][next]) {
                    parent[next] = cur;
                    int new_flow = min(flow, capacity[cur][next]);
                    if (next == t)
                        return new_flow;
                    q.push({next, new_flow});
                }
            }
        }

        return 0;
    }

    int maxflow(int s, int t) {
        int flow = 0;
        vector<int> parent(n);
        int new_flow;

        while (new_flow = bfs(s, t, parent)) {
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prev = parent[cur];
                capacity[prev][cur] -= new_flow;
                capacity[cur][prev] += new_flow;
                cur = prev;
            }
        }

        return flow;
    }
};

class DSU{
public:
    int n = 500010;
    vector<int> id = vector<int>(n);
    vector<int> parent = vector<int>(n);

    DSU(int _n) {
        n = _n;
        parent.resize(n);
        id.resize(n);
    }

    DSU() { }


    void make_set(ll v) {
        parent[v] = v;
        id[v] = v;
    }

    ll find_set(ll v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    int find_set_no_modification(int v) {
        if (v == parent[v]) return v;
        return find_set_no_modification(parent[v]);
    }

    int find_set_id(int v) {
        if (v == id[v]) return v;
        return id[v] = find_set_id(id[v]);
    }

    void union_sets(int replace, int replaced) {
        // int b = find_set(replaced);
        id[replace] = id[replaced];
        // parent[replace] = replaced;
    }
};

class Graph{
    public:
    vector<vector<int>> adj;
    vector<int> valores;
    vector<vector<vector<int>>> qrry;
    vector<string> ans;
    vector<bool> visited;
    int n;
    bool biconnected;

    Graph(int _n, bool _biconnected) {
        n = _n;
        biconnected = _biconnected;
        adj.resize(n);
        qrry.resize(n);
        valores.resize(n);
        visited.resize(n);
    }

    void setValor(int nV, int oV) {
        valores[oV] = nV;
    }

    void addQuerry(int v, vector<int> x){
        qrry[v].pb(x);
    }

    set<int> dfs(int v) {
        set<int> defaultSet;
        defaultSet.insert(valores[v]);
        visited[v] = true;
        for(auto u : adj[v]) {
            if(visited[u]) continue;
            auto childSet = dfs(u);
            if(childSet.size() > defaultSet.size()) {
                childSet.insert(all(defaultSet));
                defaultSet = move(childSet);
            } else {
                defaultSet.insert(all(childSet));
            }
        }
        for(auto x : qrry[v]) {
            int l = x[1], r = x[2] + 1;
            auto lp = defaultSet.lower_bound(l);
            auto rp = defaultSet.lower_bound(r);
            if(lp == rp) {
                ans[x[0]] = "NO";
            } else {
                ans[x[0]] = "YES";
            }
        }
        return defaultSet;
    }

    void add(ll v, ll u) {
        adj[v].pb(u);
        if(biconnected) adj[u].pb(v);
    }

    void resizeQuerry(int q) {
        ans.resize(q);
    }

};

class Hash{
private:
    const ll BASE = 71;
    const ll MOD = 1e9 + 1e5 + 1989;

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
        h.resize(n + 1);
        b.resize(n);
        init();
    }

    ll check_hash(int l, int r) {
        return (((h[r + 1] + MOD - h[l]) % MOD) * b[n - 1 - l]) % MOD;
    }
};

class Node{
public:
    ll id;
    ll val;

    Node(ll _id, ll _val) {id = _id; val = _val;}
};

class Trie{
    public:
    ll k;
    ll maxVal;
    vector<vector<Node>> adj;
    vector<ll> values;

    Trie(ll _k) {
        k = _k;
        adj.resize(1);
        values.resize(k + 1);
        values[0] = 1;
        for(int i = 1;i <= k ;i++) values[i] = 2 * values[i - 1];
        maxVal = values[k] - 1;
    }

    Node searchNode(ll pId, ll nVal) {
        for(int i = 0;i < adj[pId].size();i++) {
            if(adj[pId][i].val == nVal) return adj[pId][i];
        }
        return Node(-1, -1);
    }

    Node createNode(ll pId, ll nVal) {
        ll nId = adj.size();
        Node n(nId, nVal);
        adj[pId].pb(n);
        adj.resize(nId + 1);
        return n;
    }

    ll insert(ll n){
        if(n > maxVal) return 0;
        ll curNode = 0;
        bool exist = true;
        for(int i = k - 1;i >= 0;i--) {
            ll val = values[i];
            ll nodeVal = val & n;
            Node n = searchNode(curNode, nodeVal);
            if(n.id == -1) {
                n = createNode(curNode, nodeVal);
                exist = false;
            }
            curNode = n.id;
        }
        if(exist) return 1;
        return 2;
    }

    pair<int, int> getMinXor() {
        return getMinXor(0, 0);
    }

    pair<int, int> getMinXor(ll acum, ll nId) {
        pair<int, int> ans;
        acum << 1;
        if(adj[nId].size() == 0) return {acum, acum};
        else if(adj[nId].size() == 1) {
            return getMinXor(acum + adj[nId][0].val, adj[nId][0].id);
        } else {
            auto x1 = getMinXor(acum + adj[nId][0].val, adj[nId][0].id);
            auto x2 = getMinXor(acum + adj[nId][1].val, adj[nId][1].id);
            if(x1.first == x1.second && x2.second == x2.first) {
                return {x1.first, x2.first};
            } else if(x1.first == x1.second) {
                return x2;
            } else if(x2.first == x2.second) {
                return x1;
            } else {
                if(x1.first ^ x1.second < x2.first ^ x2.second) {
                    return x1;
                } else {
                    return x2;
                }
            }
        }
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
    if(x <= 1) return 0;
    else return getLog2(x / 2) + 1;
}

ll expBin(ll base, ll exp){
    if(exp == 0) return 1;
    ll ans = expBin(base, exp / 2);
    ans *= ans;
    ans %= mod;
    if(exp & 1){
        ans *= base;
        ans %= mod;
    }
    return ans;
}

ll invMod(ll x){
    return expBin(x, mod - 2);
}

template <typename T>
vector<vector<T>> multMatrix(vector<vector<T>> a, vector<vector<T>> b) {
    int n = a.size();
    int m = a[0].size();
    int o = b[0].size();
    vector<vector<T>> ans(n, vector<T>(o));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < o;j++) {
            T acum = 0;
            for(int k = 0;k < m;k++) {
                acum += a[i][k] * b[k][j];
                acum %= mod;
            }
            ans[i][j] = acum;
        }
    }
    return ans;
}

template <typename T>
vector<vector<T>> expBinM(vector<vector<T>> m, int n) {
    if(n == 1) return m; 
    auto nm = expBinM(m, n / 2);
    nm = multMatrix(nm, nm);
    if(n & 1) {
        nm = multMatrix(nm, m);
    }
    return nm;
}

istream& operator>>(istream& in, __int128& num) {
    string input;
    in >> input;

    num = 0;
    bool is_negative = false;
    size_t start = 0;

    if (input[0] == '-') {
        is_negative = true;
        start = 1;
    }

    for (size_t i = start; i < input.size(); ++i) {
        num = num * 10 + (input[i] - '0');
    }

    if (is_negative) {
        num = -num;
    }

    return in;
}

bool qry(int u, int v) {
    cout << "? " << u << " " << v << nl;
    cout.flush();
    bool b;
    cin >> b;
    return b;
}

void sol() {
    int n, m;
    cin >> n >> m;
    ordered_set dpi;
    ordered_set dps;
    int points = 0;
    ll ans = 0;
    for(int i = 0;i < n;i++) {
        int a; cin >> a;
        if(a == 0) {
            points++;
        } else 
        if(a < 0) {
            a = -a;
            if(a > points) continue;
            dpi.insert({a, i});
            ll x = dpi.order_of_key({a, n});
            ll y = dps.order_of_key({points - a, n});
            ans = max(ans, x + y);
        } else {
            if(a > points) continue;
            dps.insert({a, i});
            ll x = dps.order_of_key({a, n});
            ll y = dpi.order_of_key({points - a, n});
            ans = max(ans, x + y);
        }
    }
    cout << ans << nl;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--) sol();
}