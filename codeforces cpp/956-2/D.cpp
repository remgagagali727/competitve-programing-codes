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

ll dig(ll n) {
    if(n == 0) return 0;
    return dig(n / 10) + 1;
}

void sol() {
    ll n;
    cin >> n;
    map<ll,ll> map;
    vector<bool> a(n, false);
    vector<ll> b(n);
    for(int i = 1;i <= n;i++) {
        ll h;
        cin >> h;
        map[h] = i;
    }
    for(int i = 1;i <= n;i++) {
        ll h;
        cin >> h;
        b[i - 1] = map[h];
    }
    ll count = 0;
    for(int i = 0;i < n;i++) {
        if (!a[i]) {
            int x = i;
            while (!a[x]) {
                a[x] = true;
                x = b[x] - 1;
                if(x == -1) {
                    count = -1;
                    i = n;
                    break;
                }
                if(a[x]) break;
                count++;
            }
        }
    }
    string ans = "NO";
    if(count % 2 == 0) ans = "YES";
    cout << ans << nl;
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) sol();
}