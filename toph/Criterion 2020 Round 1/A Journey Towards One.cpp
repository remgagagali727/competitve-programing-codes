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
    ll n;
    cin >> n;
    cout << dp[n] << nl;
}

vector<ll> dp;

int main() {
    int t = 1;
    dp.resize(10e6 + 4);
    for(int i = 1;i < 10e6 + 2;i++) {
        dp[i - 1] = min(dp[i - 1], dp[i] + 1);
        dp[i + 1] = min(dp[i + 1], dp[i] +1);
        dp[i / 2] = min(dp[i / 2], dp[i] + 1);
    }
    cin >> t;
    while(t--) sol();
}
