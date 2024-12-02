#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return move(z);
}

vector<string> solve(vector<string>& s) {
    int n = s.size();
    vector<string> f((n + 1) / 2);
    for(int i = 1;i < n;i+=2) {
        string c = s[i] + "#" + s[i - 1];
        vector<int> z = z_function(c);
        int zn = z.size();
        int bop = 0;
        string r = "";
        for(int j = s[i].size() + 1;j < zn;j++) {
            if(z[j] + j == zn) {
                bop = z[j];
                break;
            }
        }
        for(int j = s[i].size() + 1;j < zn - bop;j++) {
            r += c[j];
        }
        r.append(s[i]);
        f[i / 2] = move(r);
    }
    if(n % 2) {
        f[f.size() - 1] = move(s[n - 1]);
    }
    return move(f);
}

int main() {
    int n;
    cin >> n;
    vector<string> start(n);
    for(int i = 0;i < n;i++) cin >> start[i];
    while(start.size() > 1) {
        start = solve(start);
    }
    cout << start[0] << '\n';
}