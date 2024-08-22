#include <bits/stdc++.h>

#define ll long long
#define lll __int128_t
#define nl "\n"

using namespace std;



int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];
    ll l = 0, r = 1000000010;
    ll m;
    while(l + 1 < r){
        m = (l + r) / 2;
        ll sobra = 0;
        for(int i = 0;i < n;i++){
            if(a[i] * m <= b[i] + sobra) {
                sobra += b[i] - a[i] * m;
            } else {
                r = m;
                break;
            }
        }
        if(r != m) l = m;
    }
    cout << l << nl;
}