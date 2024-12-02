#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<bool> activo(n + 1);
    vector<ll> cribaActivo(n + 1);
    vector<ll> cribaValor(n + 1);
    vector<ll> criba(n + 1);
    criba[1] = 1; 
    for(ll i = 2;i <= n;i++) {
        if(criba[i] == 0) {
            criba[i] = i;
            for(ll j = i * i;j <= n;j += i) criba[j] = i;
        }
    }
    while(m--) {
        char c; cin >> c;
        ll x; cin >> x;
        if(c == '-') {
            if(!activo[x]) {
                cout << "Already off" << '\n';
            } else {
                activo[x] = false;
                cout << "Success" << '\n';
                while(x != 1) {
                    cribaActivo[criba[x]]--;
                    cribaValor[criba[x]] = 0;
                    x /= criba[x];
                }
            }
        } else {
            if(activo[x]) {
                cout << "Already on" << '\n';
            } else {
                ll valor = 0;
                ll tx = x;
                while(x != 1) {
                    valor = max(valor, cribaValor[criba[x]]);
                    x /= criba[x];
                }
                x = tx;
                if(valor == 0) {
                    activo[x] = true;
                    while(x != 1) {
                        cribaValor[criba[x]] = tx;
                        cribaActivo[criba[x]]++;
                        x /= criba[x];
                    }
                    cout << "Success" << '\n';
                } else {
                    cout << "Conflict with " << valor << '\n';
                }
            }
        }
    }
}