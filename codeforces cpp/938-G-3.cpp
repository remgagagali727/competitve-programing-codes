#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

vector<vector<int>> divs;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> grid;
    vector<vector<bool>> visited;
    for(int i = 0;i < n;i++){
        vector<ll> helper(m);
        vector<bool> v(m);
        for(int j = 0;j < m;j++){
            cin >> helper[j];
        }
        visited.pb(v);
        grid.pb(helper);
    }

    int mcd = __gcd(grid[0][0],grid[n-1][m-1]);

    int ans = 1;

    for(int div : divs[mcd]) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++){
                bool posible = false;
                if(i == 0 && j == 0) posible = true;
                if(i != 0) posible |= visited[i-1][j];
                if(j != 0) posible |= visited[i][j-1];
                visited[i][j] = posible && (grid[i][j] % div == 0);
            }
        }
        if(visited[n-1][m-1]) ans = max(ans, div);
    }

    cout << ans << nl;

}

int main() {

    int max = 1000070;

    divs.resize(max);

    for(int i = 2;i < max;i++){
        for(int j = i;j < max;j+=i){
            divs[j].push_back(i);
        }
    }

    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
