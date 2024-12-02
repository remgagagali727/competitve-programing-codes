#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll mod = 1e9 + 7;
//xd
vector<vector<vector<vector<ll>>>> dpv;
//xd
vector<ll> factoriales(25);
vector<ll> invFactoriales(25);

ll expBin(ll base, ll exp){
    if(exp == 1)     return base;
    ll p = expBin(base, exp / 2);
    p *= p;
    p %= mod;
    if(exp & 1) {
        p *= base;
        p %= mod;
    }
    return p;
}

ll dp(ll nivel, ll rojo, ll verde, ll azul) {
    if(rojo < 0 || verde < 0 || azul < 0) return 0;
    if(nivel == 0) return 1;
    if(dpv[nivel][rojo][verde][azul] > 0) return dpv[nivel][rojo][verde][azul];
    ll ans = 0;
    if(nivel % 3 == 0) {
        ll extra = invFactoriales[nivel / 3];
        ll t = extra * extra;
        t %= mod;
        t *= extra;
        t %= mod;
        t *= dp(nivel - 1, rojo - nivel / 3, verde - nivel / 3, azul - nivel / 3);
        t %= mod;
        t *= factoriales[nivel];
        t %= mod;
        ans += t;
        ans %= mod;
    }
    if(nivel % 2 == 0) {
        ll extra = invFactoriales[nivel / 2];
        extra *= extra;
        extra %= mod;
        extra *= factoriales[nivel];
        extra %= mod;
        ans += (dp(nivel - 1, rojo,verde - nivel / 2, azul - nivel / 2) * extra) % mod;
        ans %= mod;
        ans += (dp(nivel - 1, rojo - nivel / 2,verde, azul - nivel / 2) * extra) % mod;
        ans %= mod;
        ans += (dp(nivel - 1, rojo - nivel / 2,verde - nivel / 2, azul) * extra) % mod;
    }
    ans += dp(nivel - 1, rojo - nivel, verde, azul);
    ans += dp(nivel - 1, rojo, verde - nivel, azul);
    ans += dp(nivel - 1, rojo, verde, azul - nivel);
    ans %= mod;
    return dpv[nivel][rojo][verde][azul] = ans;
}

int main() {
    iostream::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, r, g, b;
    cin >> n >> r >> g >> b;
    factoriales[0] = 1;
    for(int i = 1;i < 25;i++) factoriales[i] = (factoriales[i - 1] * i) % mod;
    for(int i = 0;i < 25;i++) invFactoriales[i] = expBin(factoriales[i], mod - 2);
    dpv = vector<vector<vector<vector<ll>>>>(n + 2, vector<vector<vector<ll>>>(r + 2, vector<vector<ll>>(g + 2, vector<ll>(b + 2, 0))));
    cout << dp(n, r, g, b) << '\n';
}