#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

struct sc{
    set<int> st;
    int lt;
    int rt;
};

sc dq(string &s, int l, int r) {
    if(l == r) {
        set<int> sss;
        int lt;
        if(s[l] == ')') lt = 0;
        else if(s[l] == '(') lt = 1;
        else if(s[l] == '+' || s[l] == '-' || s[l] == '/' || s[l] == '*') lt = 2;
        else lt = 3;
        sc x;
        x.st = move(sss);
        x.lt = x.rt = lt;
        return move(x);
    }
    int m = (l + r) / 2;
    sc left = dq(s, l, m);
    sc right = dq(s, m + 1, r);

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    set<int> st = dq(s, 0, s.size() - 1).st;
}