#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0;i < n;i++) cin >> a[i];
    vector<ll> pf(n + 1);
    for(ll i = 1;i <= n;i++) pf[i] = a[i - 1] + pf[i - 1];
    vector<ll> sumaDeBloque(n);
    for(ll i = 1;i <= n;i++) {
        sumaDeBloque[0] += pf[i];
    }
    for(ll i = 1;i < n;i++) {
        sumaDeBloque[i] = sumaDeBloque[i - 1] - (n - i + 1) * a[i - 1];
    }
    vector<ll> pFF(n + 1);
    for(int i = 1;i <= n;i++) pFF[i] = pFF[i - 1] + pf[i];
    vector<ll> pSB(n + 1);
    for(int i = 1;i <= n;i++) {
        pSB[i] = pSB[i - 1] + sumaDeBloque[i - 1];
    }
    ll q;
    ll total = (n + 1) * n / 2;
    cin >> q;
    while(q--) {
        ll l, r;
        cin >> l >> r;
        ll bloquel, bloquer;
        ll lb = 0, rb = n + 1;
        while(lb + 1 < rb) {
            ll mb = (lb + rb) / 2;
            if(mb * (mb + 1) / 2 < total - l + 1) lb = mb;
            else rb = mb;
        }
        bloquel = n - lb - 1;
        lb = 0, rb = n + 1;
        while(lb + 1 < rb) {
            ll mb = (lb + rb) / 2;
            if(mb * (mb + 1) / 2 < total - r + 1) lb = mb;
            else rb = mb;
        }
        bloquer = n - lb - 1;
        l -= (n + 1) * n / 2 - (n + 1 - bloquel) * (n - bloquel) / 2;
        r -= (n + 1) * n / 2 - (n + 1 - bloquer) * (n - bloquer) / 2;
        ll ans = 0;
        // for(ll i = bloquel;i <= bloquer;i++) ans += sumaDeBloque[i];
        ans = pSB[bloquer + 1] - pSB[bloquel];

        ans -= (pFF[l - 1 + bloquel] - pFF[bloquel]);
        ans += pf[bloquel] * (l - 1);

        // for(ll i = 1;i < l;i++) {
        //     ans -= pf[i + bloquel] - pf[bloquel];
        // } 

        ans += (pf[bloquer] * (n - (r + bloquer)));
        ans -= (pFF[n] - pFF[r + bloquer]);

        // for(ll i = n;i > r + bloquer;i--) {
        //     // ans -= pf[i];
        //     // ans += pf[bloquer];
        // }
        cout << ans << '\n';
    }
    
}