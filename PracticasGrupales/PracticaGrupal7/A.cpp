#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    iostream::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    ll acumL = 0, acumR = 0;
    int taml = 0, tamr = 0;
    int l = 0, r = n - 1;
    int ans = 0;
    while(l <= r) {
        if(acumL <= acumR) {
            acumL += a[l++];
            taml++;
        } else {
            acumR += a[r--];
            tamr++;
        }
        if(acumL == acumR) {
            ans += taml + tamr - 2;
            taml = tamr = 0;
        }
    }
    if(taml + tamr > 0) ans += taml + tamr - 1;
    cout << ans << '\n';
}