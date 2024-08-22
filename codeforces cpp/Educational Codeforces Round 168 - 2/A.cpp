#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define ull     unsigned long long
#define lll     __int128_t
#define ulll    unsigned __int128_t
#define all(a)  a.begin(),a.end()

using namespace std;

class Graph{
    private:
    vector<vector<ll>> adj;
    ll n;

    public:

    Graph(ll _n) {
        n = _n;
        adj.resize(n);
    }

    void add(ll v, ll u) {
        adj[v].pb(u);
        adj[u].pb(v);
    }

    bool dfs_winner(ll v, ll f, bool turn) {
        for(auto u : adj[v]) {
            if(u != f) {
                if(dfs_winner(u, v, !turn) == turn) {
                    return turn;
                }
            }
        }
        return !turn;
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

void sol() {
    string s;
    cin >> s;
    ll n = s.size();
    bool inserted = false;
    for(int i = 1;i < n;i++) {
        if(s[i] == s[i - 1]) {
            inserted = true;
            string insert;
            if(s[i] == 'z')  insert = "a";
            else insert = s[i] + 1;
            s.insert(i, insert);
            break;
        }
    }
    string insert;
    if(s[0] == 'z')  insert = "a";
    else insert = s[0] + 1;
    if(!inserted) s.insert(0, insert);
    cout << s << nl;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--) sol();
}