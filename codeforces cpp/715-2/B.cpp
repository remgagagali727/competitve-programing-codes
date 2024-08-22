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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "YES";
    int times = n / 3;
    int x = 0;
    int y = 0;
    for(int i = 0;i < n;i++) {
        if(s[i] == 'T')
            if(times-- > 0) {
                x++;
            } else {
                y--;
            }
        else {
            x--;
            y++;
        }
        if(x < 0) {
            ans = "NO";
            break;
        }
        if(y < 0) {
            ans = "NO";
            break;
        }
    }
    if(x | y) ans = "NO";
    cout << ans << nl;
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) sol();
}
