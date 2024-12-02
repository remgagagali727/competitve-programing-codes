#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct nodo{
    ll MP;
    ll MS;
    ll ST;
    ll MSA;
};

nodo dq(int l, int r, vector<ll>& a) {
    nodo toReturn;
    if(l == r) {
        toReturn.MP = toReturn.MS = toReturn.MSA = toReturn.ST = a[l];
    } else {
        int m = (l + r) / 2;
        nodo left, right;
        left = dq(l, m, a);
        right = dq(m + 1, r, a);
        toReturn.ST = left.ST + right.ST;
        toReturn.MP = max(left.MP, left.ST + right.MP);
        toReturn.MS = max(right.MS, right.ST + left.MS);
        toReturn.MSA = max(max(left.MSA, right.MSA), right.MP + left.MS);
    }
    return toReturn;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    cout << dq(0, n - 1, a).MSA << '\n';
}