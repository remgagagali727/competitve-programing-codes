#include <bits/stdc++.h>

using namespace std;

struct nodo{
    int valor, pos, minvalor;
    nodo(int _valor, int _pos, int _minvalor) {
        valor = _valor;
        pos = _pos;
        minvalor = _minvalor;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n;i++) cin >> a[i];
        stack<nodo> dp;
        reverse(a.begin(), a.end());
        dp.push(nodo(a[0], 1, a[0]));
        for(int i = 1;i < n;i++) {
            auto x = dp.top();
            auto y = x;
            y.pos = 1;
            y.minvalor = a[i];
            y.valor = a[i];
            if(a[i] > x.minvalor) {
                while(a[i] > x.minvalor) {
                    y.pos += x.pos;
                    y.minvalor = min(x.minvalor, y.minvalor);
                    y.valor = max(y.valor, x.valor);
                    dp.pop();
                    if(dp.empty()) break;
                    x = dp.top();
                }
                dp.push(y);
            } else {
                dp.push(nodo(a[i], 1, a[i]));
            }
        }
        while(!dp.empty()) {
            auto x = dp.top();
            dp.pop();
            for(int i = 0;i < x.pos;i++) {
                cout << x.valor << " ";
            }
        }
        cout << '\n';
    }
}