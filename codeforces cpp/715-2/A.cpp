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

void sol() {
    const int mod = 2;
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    int change = 0;
    for(int i = 0;i < n;i++) {
        if(a[i] % mod == 0) {
            ll t = a[change];
            a[change++] = a[i];
            a[i] = t;
        }
    }
    for(int i = 0;i < n;i++) cout << a[i] << " ";
    cout << nl;
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) sol();
}
