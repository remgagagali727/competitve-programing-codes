#include <bits/stdc++.h>

#define nl      "\n"

using namespace std;

/* int ans(int i, int *array, int n){
    if(i > n) return INT_MAX;
    if(i == n) return 0;
    return min(ans(i+1,array,n)+1,ans(i+array[i]+1,array,n));
} */

void sol(){
    int n;
    cin >> n;
    int *array = new int[n];
    int dp[n];
    for(int i = 0;i < n;i++){
        cin >> array[i];
    }

    dp[n-1] = 1;

    for(int i = n-2;i >= 0;i--){
        int took = array[i]+i+1;
        if(took==n) dp[i] = 0;
        else if(took>n) dp[i] = dp[i+1]+1;
        else dp[i] = min(dp[i+1]+1,dp[took]);
    }
    cout << dp[0] << nl;
    //cout << ans(0,array,n) << nl;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }    
    return 0;
}
