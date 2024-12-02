#include <bits/stdc++.h>

using namespace std;

using ll = long long;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, p, h;
    cin >> n >> p >> h;
    vector<bool> dobleces(n);
    for(int i = n - 1;i >= 0;i--) {
        if(h > (1LL << i)) {
            dobleces[i] = true;
            h = (1LL << (i + 1)) - h + 1;
        } else {
            dobleces[i] = false;
        }
    }
    for(int i = 0;i < n;i++) {
        if(dobleces[i]) {
            if(p > (1LL << (n - i - 1))) {
                cout << 'R';
                p -= (1LL << (n - i - 1));
            } else {
                cout << 'L';
            }
            p = (1LL << (n - i - 1)) - p + 1;
        } else {
            if(p > (1LL << (n - i - 1))) {
                cout << 'L';
                p -= (1LL << (n - i - 1));
            } else {
                cout << 'R';
            }
        }
    }
    cout << '\n';
}