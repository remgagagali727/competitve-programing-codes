    #include <bits/stdc++.h>

    #define ll long long

    using namespace std;

    #define PAR 0
    #define IMPAR 1

    struct node{
        ll mx;
        bool posicion;
        ll tam;
        bool siempretomamax = false;
    };

    struct DSU{
        ll n;
        ll mx;
        vector<node> nodos;
        vector<ll> padres;

        ll ans = 0;
        ll tomamosMaximo = 0;
        bool stm = false;

        DSU(ll _n, ll _mx) {
            n = _n;
            mx = _mx;
            nodos.resize(n);
            padres.resize(n);
        }

        ll getRespuesta() {
            if(stm) return ans;
            if(tomamosMaximo == 0) {
                return ans - 1;
            }
            return ans;
        }

        void inicializar(ll i, ll v) {
            padres[i] = i;
            nodos[i].mx = v;
            nodos[i].posicion = IMPAR;
            nodos[i].tam = 1;
            ans++;
            if(mx == v)
                tomamosMaximo++;
        }

        ll getParent(ll i) {
            if(padres[i] == i) return i;
            else return padres[i] = getParent(padres[i]);
        }

        ll getRespuesta(node a) {
            return (a.tam + 1) / 2;
        }

        ll toma(node a) {
            if(a.mx != mx) return 0;
            if(a.siempretomamax) return 1;
            if(a.tam % 2 && a.posicion == PAR) return 0;
            return 1;
        }

        node unir(node a, node b) {
            node toReturn;
            toReturn.mx = max(a.mx, b.mx);
            toReturn.tam = a.tam + b.tam;
            if(a.mx >= b.mx) {
                toReturn.posicion = a.posicion;
            } else {
                if(a.tam % 2) {
                    toReturn.posicion = b.posicion ^ 1;
                } else {
                    toReturn.posicion = b.posicion;
                }
            }
            toReturn.siempretomamax = a.siempretomamax || b.siempretomamax;
            if(!toReturn.siempretomamax) {
                if(a.mx == mx && b.mx == mx) {
                    if(a.tam % 2) {
                        toReturn.siempretomamax = a.posicion == b.posicion;
                    } else {
                        toReturn.siempretomamax = a.posicion != b.posicion;
                    }
                }
            }
            ans += (getRespuesta(toReturn) - getRespuesta(a) - getRespuesta(b));
            tomamosMaximo += (toma(toReturn) - toma(a) - toma(b));
            if(toReturn.siempretomamax) stm = true;
            return toReturn;
        }

        void unir(ll v, ll u) {
            u = getParent(u);
            v = getParent(v);
            if(u == v) return;
            padres[u] = v;
            nodos[v] = nodos[u] = unir(nodos[v], nodos[u]);
            // cout << nodos[v].mx << " " << nodos[v].posicion << " " << nodos[v].siempretomamax << " " << nodos[v].tam << " " << v << endl;
        }
    };

    void casito() {
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<pair<ll, ll>> ps(n);
        ll mx = 0;
        for(ll i = 0;i < n;i++) {
            cin >> a[i];
            mx = max(a[i], mx);
            ps[i].first = a[i];
            ps[i].second = i;
        }
        sort(ps.rbegin(), ps.rend());
        DSU dsu(n, mx);
        ll ans = 0;
        for(ll i = 0;i < n;i++) {
            auto x = ps[i];
            dsu.inicializar(x.second, x.first);
            if(x.second != 0) {
                if(a[x.second - 1] > a[x.second]) dsu.unir(x.second - 1, x.second);
            }
            if(x.second != n - 1) {
                if(a[x.second + 1] >= a[x.second]) dsu.unir(x.second, x.second + 1);
            }
            ans = max(ans, dsu.getRespuesta() + x.first);
        }
        cout << ans + mx << endl;
    }

    int main() {
        ll t;
        cin >> t;
        while(t--) casito();
    }