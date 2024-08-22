#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0;i < n;i++) {
        if(s[i]=='U') count++;
    }
    string ans = "YEs";
    if(count%2==0) ans = "NO";
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
