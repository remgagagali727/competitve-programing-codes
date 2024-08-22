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
    ll l = 2, r = 999;
    while(l + 1 < r) {
        ll m1, m2;
        ll espacio = (r - l) / 3;
        m1 = l + espacio;
        m2 = m1 + espacio;
        cout << "? " << m1 << " " << m2 << nl;
        cout.flush();
        ll ans1 = m1 * m2;
        ll ans2 = m1 * (m2 + 1);
        ll juryAns;
        cin >> juryAns;
        if(juryAns == ans1) {
            l = m2 + 1;
        } else if (juryAns == ans2) {
            l = m1 + 1;
            r = m2;
        } else {
            r = m1;
        }
    }
    cout << "? " << l << " " << l << nl;
    cout.flush();
    ll expectedAns = l * l;
    ll juryAns;
    cin >> juryAns;
    if(juryAns != expectedAns) {    
        cout << "! " << l << nl;
    } else {
        cout << "! " << r << nl;
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--) sol();
}