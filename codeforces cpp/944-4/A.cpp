#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

void sol() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<double> a(k+1);
    vector<double> b(k+1);
    a[0] = b[0] = 0;
    for(int i = 1;i < k+1;i++){
        cin >> a[i];
    }
    for(int i = 1;i < k+1;i++){
        cin >> b[i];
    }
    for(int i = 0;i < q;i++){
        int pos;
        cin >> pos;
        if(pos == 0) {
            cout << "0 ";
            continue;
        }
        int r = k+1, l = 0, m;
        while(l+1<r){
            m = (r+l) / 2;
            if(a[m] <= pos) {
                l = m;
            } else {
                r = m;
            }
        }
        
        cout << b[l] + extra << " ";
    }
    cout << nl;
    
}

int main() {
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
