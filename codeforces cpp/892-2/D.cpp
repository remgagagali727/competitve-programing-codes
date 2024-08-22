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

#define IS_LEAVE 10
#define HAS_1_HOUSE 1
#define DOESNT_HAVE_HOUSE 2
#define INVALID 0

using namespace std;

const ll mod = 1000000007;

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

void sol() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> tps;
    for(int i = 0;i < n;i++) {
        ll l, r;
        cin >> l >> r >> r >> r;
        tps.push_back({l, r});
    }
    vector<pair<ll,ll>> truePairs;
    sort(all(tps));
    pair<ll, ll> curr = tps[0];
    for(int i = 0;i < tps.size();i++) {
        if(curr.second >= tps[i].first) {
            curr.second = max(curr.second, tps[i].second);
        } else {
            truePairs.pb(curr);
            curr = tps[i];
        }
    }
    truePairs.pb(curr);
    ll q;
    cin >> q;
    for(int i = 0;i < q;i++) {
        ll h; cin >> h;
        ll l = 0, r = truePairs.size();
        while(l + 1 < r) {
            ll m = (l + r) / 2;
            auto x = truePairs[m];
            if(h >= x.first) {
                l = m;
            } else {
                r = m;
            }
        }
        if(h >= truePairs[l].first) cout << max(h, truePairs[l].second) << " ";
        else cout << h << " ";
    }
    cout << nl;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--) sol();
}