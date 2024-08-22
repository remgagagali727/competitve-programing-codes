#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()
#define flip(a,b)       ll t = a; a = b; b = t

using namespace std;

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1;i <= n;i++){        
        ans += i * (i+1) / 2;
    }

    for(int i = 1; i < n;i++){
        if(i  != n) {
            int a, b;
            cin >> a >> b;  

            int t;

            if(a > b) {
                t = a;
                a = b;
                b = t;
            }
            b = n - b + 1;
            t = a * b;
            ans-= t;
        }
        cout << ans << nl;
    }
    cout << ans << nl;
}
