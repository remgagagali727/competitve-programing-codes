#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll mod = 1000000007;

ll expBin(ll base, ll exp) {
    if(exp == 0) return 1;
    ll dup = expBin(base, exp / 2);
    dup *= dup;
    dup %= mod;
    if(exp & 1) {
        dup *= base;
        dup %= mod;
    } 
    return dup;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i = 0;i < n;i++) cin >> a[i];
        ll a0 = a[0];
        vector<ll> pPoints(n);
        vector<ll> lastBigger(n);
        stack<ll> s;
        for(ll i = 0;i < n;i++) {
            while(a[i] % 2 == 0) {
                a[i] /= 2;
                pPoints[i]++;
            }
        }
        // for(ll i = 0;i < n;i++) {
        //     cout << a[i] << endl;
        // }
        for(ll i = 1;i < n;i++) pPoints[i] += pPoints[i - 1];
        for(ll i = 0;i < n;i++) {
            ll indice = -1;
            while(!s.empty()) {
                auto x = s.top();
                ll diferencia = pPoints[i] - pPoints[x];
                ll t = a[i];
                while(t < a[x]) {
                    if(diferencia == 0) break;
                    diferencia--;
                    t *= 2;
                }
                if(t < a[x]) {
                    indice = x;
                    break;
                }
                s.pop();
            }
            s.push(i);
            lastBigger[i] = indice;
        }
        vector<ll> dp(n);
        vector<ll> pf(n);
        cout << a0 << " ";
        dp[0] = a0;
        pf[0] = a[0];
        for(ll i = 1;i < n;i++) pf[i] += a[i] + pf[i - 1];
        for(ll i = 1;i < n;i++) {
            ll acum;
            if(lastBigger[i] == -1) acum = 0;
            else acum = dp[lastBigger[i]];
            ll extra = pf[i - 1];
            ll puntosDiferencia = pPoints[i];
            if(lastBigger[i] != -1) {
                puntosDiferencia -= pPoints[lastBigger[i]];
                extra -= pf[lastBigger[i]];
            }
            ll ans = (acum + extra + a[i] * expBin(2, puntosDiferencia));
            ans %= mod;
            cout << ans << " ";
            dp[i] = ans;
        }
        cout << '\n';
    }
}