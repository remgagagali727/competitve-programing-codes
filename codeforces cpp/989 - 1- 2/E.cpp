#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

bool generate(int n, int k, vector<vector<int>>& per, int i = 0) {
    bool t;
    vector<int> base(n), rbase(n);
    for(int i = 0;i < n;i++) {
        base[i] = i + 1;
    }
    for(int i = 0;i < n;i++) {
        rbase[i] = n - base[i] + 1;
    }
    for(;i < k;i += 2) {
        bool d = true;
        while(d) {
            d = false;
            for(int j = 0;j < i;j++) {
                if(per[j] == base || per[j] == rbase) {
                    d = true;
                    t = next_permutation(base.begin(), base.end());
                    if(!t) return t;
                    for(int k = 0;k < n;k++) {
                        rbase[k] = n - base[k] + 1;
                    }
                    break;
                }
            }
        }
        per[i] = base;
        per[i + 1] = rbase;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for(int kkk = 1;kkk <= t;kkk++) {
        int n, k;
        cin >> n >> k;
        if(n == 1 && k == 1) {
            cout << "YES" << '\n';
            cout << "1" << '\n';
            continue;
        }
        if(n == 1) {
            cout << "NO" << '\n';
            continue;
        }
        if(k == 1 || ((n % 2 == 0) && (k % 2 == 1))) {
            cout << "NO" << '\n';
        } else {
            bool pos;
            vector<vector<int>> per(k, vector<int>(n));
            if(k % 2 == 0) {
                pos = generate(n, k, per);
            } else {
                int help = n;
                int h2 = n / 2 + 1;
                for(int i = 0;i < n;i++) {
                    per[0][i] = help;
                    help -= 2;
                    per[1][i] = h2;
                    h2++;
                    if(h2 > n) h2 = 1;
                    if(help < 0) help += n;
                    per[2][i] = i + 1;
                }
                pos = generate(n, k, per, 3);
            }
            if(pos) {
                cout << "yES" << '\n';
                for(auto x : per) {
                    for(auto y : x) cout << y << ' ';
                    cout << '\n';
                }
            } else {
                cout << "NO" << '\n';
            }
        }
    }
}

