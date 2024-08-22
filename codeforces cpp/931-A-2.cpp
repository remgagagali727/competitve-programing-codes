#include <bits/stdc++.h>

#define nl          "\n"
#define pb          push_back
#define ll          long long

using namespace std;

ll trueVal(ll a, ll b){
    a -= b;
    if(a < 0) return -a;
    return a;
}

void sol(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i = 0;i < n;i++) cin >> array[i];
    sort(array.begin(),array.end());
    ll ans;
    ans = trueVal(array[0],array[n-1]) +
        trueVal(array[1],array[n-1]) +
        trueVal(array[0],array[n-2]) +
        trueVal(array[1],array[n-2]);
    cout << ans << nl;
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
