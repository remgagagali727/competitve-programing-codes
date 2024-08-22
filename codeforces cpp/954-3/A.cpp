#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

void sol() {
    vector<int> a(3);
    for(int i = 0;i < 3;i++) cin >> a[i];
    sort(all(a));
    int res = a[1] + a[2] - a[0] - a[0];
    for(int i = a[0];i <= a[2];i++) {
        int t = abs(a[0] - i) + abs(a[1] - i) + abs(a[2] - i);
        if(res > t) {
            res = t;
        }
    }
    cout << res << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
    }
