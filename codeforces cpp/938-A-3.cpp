#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long

using namespace std;

bool helpComp(char a, char b){
    if(a == '?' || b == '?') return true;
    return a == b;
}

void sol() {
    
    int n, a, b;
    cin >> n >> a >> b;
    int ans;
    if(a * 2 < b){
        ans = n * a;
    } else {
        ans = n / 2 * b + (n%2==1?a:0); 
    }

    cout << ans << nl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
