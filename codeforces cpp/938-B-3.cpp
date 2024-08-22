#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

bool helpComp(char a, char b){
    if(a == '?' || b == '?') return true;
    return a == b;
}

void sol() {
    
    string ans = "yes";

    int n, c, d;

    cin >> n >> c >> d;

    vector<int> original(n*n);
    vector<int> compare(n*n);

    int first = INT_MAX;

    for(int i = 0; i < n * n;i++){
        cin >> original[i];
        first = min(original[i],first);
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            compare[i*n+j] = first + i*c + j*d; 
        }
    }

    sort(all(compare));
    sort(all(original));

    for(int i = 0;i < n*n;i++){
        if(original[i] != compare[i]) {
            ans = "NO";
            break;
        }
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
