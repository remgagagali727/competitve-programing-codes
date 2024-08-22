#include <bits/stdc++.h>

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

#define IS_LEAVE 10
#define HAS_1_HOUSE 1
#define DOESNT_HAVE_HOUSE 2
#define INVALID 0

using namespace std;

const ll mod = 1000000007;

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
    private:
    vector<vector<ll>> adj;
    vector<ll> pesos;
    vector<bool> marked;
    vector<ll> distances;
    ll n;
    bool biconnected;

    public:

    Graph(ll _n, bool _biconnected) {
        n = _n;
        biconnected = _biconnected;
        adj.resize(n);
        pesos.resize(n);
        marked.resize(n);
        distances.resize(n);
    }

    void add(ll v, ll u) {
        adj[v].pb(u);
        if(biconnected) adj[u].pb(v);
    }

    ll calcularPesos(ll v, ll p) {
        ll peso = 1;
        for(auto u : adj[v]) {
            if(u != p) {
                peso += calcularPesos(u, v);
            }
        }
        pesos[v] = peso;
        return peso;
    }

    void setMarked(ll v) {
        marked[v] = true;
    }

    pair<ll, ll> getFurthestMarked(ll v, ll p) {
        pair<ll, ll> ans;
        if(marked[v]) ans = {0, v};
        else ans = {0, 0};
        for(auto u : adj[v]) {
            if(u != p) {
                auto cAns = getFurthestMarked(u, v);
                cAns.first += 1;
                if(cAns.second != 0 && cAns.first > ans.first) {
                    ans = cAns;
                }
            }
        }
        return ans;
    }

    void setMaxDistances(ll v, ll p, ll acum) {
        distances[v] = fmax(acum, distances[v]);
        for(auto u : adj[v]) {
            if(u != p) {
                setMaxDistances(u, v, acum + 1);
            }
        }
    }

    ll getMinDistanceOfAll() {
        ll ans = LONG_LONG_MAX;
        for(int i = 1;i <= n;i++) {
            ans = min(distances[i], ans);
        }
        return ans;
    }

    ll getDistanceOf(ll v) {
        return distances[v];
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

void sol() {
    ull k, n;
    ull ans = ullinf;
    cin >> n >> k;
    vector<ull> a(n + 1);
    vector<ull> cold(k + 1);
    vector<ull> hot(k + 1);

    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= k;i++) cin >> cold[i];
    for(int i = 1;i <= k;i++) cin >> hot[i];

    vector<ull> dp(max(k, n) + 1, ullinf);
    dp[0] = 0;
    
    ull y = 0;
    ull last;
    ull curr;
    for(int x = 1;x <= n;x++) {
        vector<ull> ndp(max(k, n) + 1, ullinf);
        last = a[y];
        curr = a[x];
        if(last == curr) {
            for(int i = 0;i <= k;i++) {
                ndp[i] = min(ndp[i], dp[i] + hot[curr]);
            }
            for(int i = 0;i <= k;i++) {
                if(i == curr) continue;
                ndp[curr] = min(ndp[curr], dp[i] + cold[curr]);
            }
            ndp[curr] = min(ndp[curr], dp[curr] + hot[curr]);
        } else {
            for(int i = 0;i <= k;i++) {
                ndp[i] = min(ndp[i], dp[i] + cold[curr]);
            }
            for(int i = 0;i <= k;i++) {
                if(i == curr) continue;
                ndp[last] = min(ndp[last], dp[i] + cold[curr]);
            }
            ndp[last] = min(ndp[last], dp[curr] + hot[curr]);
        }
        dp = ndp;
        y++;
    }
    for(auto axd : dp) ans = min(ans, axd);
    cout << ans << nl;

}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--) sol();
}