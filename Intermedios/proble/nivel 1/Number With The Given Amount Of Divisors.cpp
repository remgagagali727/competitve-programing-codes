#include <bits/stdc++.h>

using namespace std;

using ll = long long;

long long expBin(ll base, ll exp) {
    if(exp == 0) return 1;
    ll d = expBin(base, exp / 2);
    d *= d;
    if(exp & 1) d *= base;
    return d;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    if(n == 1) {
        cout << 1 << '\n';
    } else {
        vector<int> crib(n + 1);
        vector<int> primos;
        vector<int> mp(n + 1);
        crib[1] = 1;
        int k = 1;
        for(int i = 2;i <= n;i++) {
            if(crib[i]) continue;
            mp[i] = k++;
            primos.push_back(i);
            crib[i] = i;
            for(long long j = i * i;j <= n;j+=i) crib[j] = i;
        }
        // ll xd = expBin(2, 10) * 3;
        // cout << xd << " ";
        // ll sq = sqrt(xd);
        // ll ans = 0;
        // if(xd % sq == 0) ans++;
        // for(ll j = 1;j < sq;j++) {
        //     if(xd % j == 0) ans += 2;
        // }
        // cout << ans << '\n';
        vector<int> dupes;
        while(n != 1) {
            dupes.push_back(mp[crib[n]]);
            n /= crib[n];
        }
        sort(dupes.rbegin(), dupes.rend());
        long long ans = 1;
        for(int i = 0;i < dupes.size();i++) {
            ans *= expBin(primos[i], primos[dupes[i] - 1] - 1);
        }
        cout << ans << '\n';
    }
}