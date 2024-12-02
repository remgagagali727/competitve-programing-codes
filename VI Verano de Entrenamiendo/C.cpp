#include <bits/stdc++.h>

#define ll long long
#define nl "\n"

using namespace std;


void sol() {
    ll n;
    cin >> n;
    if(n > 3) {
        vector<vector<ll>> xd(n, vector<ll>(n));
        vector<ll> filas(n);
        vector<ll> columnas(n);
        for(ll i = 0;i < n;i++) {
            for(ll j = 0;j < n;j++) {
                cin >> xd[i][j];
                filas[i] += xd[i][j];
                columnas[j] += xd[i][j];
            }
        }
        ll valorReal = 0;
        map<ll,ll> m;
        for(ll i = 0;i < n;i++) {
            m[filas[i]]++;
            if(m[filas[i]] > 1) {
                valorReal = filas[i];
                break;
            }
        }
        ll difFilas = 0;
        ll difColumnas = 0;
        for(auto f : filas) {
            if(f != valorReal) {
                difFilas++;
            }
        }
        for(auto f : columnas) {
            if(f != valorReal) {
                difColumnas++;
            }
        }
        if(difFilas && difColumnas) {
            ll x1, x2, y1, y2;
            for(ll i = 0;i < n;i++) {
                if(valorReal - filas[i] > 0) {
                    x1 = i + 1;
                } else if(valorReal - filas[i] < 0) {
                    x2 = i + 1;
                }
                if(valorReal - columnas[i] > 0) {
                    y1 = i + 1;
                } else if(valorReal - columnas[i] < 0) {
                    y2 = i + 1;
                }
            }
            if(y1 < y2)
                cout << y1 << " " << x1 << nl << y2 << " " << x2 << nl;
            else 
                cout << y2 << " " << x2 << nl << y1 << " " << x1 << nl;
        } else if(difColumnas) {
            ll x1, x2;
            for(ll i = 0;i < n;i++) {
                if(valorReal - columnas[i] > 0) x1 = i;
                if(valorReal - columnas[i] < 0) x2 = i;
            }
            ll dif = valorReal - columnas[x1];
            for(ll i = 0;i < n;i++) {
                if(xd[i][x1] - xd[i][x2] == -dif) {
                    if(x1 < x2)
                        cout << i + 1 << " " << x1 + 1 << nl << i + 1 << " " << x2 + 1 << nl;
                    else 
                        cout << i + 1 << " " << x2 + 1 << nl << i + 1 << " " << x1 + 1 << nl;
                    break;
                }
            }
        } else {
            ll x1, x2;
            for(ll i = 0;i < n;i++) {
                if(valorReal - filas[i] > 0) x1 = i;
                if(valorReal - filas[i] < 0) x2 = i;
            }
            ll dif = valorReal - filas[x1];
            for(ll i = 0;i < n;i++) {
                if(xd[x1][i] - xd[x2][i] == -dif) {
                    if(x1 < x2)
                        cout << x1 + 1 << " " << i + 1 << nl << x2 + 1 << " " << i + 1 << nl;
                    else 
                        cout << x2 + 1 << " " << i + 1 << nl << x1 + 1 << " " << i + 1 << nl;
                    break;
                }
            }
        }
    } else {
        vector<vector<ll>> xd(n, vector<ll>(n));
        vector<ll> filas(n);
        vector<ll> columnas(n);
        for(ll i = 0;i < n;i++) {
            for(ll j = 0;j < n;j++) {
                cin >> xd[i][j];
                filas[i] += xd[i][j];
                columnas[j] += xd[i][j];
            }
        }
        ll valorReal = 15;
        ll difFilas = 0;
        ll difColumnas = 0;
        for(auto f : filas) {
            if(f != valorReal) {
                difFilas++;
            }
        }
        for(auto f : columnas) {
            if(f != valorReal) {
                difColumnas++;
            }
        }
        if(difFilas && difColumnas) {
            ll x1, x2, y1, y2;
            for(ll i = 0;i < n;i++) {
                if(valorReal - filas[i] > 0) {
                    x1 = i + 1;
                } else if(valorReal - filas[i] < 0) {
                    x2 = i + 1;
                }
                if(valorReal - columnas[i] > 0) {
                    y1 = i + 1;
                } else if(valorReal - columnas[i] < 0) {
                    y2 = i + 1;
                }
            }
            if(y1 < y2)
                cout << y1 << " " << x1 << nl << y2 << " " << x2 << nl;
            else 
                cout << y2 << " " << x2 << nl << y1 << " " << x1 << nl;
        } else if(difColumnas) {
            ll x1, x2;
            for(ll i = 0;i < n;i++) {
                if(valorReal - columnas[i] > 0) x1 = i;
                if(valorReal - columnas[i] < 0) x2 = i;
            }
            ll dif = valorReal - columnas[x1];
            for(ll i = 0;i < n;i++) {
                if(xd[i][x1] - xd[i][x2] == -dif) {
                    if(x1 < x2)
                        cout << i + 1 << " " << x1 + 1 << nl << i + 1 << " " << x2 + 1 << nl;
                    else 
                        cout << i + 1 << " " << x2 + 1 << nl << i + 1 << " " << x1 + 1 << nl;
                    break;
                }
            }
        } else {
            ll x1, x2;
            for(ll i = 0;i < n;i++) {
                if(valorReal - filas[i] > 0) x1 = i;
                if(valorReal - filas[i] < 0) x2 = i;
            }
            ll dif = valorReal - filas[x1];
            for(ll i = 0;i < n;i++) {
                if(xd[x1][i] - xd[x2][i] == -dif) {
                    if(x1 < x2)
                        cout << x1 + 1 << " " << i + 1 << nl << x2 + 1 << " " << i + 1 << nl;
                    else 
                        cout << x2 + 1 << " " << i + 1 << nl << x1 + 1 << " " << i + 1 << nl;
                    break;
                }
            }
        }
    }
}


int main() {
    sol();
    return 0;
}