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
#define fi          first
#define se          second

using namespace std;

const ll mod = 1000000007;
const ll modfeo = 998244353;


// template<
// 	  typename Key,
// 	  typename Mapped,
// 	  typename Cmp_Fn = less<Key>,
// 	  typename Tag = rb_tree_tag,
// 	  template<
// 	  typename Const_Node_Iterator,
// 	  typename Node_Iterator,
// 	  typename Cmp_Fn_,
// 	  typename Allocator_ >
//     class Node_Update = null_node_update,
//     typename Allocator = allocator<char>
// > class tree;
// typedef tree<int,
//     null_type,
//     less<int>,
//     rb_tree_tag,
//     tree_order_statistics_node_update
// > ordered_set;

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
    vector<int> d;
    vector<int> marked;
    vector<int> p;
    vector<int> ciclo;
    int n;
    bool biconnected;

    Graph(int _n, bool _biconnected) {
        n = _n;
        biconnected = _biconnected;
        adj.resize(n);
        d.resize(n, -1);
        ciclo.resize(n);
        // p.resize(n);
        marked.resize(n);
    }

    // void printBfs(int s, map<int, string> itos) {
    //     queue<ll> q;
    //     q.push(s);
    //     marked[s] = true;
    //     p[s] = -1;
    //     d[s] = 0;
    //     while (!q.empty()) {
    //         int v = q.front();
    //         q.pop();
    //         for (int u : adj[v]) {
    //             if (!marked[u]) {
    //                 marked[u] = true;
    //                 q.push(u);
    //                 d[u] = d[v] + 1;
    //                 p[u] = v;
    //             } else {

    //             }
    //         }
    //     }
    // }

    #define INVALID LLONG_MAX

    int dfs(int v, ll ds) {
        if(marked[v] == 2) return ciclo[v];
        int ans = INT_MAX;
        marked[v] = 1;
        d[v] = ds;
        for(auto u : adj[v]) {
            if(marked[u] == 0) {
                ans = min(ans, dfs(u, ds + 1));
            } else if(marked[u] == 1) {
                ans = min(d[v] - d[u] + 1, ans);
                ciclo[u] = ans;
            } else if(marked[u] == 2) {
                // cout << ciclo[u] << " " << u <<  nl;
                ans = ciclo[u];
            }
        }
        marked[v] = 2;
        ciclo[v] = ans;
        // cout << ans << " " << v << nl;
        return ans;
    }

    void resetMarked() {
        marked = vector<int>(n);
    }

    void add(ll v, ll u) {
        adj[v].pb(u);
        if(biconnected) adj[u].pb(v);
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

class Node{
public:
    ll id;
    ll val;

    Node(ll _id, ll _val) {id = _id; val = _val;}
};

#define ALREADY_EXIST 1
#define ADDED_SUCCESFULLY 0
#define INVALID_VALUE -1

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
        if(n > maxVal) return INVALID_VALUE;
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
        if(exist) return ALREADY_EXIST;
        return ADDED_SUCCESFULLY;
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

int nextTrue(vector<bool> v, int i) {
    for(int j = i + 1;j < v.size();j++) {
        if(v[j]) return j;
    }
    return v.size();
}

int nextFalse(vector<bool> v, int i) {
    for(int j = i + 1;j < v.size();j++) {
        if(!v[j]) return j;
    }
    return v.size();
}

int getLastThatIsMe(vector<ll> a, int i){
    int yo = a[i];
    for(int j = i - 1;j >= 0;j--) {
        if(yo == a[j]) return j;
    }
    return -1;
}

int getLastThatIsMe(vector<int> a, int i){
    int yo = a[i];
    for(int j = i - 1;j >= 0;j--) {
        if(yo == a[j]) return j;
    }
    return -1;
}

lll expBin(lll base, lll exp){
    if(exp == -1) return 0;
    if(exp == 0) return 1;
    ll ans = expBin(base, exp / 2);
    ans *= ans;
    if(exp % 2){
        ans*= base;
    }
    return ans;
}

ll expBinMod(ll base, ll exp){
    if(exp == 0) return 1;
    ll ans = expBinMod(base, exp / 2);
    ans *= ans;
    ans %= mod;
    if(exp % 2){
        ans*= base;
        ans%=mod;
    }
    return ans;
}

ll invMod(ll x){
    return expBinMod(x, mod - 2);
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

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);
}

void sol() {
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    vector<vector<int>> d(n, vector<int>(m, -1));
    pair<int, int> exit = {-1, -1};
    for(int i = 0;i < n;i++) {
        cin >> map[i];
        if(exit.fi == -1)
        for(int j = 0;j < m;j++) {
            if(map[i][j] == 'E') exit = {i, j};
        }
    }
    queue<vector<int>> q;
    d[exit.fi][exit.se] = 0;
    q.push({exit.fi, exit.se, 0});
    int x, y;
    while(!q.empty()) {
        auto pos = q.front();
        q.pop();
        x = pos[0] - 1; y = pos[1];
        if(x >= 0 && x < n && y >= 0 && y < m) {
            if(d[x][y] == -1 && map[x][y] == '.') {
                d[x][y] = pos[2] + 1;
                q.push({x, y, pos[2] + 1});
            }
        }
        x = pos[0] + 1; y = pos[1];
        if(x >= 0 && x < n && y >= 0 && y < m) {
            if(d[x][y] == -1 && map[x][y] == '.') {
                d[x][y] = pos[2] + 1;
                q.push({x, y, pos[2] + 1});
            }
        }
        x = pos[0]; y = pos[1] + 1;
        if(x >= 0 && x < n && y >= 0 && y < m) {
            if(d[x][y] == -1 && map[x][y] == '.') {
                d[x][y] = pos[2] + 1;
                q.push({x, y, pos[2] + 1});
            }
        }
        x = pos[0]; y = pos[1] - 1;
        if(x >= 0 && x < n && y >= 0 && y < m) {
            if(d[x][y] == -1 && map[x][y] == '.') {
                d[x][y] = pos[2] + 1;
                q.push({x, y, pos[2] + 1});
            }
        }
    }
    int qrys;
    cin >> qrys;
    while(qrys--) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        if(d[a][b] > 0) {
            char imprimir = 0;
            int dis = INT_MAX;
            x = a - 1; y = b;
            if(x >= 0 && x < n && y >= 0 && y < m) {
                if(d[x][y] >= 0) {
                    if(dis >= d[x][y]) {
                        imprimir = 'U';
                        dis = d[x][y];
                    }
                }
            }
            x = a; y = b + 1;
            if(x >= 0 && x < n && y >= 0 && y < m) {
                if(d[x][y] >= 0) {
                    if(dis >= d[x][y]) {
                        imprimir = 'R';
                        dis = d[x][y];
                    }
                }
            }
            x = a + 1; y = b;
            if(x >= 0 && x < n && y >= 0 && y < m) {
                if(d[x][y] >= 0) {
                    if(dis >= d[x][y]) {
                        imprimir = 'D';
                        dis = d[x][y];
                    }
                }
            }
            x = a; y = b - 1;
            if(x >= 0 && x < n && y >= 0 && y < m) {
                if(d[x][y] >= 0) {
                    if(dis >= d[x][y]) {
                        imprimir = 'L';
                        dis = d[x][y];
                    }
                }
            }
            cout << imprimir;
        } else {
            char c = map[a][b];
            if(c == '#') cout << "W";
            else if(c == '.') cout << "?";
            else if(c == 'X') cout << "X";
            else if(c == 'E') cout << "E";
        }
        cout << nl;
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--) sol();
}