#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n <= 4) {
            cout << "-1" << '\n';
        } else {
            for(int i = 1;i <= n;i+=2) {
                if(i == 5) continue;
                cout << i << ' ';
            }
            cout << "5 4 ";
            for(int i = 2;i <= n;i+=2) {
                if(i == 4) continue;
                cout << i << " ";
            }
            cout << '\n';
        }
    }
}