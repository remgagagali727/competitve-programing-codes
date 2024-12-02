#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        bool pos = false;
        for(int i = 1;i < n;i++) {
            if(s[i] == s[i - 1]) {
                pos = true;
                cout << s[i] << s[i] << '\n';
                break;
            }
        }
        if(!pos) {
            for(int i = 2;i < n;i++) {
                if(s[i] != s[i-1] && s[i - 1] != s[i - 2] && s[i - 2] != s[i]){
                    pos = true;
                    cout << s[i - 2] << s[i- 1] << s[i] << '\n';
                    break;
                }
            }
        }
        if(!pos) {
            cout << -1 << '\n';
        }
    }
}