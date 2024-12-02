#include <bits/stdc++.h>

#define ll long long
#define nl "\n"

using namespace std;


void sol() {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    vector<int> columnas(n);
    vector<int> filas(n);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> m[i][j];
            columnas[j] += m[i][j];
            filas[i] += m[i][j];
        }
    }
    // n^2 + n + nlogn + n + n + 2n = n^2 + nlogn + 5n
    vector<int> nse = columnas;
    sort(nse.begin(),nse.end());
    int valorReal = nse[1];
    int colAc = 0, filAc = 0;
    for(auto x : columnas) if(valorReal != x) colAc++;
    for(auto x : filas) if(valorReal != x) filAc++;
    if(colAc && filAc) {
        int x1, x2, y1, y2;
        for(int i = 0;i < n;i++) {
            if(filas[i] > valorReal) x1 = i + 1 ;
            if(filas[i] < valorReal) x2 = i + 1;
            if(columnas[i] > valorReal) y1 = i + 1;
            if(columnas[i] < valorReal) y2 = i + 1;
        }
        if(x1 < x2) cout << x1 << " " << y1 << nl << x2 << " " << y2 << nl;
        else cout << x2 << " " << y2 << nl << x1 << " " << y1 << nl;
    } else if(filAc) {
        int x1, x2;
        for(int i = 0;i < n;i++) {
            if(filas[i] > valorReal) x1 = i + 1;
            if(filas[i] < valorReal) x2 = i + 1;
        }
        int dif = filas[x1 - 1] - filas[x2 - 1];
        dif /= 2;
        for(int i = 0;i < n;i++) {
            if(dif == m[x1 - 1][i] - m[x2 - 1][i]) {
                if(x1 < x2) cout << x1 << " " << i + 1 << nl << x2 << " " << i + 1 << nl;
                else cout << x2 << " " << i + 1 << nl << x1 << " " << i + 1 << nl;
                return;
            }
        }
    } else {
        int y1, y2;
        for(int i = 0;i < n;i++) {
            if(columnas[i] > valorReal) y1 = i + 1;
            if(columnas[i] < valorReal) y2 = i + 1;
        }
        int dif = columnas[y1 - 1] - columnas[y2 - 1];
        dif /= 2;
        for(int i = 0;i < n;i++) {
            if(dif == m[i][y1 - 1] - m[i][y2 - 1]) {
                if(y1 < y2) cout << i + 1 << " " << y1 << nl << i + 1 << " " << y2 << nl;
                else cout << i + 1 << " " << y2 << nl << i + 1 << " " << y1 << nl;
                return;
            }
        }
    }
}


int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    sol();
    return 0;
}