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

#define slotIndex 0
#define slotValue 1

using namespace std;

const ll mod = 1000000007;

class Graph{
    private:
    vector<vector<ll>> adj;
    ll n;
    bool biconnected;

    public:

    Graph(ll _n, bool _biconnected) {
        n = _n;
        biconnected = _biconnected;
        adj.resize(n);
    }

    void add(ll v, ll u) {
        adj[v].pb(u);
        if(!biconnected) adj[u].pb(v);
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
    vector<ll> ans(n);
    ll posible = true;
    vector<vector<ll>> criticPoints;
    for(int i = 0;i < n;i++) {
        cin >> ans[i];
        if(ans[i] != -1) {
            criticPoints.pb({i, ans[i]});
        }
    }
    if(criticPoints.size()==0) {
        criticPoints.pb({0, 1});
        ans[0] = 1;
    }
    for(int i = criticPoints[0][slotIndex] - 1;i >= 0;i--) {
        ll last = ans[i + 1];
        if(last == 1) {
            ans[i] = 2;
        } else {
            ans[i] = last / 2;
        }
    }
    for(int i = criticPoints[criticPoints.size() - 1][slotIndex] + 1;i < n;i++) {
        ll last = ans[i - 1];
        if(last == 1) {
            ans[i] = 2;
        } else {
            ans[i] = last / 2;
        }
    }
    for(int i = 1;i < criticPoints.size();i++) {
        ll pointA, pointB;
        pointA = criticPoints[i - 1][slotIndex];
        pointB = criticPoints[i][slotIndex];
        ll difference = getLog2(criticPoints[i][slotValue]) - getLog2(criticPoints[i - 1][slotValue]);
        ll indxDiff = pointB - pointA;
        if(!((difference & 1) ^ (indxDiff & 1))) {
            ll midpoint;
            if(difference & 1) {

            } else {

            }
            midpoint = (pointA + pointB - difference) / 2;
            for(int i = pointA + 1;i <= midpoint && i < n && i >= 0;i++) {
                if(i == pointA || i == pointB) continue;
                ll last = ans[i - 1];
                if(last == 1) {
                    ans[i] = 2;
                } else {
                    ans[i] = last / 2;
                }
            }
            for(int i = pointB - 1;i >= midpoint && i >= 0 && i < n;i--) {
                if(i == pointA || i == pointB) continue;
                ll last = ans[i + 1];
                if(last == 1) {
                    ans[i] = 2;
                } else {
                    ans[i] = last / 2;
                }
            }
        }
    }
    for(int i = 0;i < n - 1;i++) {
        if(ans[i] / 2 != ans[i + 1] && ans[i] != ans[i + 1] / 2) {
            posible = false;
            break;
        }
        if(ans[i] == -1) {
            posible = false;
            break;
        }
    }
    if(posible)
        for(auto x : ans) cout << x << " ";
    else cout << "-1";
    cout << nl;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--) sol();
}