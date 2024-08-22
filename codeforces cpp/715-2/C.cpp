#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

// ll helper(int L, int R, vector<int> a){
//     if(L == R) return 0;
//     if(dp[L][R]) return dp[L][R];
//     ll ans = min(helper(L+1,R,a),helper(L,R-1,a));
//     ans += a[R] - a[L];
//     dp[L][R] = ans;
//     return ans;
// }

int main() {
    ll n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<vector<ll>> dp;
    vector<ll> h(n, 0);
    dp.resize(n, h);

    dp[0][n-1] = a[n-1] - a[0];

    ll ans = 0;

    for(int L = 0;L < n;L++){
        for(int R = n-1;R >= L;R--){
            ans = LONG_LONG_MAX;
            if(L == 0 && R == n-1) continue;
            if(L != 0) ans = dp[L-1][R];
            if(R != n-1) ans = min(dp[L][R+1],ans);
            ans += a[R] - a[L];
            dp[L][R] = ans;
        }
    }

    for(int i = 0;i < n;i++) {
        ans = min(ans,dp[i][i]);
    }

    cout << ans << nl;

    return 0;
}
