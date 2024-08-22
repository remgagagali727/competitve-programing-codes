#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define nl          "\n"
#define pb          push_back
#define ll          long long
#define ull         unsigned long long
#define lll         __int128_t
#define ulll        unsigned __int128_t
#define all(a)      a.begin(),a.end()
#define rall(a)     a.rbegin(),a.rend()
#define swap(a,b)   auto t = a; a = b; b = t
#define ullinf       LONG_LONG_MAX

using namespace std;

const ll mod = 1000000007;


// template<
// 	  typename Key,
// 	  typename Mapped,
// 	  typename Cmp_Fn = std::less<Key>,
// 	  typename Tag = rb_tree_tag,
// 	  template<
// 	  typename Const_Node_Iterator,
// 	  typename Node_Iterator,
// 	  typename Cmp_Fn_,
// 	  typename Allocator_>
//     class Node_Update = null_node_update,
//     typename Allocator = std::allocator<char>
// >
// class tree;
// typedef tree<int,
//     null_type,
//     less<int>,
//     rb_tree_tag,
//     tree_order_statistics_node_update
// > ordered_set;

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
    vector<vector<ll>> adj;
    vector<ll> d;
    vector<bool> marked;
    vector<ll> p;
    ll n;
    bool biconnected;

    Graph(ll _n, bool _biconnected) {
        n = _n;
        biconnected = _biconnected;
        adj.resize(n);
        d.resize(n, -1);
        p.resize(n);
        marked.resize(n);
    }

    void cleanMarked() {
        marked = vector<bool>(n);
    }

    int getDistance(int v) {
        return d[v];
    }

    int getParent(int v) {
        return p[v];
    }

    void printDfs(int v) {
        marked[v] = true;
        for(auto u : adj[v]) {
            if(!marked[u]) {
                cout << v << " " << u << " ";
                printDfs(u);
            }
        }
    }

    bool askDfs(int v, Graph& b) {
        bool redo = false;
        marked[v] = true;
        int p;
        for(auto u : adj[v]) {
            if(!marked[u]) {
                cout.flush();
                cout << "? " << v << " " << u << nl;
                cout.flush();
                cin >> p;
                if(p == -1) exit(1);
                cout.flush();
                if(p != v) redo = true;
                b.add(p, u);
                b.add(v, p);
                redo = askDfs(u, b) || redo;
            }
        }
        return redo;
    }

    string printBfs(int s, map<int, string> itos) {
        string ans = "";
        queue<ll> q;
        q.push(s);
        marked[s] = true;
        p[s] = -1;
        d[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            cout << itos[v] << nl;
            ans.append("1");
            q.pop();
            for (int u : adj[v]) {
                if (!marked[u]) {
                    marked[u] = true;
                    ans.append("0");
                    q.push(u);
                    d[u] = d[v] + 1;
                    p[u] = v;
                }
            }
        }
        return ans;
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

ll expBin(ll base, ll exp){
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

int mejor(int i, int j, vector<int> a, int tam) {
    i -= tam;
    j -= tam;
    for(int k = 0;k < tam;k++) {
        if(a[k + i] == a[k + j]) continue;
        if(k & 1) {
            if(a[k + i] < a[k + j]) {
                return i + tam;
            }
            return j + tam;
        } else {
            if(a[k + i] < a[k + j]) {
                return j + tam;
            }
            return i + tam;
        }
    }
    return i + tam;
}

void sol() {
    int n;
    cin >> n;
    Graph a(n + 1, false);
    Graph b(n + 1, false);
    for(int i = 1;i < n;i++) {
        a.add(i, i + 1);
    }
    while(a.askDfs(1,b)) {
        a = b;
        a.cleanMarked();
        b = Graph(n + 1, false);
    }
    cout << "! ";
    a.cleanMarked();
    a.printDfs(1);
    cout.flush();
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;  
    cin >> t;
    while(t--) sol();
}