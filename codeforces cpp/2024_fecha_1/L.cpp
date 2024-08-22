// #include <bits/stdc++.h>

// #define nl      "\n"
// #define pb      push_back
// #define ll      long long
// #define all(a)  a.begin(),a.end()

// using namespace std;

// void sol(ll n) {
//     ll l, r;
//     ll s, p;
//     ll ways = 0;
//     ll helps = 0;
//     int inf = 1001;
//     cin >> s >> p;
//     int tam = n / p;
//     vector<int> multiplicados(tam);    
//     multiplicados[0] = p;
//     for(int j = 1;j < tam;j++){
//         multiplicados[j] = multiplicados[j-1] + p;
//     }
//     l = r = 0;
//     while(r < tam) {
//         helps += multiplicados[r];
//         if(helps >= s) {
//             if(tam - l - inf > 0) { 
//                 ways += (inf + l) - r;
//             } else {
//                 ways += tam - r;
//             }
//             if(l == r) ways-= 1;
//             helps -= multiplicados[l];
//             helps -= multiplicados[r];
//             l++;
//             r--;
//         }
//         r++;
//         if(r - l > inf) {
//             helps -= multiplicados[l];
//             l++;
//         }
//     }
//     cout << ways << nl;
// }   

// int main() {
//     ll n, q;
//     cin >> n >> q;
//     while(q--) sol(n);
//     return 0;
// }


#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()

using namespace std;

void sol(ll n) {
    ll s, p;
    cin >> s >> p;
    ll maxTam = 1001;
    ll longitud = n/p;
    ll tam = min(maxTam,longitud);
    ll formas = 0;
    ll gauss = p;
    for(int R = 2;R <= tam;R++){
        ll rp = R*p;
        gauss += rp;
        ll resta = s-gauss;
        int L;
        if(resta <= 0) {
            L = 0;
        } else {
            L = (s-gauss-1) / rp + 1;
        }
        ll formasNuevas = longitud-(R+L)+1;
        if(formasNuevas < 0) formasNuevas = 0;
        formas +=  formasNuevas;
    }
    cout << formas << nl;
}   

int main() {
    ll n, q;
    cin >> n >> q;
    while(q--) sol(n);
    return 0;
}
