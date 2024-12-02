#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<string> palabras(n);
    for(int i = 0;i < n;i++) {
        cin >> palabras[i];
    }
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        vector<int> dif;
        vector<int> noex;
        vector<int> ex;
        int ans = 0;
        for(int i = 0;i < 5;i++) {
            if(s[i] == '!') dif.push_back(i);
            else if(s[i] == '*') ex.push_back(i);
            else if(s[i] == 'X') noex.push_back(i);
        }
        for(int i = 0;i < n;i++) {
            int cumple = 0;
            auto x = palabras[i];
            for(auto it : ex) {
                if(x[it] == palabras[0][it]) cumple++;
            }
            for(auto it : noex) {
                char no = x[it];
                bool existe = false;
                for(auto c : palabras[0]) {
                    existe |= no == c;
                }
                if(!existe) cumple++;
            }
            for(auto it : dif) {
                char si = x[it];
                bool existe = false;
                for(auto c : palabras[0]) {
                    existe |= si == c;
                }
                if(existe && palabras[0][it] != si) cumple++;
            }
            if(cumple == 5) ans++;
        }
        cout << ans << '\n';
    }
}