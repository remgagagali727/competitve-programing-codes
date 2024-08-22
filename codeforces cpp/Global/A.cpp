#include <bits/stdc++.h>

#define f(i,n)  for(int i = 0;i < n;i++)
#define nl      "\n"
#define pb      push_back
#define ll      long long
#define ull     unsigned long long
#define lll     __int128_t
#define all(a)  a.begin(),a.end()

using namespace std;

void sol() {
    ll ans = 0;
    ll x, y, z;
    ll k;
    cin >> x >> y >> z;
    cin >> k;
    for(int i = 1;i <= x;i++){
        ll xk = k;
        if(xk % i == 0) {
            xk /= i;
            for(int j = 1;j <= y;j++){
                ll yk = xk;
                if(yk % j == 0){
                    yk /= j;
                    for(int ii = 1;ii <= z;ii++){
                        ll zk = yk;
                        if(zk % ii == 0){
                            zk /= ii;
                            if(zk == 1) {
                                ll total = (x - i + 1) * (y - j + 1) * (z - ii + 1);
                                ans = max(ans,total);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << nl;
}


int main() {
    int t = 1;
    cin >> t;
    while(t--) sol();
}
