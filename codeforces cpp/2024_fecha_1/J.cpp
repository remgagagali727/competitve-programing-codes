#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

#define inf     500

using namespace std;

// ll helper(int L, int R, string s, ll current) {
//     int aum = 1;
//     if(current == 0) return 0;
//     if(current < 0) return INT_MAX;
//     if(dp[L][R][current]) return dp[L][R][current];
//     if(R == L) {
//         if(current - 1 == 0) return 0;
//         else return INT_MAX;
//     }
//     if(R < L) {
//         return INT_MAX;
//     }
//     ll ans = min(helper(L+1,R,s,current),helper(L,R-1,s,current));
//     if(s[L] == s[R]) aum = 0;
//     ans = min(ans,helper(L+1,R-1,s,current-2)+aum);
//     dp[L][R][current] = ans;
//     return ans;
// }

ll dp[506][506][506];

int main() {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll start = k%2;
    dp[0][n-1][0] = 0;
    for(int l = n-1;l >= 0;l--) {
        for(int r = l;r < n;r++) {
            for(int curr = start; curr <= k;curr+=2){
                if (r - l + 1 < curr) {
                    dp[l][r][curr] = inf;
                    continue;
                }
                ll ans = inf;
                ll aum = 1;
                if(l != r) {
                    if(s[l] == s[r]) aum = 0;
                    if(l != n-1) ans = min(ans,dp[l+1][r][curr]);
                    if(r != 0) ans = min(ans,dp[l][r-1][curr]);     
                    if(curr - 2 >= 0) {
                        if(l < r) ans = min(ans,dp[l+1][r-1][curr-2]+aum);   
                        
                    }
                } else {
                    if(curr > 1) ans = inf;
                    else ans = 0;
                }
                dp[l][r][curr] = ans;
            }
        }
    }
    ll res = dp[0][n-1][k];
    cout << res << nl;
    return 0;
}
