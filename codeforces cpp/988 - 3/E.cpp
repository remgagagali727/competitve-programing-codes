#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll query(ll r) {
    cout << "? 1 " << r << '\n';
    cout.flush();
    cin >> r;
    return r;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int qr;
        int r = 2;
        bool posible = false;
        ll last = 0;
        string ans = "";
        while(r <= n) {
            if(last != (qr = query(r))) {
                if(last == 0) {
                    int i;
                    for(i = 1;i <= r - qr - 1;i++) {
                        ans.append("1");
                    }
                    for(i = 1;i <= qr;i++) ans.append("0");
                    posible = true;
                    ans.append("1");
                } else {
                    ans.append("1");
                }
                last = qr;
            } else {
                if(last) {
                    ans.append("0");
                }
            }
            r++;
        }
        if(!posible) {
            cout << "! IMPOSSIBLE" << '\n';
        } else {
            cout << "! " << ans << '\n';
        }
        cout.flush();
    }
}