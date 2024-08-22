#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define ull     unsigned long long
#define lll     __int128_t
#define ulll    unsigned __int128_t
#define all(a)  a.begin(),a.end()

using namespace std;

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
    ll n;
    cin >> n;
    vector<ll> rest(n);
    vector<ll> mas4(n);
    map<ll, multiset<ll>> map;
    for(int i = 0; i < n; i++) {
        ll h;
        cin >> h;
        rest[i] = h;
        mas4[i] = h >> 2;
        map[mas4[i]].insert(rest[i]);
    }
    for(int i = 0; i < n; i++) {
        int kind = mas4[i];
        auto x = map[kind].begin();
        cout << *x << " ";
        map[kind].erase(x);
    }
    cout << nl;
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) sol();
}