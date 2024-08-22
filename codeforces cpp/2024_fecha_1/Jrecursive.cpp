#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

#define inf     500

using namespace std;

ll dp[506][506][506];

ll helper(int L, int R, string s, ll current) {
    int aum = 1;
    if(current == 0) return 0;
    if(current < 0) return INT_MAX;
    if(dp[L][R][current]) return dp[L][R][current];
    if(R == L) {
        if(current - 1 == 0) return 0;
        else return INT_MAX;
    }
    if(R < L) {
        return INT_MAX;
    }
    ll ans = min(helper(L+1,R,s,current),helper(L,R-1,s,current));
    if(s[L] == s[R]) aum = 0;
    ans = min(ans,helper(L+1,R-1,s,current-2)+aum);
    dp[L][R][current] = ans;
    return ans;
}

int main() {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    cout << helper(0,n-1,s,k) << nl;
    return 0;
}
