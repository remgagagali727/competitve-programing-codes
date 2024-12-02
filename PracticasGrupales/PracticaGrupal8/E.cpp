#include <bits/stdc++.h>

using namespace std;

bool dp[1000][1000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k; 
    int n, e;
    cin >> n >> k >> e;
    int left, right;
    left = e, right = n - (k + e);
    for(int i = 0;i <= left;i++) for(int j = 0;j <= right;j++) dp[i][j] = false;
    dp[left][right] = true;
    while(n--) {
        if(n == k) continue;
        for(int l = 0;l <= left;l++) {
            for(int r = 0;r <= right;r++) {
                if(dp[l][r]) {
                    if(l >= n) dp[l - n][r] = true;
                    if(r >= n) dp[l][r - n] = true;
                }
            }
        }
    }
    int ans = INT_MAX;
    for(int l = 0;l <= left;l++) {
        for(int r = 0;r <= right;r++) {
            if(dp[l][r]) ans = min(ans, l + r);
        }
    }
    cout << ans << '\n';
}