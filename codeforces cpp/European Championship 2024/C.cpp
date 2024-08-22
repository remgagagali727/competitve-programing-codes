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
    ll n;
    bool biconnected;

    public:

    Graph(ll _n, bool _biconnected) {
        n = _n;
        biconnected = _biconnected;
        adj.resize(n);
        pesos.resize(n);
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

    ll checkValidation(ll v) {
        if(adj[v].size() == 1) return IS_LEAVE;
        ll mPeso = pesos[v];
        vector<ll> hijos;
        for(auto u : adj[v]) {
            ll uPeso = pesos[u];
            if(uPeso > mPeso) {
                uPeso = n - uPeso + uPeso - 1 - mPeso;
            }
            hijos.pb(uPeso);
        }
        ll currPeso = 1;
        sort(all(hijos));
        for(int i = 0;i < hijos.size();i++) {
            if(currPeso < hijos[i]) {
                if(i == hijos.size() - 1) return HAS_1_HOUSE;
                else return INVALID;
            }
            currPeso += hijos[i];
        }
        if(currPeso - hijos[hijos.size() - 1] == hijos[hijos.size() - 1]) return HAS_1_HOUSE;
        return DOESNT_HAVE_HOUSE;
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
    string ans = "YES";
    ll n;
    cin >> n;
    Graph g(n + 1, true);
    for(int i = 0;i < n - 1;i++) {
        ll a, b;
        cin >> a >> b;
        g.add(a, b);
    }
    g.calcularPesos(1, 0);
    ll housesWithNoHouse = 0;
    for(int i = 1;i <= n;i++) {
        ll validation = g.checkValidation(i);
        // switch(validation) {
        //     case IS_LEAVE:
        //         printf("IS_LEAVE: El individuo ha dejado.\n");
        //         break;
        //     case HAS_1_HOUSE:
        //         printf("HAS_1_HOUSE: El individuo tiene una casa.\n");
        //         break;
        //     case DOESNT_HAVE_HOUSE:
        //         printf("DOESNT_HAVE_HOUSE: El individuo no tiene casa.\n");
        //         break;
        //     case INVALID:
        //         printf("INVALID: Valor inválido.\n");
        //         break;
        // }
        if(validation == INVALID) ans = "NO";
        if(validation == DOESNT_HAVE_HOUSE) housesWithNoHouse++;
        if(housesWithNoHouse > 1) {
            // cout << "invalid cuz hauses";
            ans = "NO";
        }
        if(ans == "NO") break;
    }
    cout << ans;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--) sol();
}