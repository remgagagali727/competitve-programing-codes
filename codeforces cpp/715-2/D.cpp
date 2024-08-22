#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

void sol() {
    const int mod = 3;
    int n;
    cin >> n;
    int n2 = 2 * n;
    int n3 = 3 * n;
    vector<string> a(3);
    vector<vector<int>> b(3, vector<int>(2,n2 + 1));
    for(int i = 0; i < 3;i++) cin >> a[i];
    for(int i = 0; i < 3;i++) {
        
    }
    pair<ll, ll> p;
    p.first = 0;
    p.second = 0;
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 2;j++)
            if(b[i][j] < b[p.first][p.second]) {
                p.first = i;
                p.second = j;
            }
    cout << a[p.first];
    for(int i = b[p.first][p.second];i < n2;i++) cout << a[(p.first+1+p.second)][i];
    cout << nl;
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) sol();
}
