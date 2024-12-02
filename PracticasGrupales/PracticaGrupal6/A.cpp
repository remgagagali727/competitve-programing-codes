#include <bits/stdc++.h>

using ll = long long;
using namespace std;

vector<int> primos;
vector<ll> valores;
vector<vector<int>> adj(61);



ll calcula(ll tam, ll k, ll n, ll acum, ll piso) {
    if(tam == n) return acum;
    if(piso > k) {
        return acum + n - tam;
    }
    if(k * tam + 1 > n) {
        ll acum2 = acum;
        ll ans = 0;
        ll delta = 0;
        for(int i = 1;i < piso;i++) {
            ll l = 0, r = k + 1;
            while(l + 1 < r) {
                ll m = (l + r) / 2;
                ll pos = m * tam;
                if(delta + pos <= n) {
                    l = m;
                } else {
                    r = m;
                }
            }
            ans += acum2 * l;
            acum2 = (acum2 - 1) / k;
            if(delta + l * tam == n) return ans;
            delta += l * tam;
            tam = (tam - 1) / k;
        }
        return ans;
    } else {
        tam = k * tam + 1;
        acum = acum * k + 1;
        return calcula(tam, k, n, acum, piso + 1);
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n, k;
    cin >> n >> k;
    cout << calcula(1, k, n, 0, 1) << endl;
}
