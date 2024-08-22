#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

vector<vector<int>> divs;

int main() {
    ll n, q;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    vector<vector<ll>> querries;
    vector<ll> acum(n,LONG_LONG_MAX);
    querries.resize(n,acum);
    for(int R = 1;R < n;R++){
        ll mejor = LONG_LONG_MAX;
        for(int L = R-1;L >= 0;L--){
            acum[L] = min(abs(a[R]-a[L]),acum[L]);
            mejor = min(acum[L],mejor);
            querries[L][R] = mejor;
        }
    }
    cin >> q;
    for(int i = 0;i < q;i++) {
        int a, b;
        cin >> a >> b;
        cout << querries[a-1][b-1] << nl;
    }
    return 0;
}
