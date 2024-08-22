#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

void sol() {
    ll ans = -1;
    int n;
    string s;
    cin >> n >> s;
    if(n == 2) cout << stoi(s);
    if(n == 3) {
        int a = (s[0] - 48) * 10 + s[1] - 48;
        int b = (s[1] - 48) * 10 + s[2] - 48;
        if(a == 1 || b == 1) cout << a * b << nl;
        else if(a == 0 || b == 0) cout << 0 << nl;
        else {
            if(a > b) {
                
            }
        }
    }
}

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
