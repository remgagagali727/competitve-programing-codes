#include <bits/stdc++.h>

using ll = long long;
using namespace std;

vector<int> primos;
vector<ll> valores;
vector<vector<int>> adj(61);


int dfs(int v, int p, ll acum, int i) {
    acum *= primos[i];
    valores[v] = acum;
    for(auto u : adj[v]) {
        if(u == p) continue;
        i = dfs(u, v, acum, i);
    }
    i++;
    return i;
}

struct dados {
    vector<int> lados;

    dados() {
        lados.resize(6);
    }

    pair<int, int> comparar(dados b) {
        int divisor = 36;
        int counter = 0;
        for(int i = 0;i < 6;i++) {
            for(int j = 0;j < 6;j++) {
                if(lados[i] == b.lados[j]) divisor--;
                else if(lados[i] > b.lados[j]) counter++;
            }
        }
        if(divisor == 0) return {0, 1};
        return {counter, divisor};
    }
};

int main() {
    vector<dados> a(3);
    for(int i = 0;i < 3;i++) {
        for(int j = 0;j < 6;j++) cin >> a[i].lados[j];
    }
    bool printedDado = false;
    for(int i = 0;i < 3;i++) {
        bool posible = true;
        pair<int, int> r2, r1;
        r1 = a[i].comparar(a[(i + 1) % 3]);
        r2 = a[i].comparar(a[(i + 2) % 3]);
        double d1, d2;
        d1 = r1.first; d1 /= r1.second;
        d2 = r2.first; d2 /= r2.second;
        double ans = min(d1, d2);
        if(ans < 0.5) posible = false;
        if(posible) {
            cout << i + 1 << endl;
            printedDado = true;
            break;
        }
    }
    if(!printedDado) cout << "No dice\n";
    return 0;
}
