
#include <bits/stdc++.h>

#define nl      "\n"
#define pb      push_back
#define ll      long long
#define all(a)  a.begin(),a.end()
#define lll     __int128_t

using namespace std;

const int MOD = 1000000007;

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

lll base[10][10] = {
        {0,1,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,1},
        {0,3,0,3,0,3,0,3,0,0}
};

int main() {

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    lll transmutador[32][10][10];
    for(int i = 0;i < 10;i++) for(int j = 0;j < 10;j++) transmutador[0][i][j] = base[i][j];
    for(int i = 1;i < 32;i++) {
        for(int n = 0;n < 10;n++){
            for(int m = 0;m < 10;m++){
                transmutador[i][n][m] = 0;
                for(int k = 0;k < 10;k++){
                    // for(int ayuda = 0;ayuda < transmutador[i-1][n][k];ayuda++) {
                    //     transmutador[i][n][m] += transmutador[i-1][k][m];
                    //     transmutador[i][n][m] %= MOD;
                    // }
                    transmutador[i][n][m] += transmutador[i-1][k][m] * transmutador[i-1][n][k];
                    transmutador[i][n][m] %= MOD;
                }
            }
        }
        // for(int n = 0;n < 10;n++){
        //     for(int m = 0;m < 10;m++){
        //         cout << transmutador[i][n][m] << " ";
        //     }
        //     cout << nl;
        // }
        // cout << "Fin transmutador ^ " << i << nl;
    }
    int querries;
    cin >> querries;
    while(querries--) {
        int quieroResultado;
        cin >> quieroResultado;
        quieroResultado /= 2;
        lll estado[10] = {1,1,1,4,4,7,16,19,37,67};
        // lll estado[10] = {0,0,0,0,0,0,0,0,0,1};
        lll resultado[10];
        int helper = 0;
        while(quieroResultado != 0) {
            // for(int i = 0;i < 10;i++) {
            //     cout << estado[i] << " ";
            // } 
            // cout << nl;
            if(quieroResultado & 1) {
                // cout << "se cambio de estado" << nl;
                for(int n = 0;n < 10;n++){
                    resultado[n] = 0;
                    for(int m = 0;m < 10;m++){
                        // for(int ayuda = 0;ayuda < estado[m];ayuda++) {
                        //     resultado[n] += transmutador[helper][n][m];
                        //     resultado[n] %= MOD;
                        // }
                        resultado[n] += estado[m]*transmutador[helper][n][m];
                        resultado[n] %= MOD;
                    }
                }
                for(int j = 0;j < 10;j++) {
                    estado[j] = resultado[j];
                }
            }
            quieroResultado = quieroResultado >> 1;
            // lll respuesta = 0;   
            // for(int i = 0;i < 10;i++) {
                // cout << estado[i] << " ";
                // respuesta+=estado[i];
            // } 
            // cout << nl << respuesta << nl;
            helper++;
        }
        // lll respuesta = 0;
        // for(int i = 1 ;i < 10;i++) {
        //     respuesta+=estado[i];
        //     respuesta%=MOD;
        // }
        // cout << respuesta << nl;
        cout << estado[0] << nl;
    }
}
