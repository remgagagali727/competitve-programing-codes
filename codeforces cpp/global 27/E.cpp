#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll mod = 10e9 + 7;

ll expBin(ll base, ll exp) {
    if(exp < 0) return 0;
    if(exp == 0) return 1;
    ll dupe = expBin(base, exp / 2);
    dupe *= dupe;
    dupe %= mod;
    if(exp & 1) dupe *= base;
    dupe %= mod;
    return dupe;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll x, y, z, k;
        cin >> x >> y >> z >> k;
        for(int w = 1;w <= 100;w++) {
            if(w % k == 0) cout << "---------" << endl;
            ll n = w / k;
            if(z - (n * (n - 1) * k / 2) < 0) break;
            ll costoEnMonedas = w * x + ((z - (n * (n + 1) * k / 2) + w - 1) / w * y + n * y);
            if(costoEnMonedas > 0) cout << costoEnMonedas << endl;
            else break;
        }
    }
}