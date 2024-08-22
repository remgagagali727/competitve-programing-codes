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
    string s;
    cin >> s;
    int n = s.size();
    int l = n/2;
    int ans = 0;
    for(int i = l; i > 0;i--){
        int count = 0;
        for(int j = i;j < n;j++) {
            if(helpComp(s[j],s[j-i])) {
                count++;
            } else {
                count = 0;
            }
            if(count == i) {
                ans = count * 2;
                break;
            }

        }
        if(ans != 0) break;
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
