#include <bits/stdc++.h>

using namespace std;

using mint = __int128_t;

vector<mint> filas(1002);
vector<vector<vector<bool>>> visited(1002, vector<vector<bool>>(102, vector<bool>(2)));
int r, c;

bool dfs(int row, mint valor, int rotacion, int volt) {
    if(row < 0) return true;
    if(row > r) return false;
    if(valor & filas[row]) return false;
    if(visited[row][rotacion][volt]) return false;
    visited[row][rotacion][volt] = true;
    mint tvalor;
    bool r = dfs(row - 1, valor, rotacion, volt);
    if(r) return r;
    r = dfs(row + 1, valor, rotacion, volt);
    if(r) return r;
    tvalor = ((valor & 1) ? (1 << (c - 1)) : 0) + (valor >> 1);
    r = dfs(row, tvalor, (rotacion + 1) % c, volt);
    if(r) return r;
    if(valor >= (1 << (c - 1))) tvalor = (valor - (1 << (c - 1))) + 1;
    else tvalor = valor << 1;
    r = dfs(row, tvalor, (rotacion - 1 + c) % c, volt);
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    string s;
    cin >> s;
    mint derecho, volteado;
    derecho = volteado = 0;
    for(int i = 0;i < c;i++) {
        derecho = derecho << 1;
        volteado = volteado << 1;
        derecho += s[i] - '0';
        volteado += s[c - i - 1] - '0';
    }
    for(int i = 0;i < r;i++) {
        cin >> s;
        for(int j = 0;j < c;j++) {
            filas[r - i - 1] = filas[r - i - 1] << 1;
            filas[r - i - 1] += s[j] - '0';
        }
    }
    if(dfs(r, derecho, 0, 0)) {
        cout << 'Y' << '\n';
    } else if(dfs(r, volteado, 0, 1)){
        cout << 'Y' << '\n';
    } else {
        cout << 'N' << '\n';
    }
}