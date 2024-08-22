#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define lli     long long int
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
    vector<lli> b;
    vector<lli> h;
    int n;
    string s;


    Hash(int _n, string _s) {
        s = _s;
        n = _n;
        h.resize(n + 1, 0);
        b.resize(2 * n + 1);
        init();
    }

    lli check_hash(int l, int r) {
        return (((h[r] + MOD - h[l]) % MOD) * b[n - l - 1]) % MOD;
    }
};


void sol() {
    int n, q;
    string s;
    lli ans = 0;
    cin >> n >> q;
    cin >> s;
    vector<ll> uni(n);
    vector<ll> duo(n);
    uni[0] = duo[0] = 1;
    duo[1] = 2;
    Hash nor(n,s);
    reverse(all(s));
    Hash rev(n,s);
    reverse(all(s));
    for(int i = 1;i < n;i++) {
        if(i != 1) {
            if(s[i - 2] == s[i]) duo[i] = duo[i - 1] + 1;
            else duo[i] = 2;
        }
        if(s[i - 1] == s[i]) uni[i] = uni[i - 1] + 1;
        else uni[i] = 1;
    }
    for(int i = 0;i < q;i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ll sn = b - a + 1;
        if(sn <= uni[b]) {
            ans = 0;
        } else if (sn <= duo[b]) {
            ans = (sn / 2) * ((sn / 2) + 1);
        } else if(nor.check_hash(a, b) == rev.check_hash(n-1-b,n-1-a)) {
            ans = (sn * (sn + 1)) / 2 - 1 - sn;
        } else {
            ans = (sn * (sn + 1)) / 2 - 1;
        }
        cout << ans << nl;
    }
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) sol();
}
