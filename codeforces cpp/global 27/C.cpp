#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isPow2(int n) {
    if(n == 1) return true;
    if(n % 2) return false;
    return isPow2(n / 2);
}

int bits(int n) {
    if(n == 0) return 0;
    int ans = 0;
    if(n & 1) ans = 1;
    return ans + bits(n / 2);
}

int logb2m(int n) {
    if(n == 1) return 0;
    return 1 + logb2m(n / 2);
}

ll expBin(int n, int pot) {
    if(pot == 1) return n;
    ll ans = 1;
    if(pot % 2) ans = n;
    ll res = expBin(n , pot / 2);
    return ans * res * res;
}

void permutacionMaxima(int n) {
    if(n == 8) cout << "2 4 5 1 3 6 7 8 ";
    else {
        if(isPow2(n)) {
            int nMax = expBin(2, logb2m(n) - 1);
            for(int i = nMax + 1;i < n - 1 ;i++) cout << i << " ";
            permutacionMaxima(nMax);
            cout << n - 1 << " " << n << " ";
        } else if(n & 1) {
            int nMax = expBin(2, logb2m(n));
            for(int i = nMax + 1;i < n;i++) cout << i << " ";
            permutacionMaxima(nMax);
            cout << n << " ";
        } else {
            int nMax = expBin(2, logb2m(n));
            for(int i = nMax + 1;i <= n;i++) cout << i << " ";
            permutacionMaxima(nMax);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        if(n == 5) {
            cout << "5 \n2 1 3 4 5" << '\n';
        } else if(n == 6) {
            cout << "7 \n1 2 4 6 5 3 \n";
        } else if(n == 7) {
            cout << "7 \n2 4 5 1 3 6 7 \n";
        } else {
            if(n % 2) {
                cout << n << '\n';
            } else {
                cout << expBin(2, logb2m(n) + 1) - 1 << '\n';
            }
            permutacionMaxima(n);
            cout << '\n';
        }
    }
}