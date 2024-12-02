#include <bits/stdc++.h>

#define ll long long
#define nl "\n"

using namespace std;

ll checkSquares(int m, int minin) {
    ll squares = 0;
    int l, r;
    for(int i = 1;i <= minin;i++) {
        l = 0, r = minin;
        while(l + 1 < r) {
            ll mid = (l + r) / 2;
            if(mid * mid + i * i <= m) {
                l = mid;
            } else {
                r = mid;
            }
        }
        squares += l;
    }
    return squares * 4;
}

void sol() {
    ll n;
    cin >> n;
    ll l, r;
    ll minin = sqrt(n) + 1;
    l = 0, r = n + 10;
    while(l + 1 < r) {
        ll m = (l + r) / 2;
        ll squares = checkSquares(m, minin + 10);
        if(squares >= n) {
            r = m;
        } else {
            l = m;
        }
    }
    long double ans = sqrt(r);
    cout << setprecision(20) << ans << nl;
}


int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    sol();
    return 0;
}